#if !defined(BLOCKMESH_C)
#define BLOCKMESH_C

#include "BlockMesh.hpp"

BlockMesh::BlockMesh(Block* _block, ChunkMesh* _chunkMesh, Ivec3 _position): block(_block), chunkMesh(_chunkMesh), position(_position) {}

void BlockMesh::addSide(int i) {
  if (visible[i])
    return;
  visible[i] = true;
  auto& side = BlockType::types[block->getType()].getSide(i);
  indices[i].resize(side.size());
  for (int j = 0; j < side.size(); j++)
    chunkMesh->addTriangle(side[j].translate(position), &indices[i][j]);
}

void BlockMesh::removeSide(int i) {
  if (!visible[i])
    return;
  visible[i] = false;
  for (auto j : indices[i])
    chunkMesh->removeTriangle(j);
}

void BlockMesh::setSide(int i, bool state) {
  if (state)
    addSide(i);
  else
    removeSide(i);
}

void BlockMesh::update() {
  if (block->getType() != cacheType)
    for (int i = 0; i < 7; i++)
      removeSide(i);
  setSide(0, block->getVisPosX());
  setSide(1, block->getVisPosY());
  setSide(2, block->getVisPosZ());
  setSide(3, block->getVisNegX());
  setSide(4, block->getVisNegY());
  setSide(5, block->getVisNegZ());
  setSide(6, block->getVis() != 0);
  cacheType = block->getType();
}

#endif // !defined(BLOCKMESH_C)