#include <iostream>

#include "Block.hpp"
#include "BlockMesh.hpp"
#include "BlockType.hpp"
#include "Chunk.hpp"
#include "ChunkIteratorX.hpp"
#include "ChunkIteratorY.hpp"
#include "ChunkIteratorZ.hpp"
#include "ChunkMesh.hpp"
#include "Env.hpp"
#include "Hash.hpp"
#include "Helper.hpp"
#include "Ivec2.hpp"
#include "Ivec3.hpp"
#include "Ivec4.hpp"
#include "Mat2.hpp"
#include "Mat3.hpp"
#include "Mat4.hpp"
#include "Noise.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "UserData.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"
#include "World.hpp"
#include "WorldMesh.hpp"

bool keyPressed[256 + 4];

void initUserData(UserData* userData) {
  int width, height;

  emscripten_get_canvas_element_size("canvas", &width, &height);

  userData->width = width;
  userData->height = height;
  userData->aspect = (float) width / height;
  userData->fov = 1.570796f;
  userData->near = 1.0f;
  userData->far = 200.0f;
}

void initWebGL(UserData* userData) {
  EmscriptenWebGLContextAttributes attrs{};
  attrs.depth = true;
  attrs.antialias = true;
  const int ctx = emscripten_webgl_create_context("canvas", &attrs);
  if (ctx <= 0) {
    printf("WebGL context could not be created!\n");
    exit(-1);
  }
  emscripten_webgl_make_context_current(ctx);

  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
  
  glCullFace(GL_BACK);
  glDepthFunc(GL_LEQUAL);

  glEnable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);

  userData->ctx = ctx;
}

void initEnv(UserData* userData) {
  Env* env = new Env();

  env->initChunkProgram();

  userData->env = env;
}

void initWorld(UserData* userData) {
  World* world = new World();
  WorldMesh* worldMesh = new WorldMesh(world);

  userData->world = world;
  userData->worldMesh = worldMesh;
}

void handleKeys(float delta, UserData* userData) {
  World* world = userData->world;

  if (keyPressed['w'])
    world->moveForward(delta);
  if (keyPressed['a'])
    world->moveLeftward(delta);
  if (keyPressed['s'])
    world->moveBackward(delta);
  if (keyPressed['d'])
    world->moveRightward(delta);
  if (keyPressed[' '])
    world->moveUpward(delta);
  if (keyPressed[256 + 1])
    world->moveDownward(delta);
}

EM_BOOL mousemoveCallback(int type, const EmscriptenMouseEvent* event, void* _userData) {
  UserData* userData = (UserData*) _userData;
  World* world = userData->world;

  world->rotate(Vec2((float) -event->movementY / 100.0f, (float) -event->movementX / 100.0f));

  return EM_TRUE;
}

EM_BOOL mousedownCallback(int type, const EmscriptenMouseEvent* event, void* _userData) {
  UserData* userData = (UserData*) _userData;

  emscripten_request_pointerlock("canvas", false);

  return EM_TRUE;
}

EM_BOOL resizeCallback(int type, const EmscriptenUiEvent* event, void* _userData) {
  UserData* userData = (UserData*) _userData;
  int& width = userData->width;
  int& height = userData->height;
  float& aspect = userData->aspect;

  width = event->windowInnerWidth;
  height = event->windowInnerHeight;
  aspect = (float) width / height;

  glViewport(0, 0, width, height);

  return EM_TRUE;
}

EM_BOOL keydownCallback(int type, const EmscriptenKeyboardEvent* event, void* _userData) {
  UserData* userData = (UserData*) _userData;

  char key = event->key[0];
  bool ctrlKey = event->ctrlKey;
  bool shiftKey = event->shiftKey;
  bool altKey = event->altKey;
  bool metaKey = event->metaKey;

  keyPressed[key] = true;
  keyPressed[256 + 0] = ctrlKey;
  keyPressed[256 + 1] = shiftKey;
  keyPressed[256 + 2] = altKey;
  keyPressed[256 + 3] = metaKey;

  return EM_TRUE;
}

EM_BOOL keyupCallback(int type, const EmscriptenKeyboardEvent* event, void* _userData) {
  UserData* userData = (UserData*) _userData;

  char key = event->key[0];
  bool ctrlKey = event->ctrlKey;
  bool shiftKey = event->shiftKey;
  bool altKey = event->altKey;
  bool metaKey = event->metaKey;

  keyPressed[key] = false;
  keyPressed[256 + 0] = ctrlKey;
  keyPressed[256 + 1] = shiftKey;
  keyPressed[256 + 2] = altKey;
  keyPressed[256 + 3] = metaKey;

  return EM_TRUE;
}

EM_BOOL draw(double time, void* _userData) {
  UserData* userData = (UserData*) _userData;
  Env* env = userData->env;
  float fov = userData->fov;
  float aspect = userData->aspect;
  float near = userData->near;
  float far = userData->far;
  World* world = userData->world;
  WorldMesh* worldMesh = userData->worldMesh;

  Mat4 view = world->getViewMatrix();
  Mat4 projection = Mat4::getProjectionMatrix(fov, aspect, near, far);
  env->updateMatrix(projection * view);

  handleKeys(1, userData);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      worldMesh->getChunkMesh(Ivec2(i, j))->draw();
    }
  }

  return EM_TRUE;
}

int main(void) {
  UserData* userData = new UserData();
  initUserData(userData);
  initWebGL(userData);
  initEnv(userData);
  initWorld(userData);

  World* world = userData->world;
  WorldMesh* worldMesh = userData->worldMesh;
  Env* env = userData->env;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      Chunk* chunk = world->createChunk(Ivec2(i, j));

      chunk->genBlocks();
      chunk->setVisLocal();
      world->setChunkVisGlobal(Ivec2(i, j));
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ChunkMesh* chunkMesh = worldMesh->createChunkMesh(Ivec2(i, j));

      chunkMesh->updateChunkMesh();
      chunkMesh->updateVao(env);
    }
  }
  
  emscripten_set_mousemove_callback("canvas", userData, false, mousemoveCallback);
  emscripten_set_mousedown_callback("canvas", userData, false, mousedownCallback);
  emscripten_set_resize_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, userData, false, resizeCallback);
  emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, userData, false, keydownCallback);
  emscripten_set_keyup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, userData, false, keyupCallback);
  emscripten_request_animation_frame_loop(draw, userData);
  return 0;
}