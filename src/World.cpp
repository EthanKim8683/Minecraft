#if !defined(WORLD_C)
#define WORLD_C

#include "World.hpp"

Chunk* World::createChunk(const Ivec2& p) {
  Chunk* chunk = new Chunk(p);
  
  chunks.insert({Hash::mortonEncode(p), chunk});
  return chunk;
}

Chunk* World::getChunk(const Ivec2& p) {
  return chunks[Hash::mortonEncode(p)];
}

Chunk* World::getOrCreateChunk(const Ivec2& p) {
  if (isChunkCreated(p))
    return getChunk(p);
  
  return createChunk(p);
}

bool World::isChunkCreated(const Ivec2& p) {
  return chunks.find(Hash::mortonEncode(p)) != chunks.end();
}

void World::setChunkVisGlobal(const Ivec2& p) {
  if (!isChunkCreated(p))
    return;
  
  Chunk* chunk = getChunk(p);
  if (isChunkCreated(p + Ivec2(1, 0)))
    chunk->setVisBorderPosX(getChunk(p + Ivec2(1, 0))->borderNegXBegin());
  if (isChunkCreated(p + Ivec2(0, 1)))
    chunk->setVisBorderPosZ(getChunk(p + Ivec2(0, 1))->borderNegZBegin());
  if (isChunkCreated(p - Ivec2(1, 0)))
    chunk->setVisBorderNegX(getChunk(p - Ivec2(1, 0))->borderPosXBegin());
  if (isChunkCreated(p - Ivec2(0, 1)))
    chunk->setVisBorderNegZ(getChunk(p - Ivec2(0, 1))->borderPosZBegin());
}

void World::rotate(const Vec2& p) {
  rotation += p;
  rotation.x = std::clamp(rotation.x, -1.570796f, 1.570796f);
}

void World::moveForward(float distance) {
  float c = cos(rotation.y);
  float s = sin(rotation.y);

  translation.x -= s * distance;
  translation.z -= c * distance;
}

void World::moveBackward(float distance) {
  float c = cos(rotation.y);
  float s = sin(rotation.y);

  translation.x += s * distance;
  translation.z += c * distance;
}

void World::moveLeftward(float distance) {
  float c = cos(rotation.y);
  float s = sin(rotation.y);

  translation.x -= c * distance;
  translation.z += s * distance;
}

void World::moveRightward(float distance) {
  float c = cos(rotation.y);
  float s = sin(rotation.y);

  translation.x += c * distance;
  translation.z -= s * distance;
}

void World::moveUpward(float distance) {
  translation.y += distance;
}

void World::moveDownward(float distance) {
  translation.y -= distance;
}

Mat4 World::getViewMatrix() {
  return Mat4::getRotationMatrix(rotation) * Mat4::getTranslationMatrix(-translation);
}

#endif // !defined(WORLD_C)