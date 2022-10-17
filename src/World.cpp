#if !defined(WORLD_C)
#define WORLD_C

#include "World.hpp"

Chunk* World::createChunk(Ivec2 p) {
  Chunk* chunk = new Chunk(p);
  
  chunks.insert({Hash::mortonEncode(p), chunk});
  return chunk;
}

Chunk* World::getChunk(Ivec2 p) {
  return chunks[Hash::mortonEncode(p)];
}

Chunk* World::getOrCreateChunk(Ivec2 p) {
  if (isChunkCreated(p))
    return getChunk(p);
  
  return createChunk(p);
}

bool World::isChunkCreated(Ivec2 p) {
  return chunks.find(Hash::mortonEncode(p)) != chunks.end();
}

void World::setChunkVisibilityGlobal(Ivec2 p) {
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

#endif // !defined(WORLD_C)