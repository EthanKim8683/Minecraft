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

void World::translate(const Vec3& p) {
  translation += p;
}

Mat4 World::getMatrix() {
  return Mat4::rotation(rotation) * Mat4::translation(translation);
}

#endif // !defined(WORLD_C)