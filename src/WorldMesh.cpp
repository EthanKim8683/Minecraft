#if !defined(WORLDMESH_C)
#define WORLDMESH_C

#include "WorldMesh.hpp"

int WorldMesh::ctx = -1;

WorldMesh::WorldMesh(World* _world): world(_world) {}

void WorldMesh::init(int _ctx) {
  ctx = _ctx;
}

ChunkMesh* WorldMesh::createChunkMesh(Ivec2 p) {
  ChunkMesh* chunkMesh = new ChunkMesh(world->getOrCreateChunk(p));
  
  chunkMeshes.insert({Hash::mortonEncode(p), chunkMesh});
  return chunkMesh;
}

ChunkMesh* WorldMesh::getChunkMesh(Ivec2 p) {
  return chunkMeshes[Hash::mortonEncode(p)];
}

ChunkMesh* WorldMesh::getOrCreateChunkMesh(Ivec2 p) {
  if (isChunkMeshCreated(p))
    return getChunkMesh(p);
  
  return createChunkMesh(p);
}

bool WorldMesh::isChunkMeshCreated(Ivec2 p) {
  return chunkMeshes.find(Hash::mortonEncode(p)) != chunkMeshes.end();
}

#endif // !defined(WORLDMESH_C)