#include <iostream>

#include "Block.hpp"
#include "BlockMesh.hpp"
#include "BlockType.hpp"
#include "Chunk.hpp"
#include "ChunkIteratorX.hpp"
#include "ChunkIteratorY.hpp"
#include "ChunkIteratorZ.hpp"
#include "ChunkMesh.hpp"
#include "Hash.hpp"
#include "Helper.hpp"
#include "Ivec2.hpp"
#include "Ivec3.hpp"
#include "Ivec4.hpp"
#include "Noise.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"
#include "World.hpp"
#include "WorldMesh.hpp"

int main(void) {
  EmscriptenWebGLContextAttributes attrs = {0};
  attrs.antialias = true;
  const int ctx = emscripten_webgl_create_context("canvas", &attrs);
  if (!ctx) {
    printf("WebGL context could not be created!\n");
    exit(1);
  }
  emscripten_webgl_make_context_current(ctx);
  glClearColor(0, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  World* world = new World();
  world->createChunk(Ivec2(0, 0));
  if (world->isChunkCreated(Ivec2(0, 0))) {
    Chunk* chunk = world->getChunk(Ivec2(0, 0));
    chunk->genBlocks();
    chunk->setVisLocal();
    ChunkMesh* chunkMesh = new ChunkMesh(*chunk);
    chunkMesh->init();
  }
  return 0;
}