#if !defined(WORLDMESH_C)
#define WORLDMESH_C

#include "WorldMesh.hpp"

WorldMesh::WorldMesh(World* _world): world(_world) {}

ChunkMesh* WorldMesh::createChunkMesh(const Ivec2& p) {
  ChunkMesh* chunkMesh = new ChunkMesh(world->getOrCreateChunk(p));
  
  chunkMeshes.insert({Hash::mortonEncode(p), chunkMesh});
  return chunkMesh;
}

ChunkMesh* WorldMesh::getChunkMesh(const Ivec2& p) {
  return chunkMeshes[Hash::mortonEncode(p)];
}

ChunkMesh* WorldMesh::getOrCreateChunkMesh(const Ivec2& p) {
  if (isChunkMeshCreated(p))
    return getChunkMesh(p);
  
  return createChunkMesh(p);
}

bool WorldMesh::isChunkMeshCreated(const Ivec2& p) {
  return chunkMeshes.find(Hash::mortonEncode(p)) != chunkMeshes.end();
}

void WorldMesh::draw() {
  
}

#endif // !defined(WORLDMESH_C)