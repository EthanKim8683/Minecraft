#if !defined(CHUNK_C)
#define CHUNK_C

#include "Chunk.hpp"
#include "ChunkIteratorX.hpp"
#include "ChunkIteratorY.hpp"
#include "ChunkIteratorZ.hpp"

Chunk::Chunk(const Ivec2 _position): position(_position) {}

Chunk::IteratorX Chunk::borderPosXBegin() { return IteratorX(&blocks[W - 1][0][0], 0, 0); }
Chunk::IteratorY Chunk::borderPosYBegin() { return IteratorY(&blocks[0][H - 1][0], 0, 0); }
Chunk::IteratorZ Chunk::borderPosZBegin() { return IteratorZ(&blocks[0][0][L - 1], 0, 0); }
Chunk::IteratorX Chunk::borderNegXBegin() { return IteratorX(&blocks[0][0][0],     0, 0); }
Chunk::IteratorY Chunk::borderNegYBegin() { return IteratorY(&blocks[0][0][0],     0, 0); }
Chunk::IteratorZ Chunk::borderNegZBegin() { return IteratorZ(&blocks[0][0][0],     0, 0); }

Chunk::IteratorX Chunk::borderPosXEnd() { return IteratorX(&blocks[W - 1][H][0], H, 0); }
Chunk::IteratorY Chunk::borderPosYEnd() { return IteratorY(&blocks[W][H - 1][0], W, 0); }
Chunk::IteratorZ Chunk::borderPosZEnd() { return IteratorZ(&blocks[W][0][L - 1], W, 0); }
Chunk::IteratorX Chunk::borderNegXEnd() { return IteratorX(&blocks[0][H][0],     H, 0); }
Chunk::IteratorY Chunk::borderNegYEnd() { return IteratorY(&blocks[W][0][0],     W, 0); }
Chunk::IteratorZ Chunk::borderNegZEnd() { return IteratorZ(&blocks[W][0][0],     W, 0); }

bool Chunk::isBound(const Ivec3 p) {
  return p.x >= 0 && p.x < W && p.y >= 0 && p.y < H && p.z >= 0 && p.z < L;
}

Block Chunk::getBlock(const Ivec3 p) {
  if (!isBound(p))
    return 0;
  return blocks[p.x][p.y][p.z];
}

void Chunk::setBlockVisLocal(const Ivec3 p) {
  if (!isBound(p))
    return;
  if (blocks[p.x][p.y][p.z] == 0)
    return;
  blocks[p.x][p.y][p.z].setVisAll(
    isBound(p + Ivec3(1, 0, 0)) && !getBlock(p + Ivec3(1, 0, 0)).isSolid(),
    isBound(p + Ivec3(0, 1, 0)) && !getBlock(p + Ivec3(0, 1, 0)).isSolid(),
    isBound(p + Ivec3(0, 0, 1)) && !getBlock(p + Ivec3(0, 0, 1)).isSolid(),
    isBound(p - Ivec3(1, 0, 0)) && !getBlock(p - Ivec3(1, 0, 0)).isSolid(),
    isBound(p - Ivec3(0, 1, 0)) && !getBlock(p - Ivec3(0, 1, 0)).isSolid(),
    isBound(p - Ivec3(0, 0, 1)) && !getBlock(p - Ivec3(0, 0, 1)).isSolid()
  );
}

void Chunk::setVisLocal() {
  for (int x = 0; x < W; x++) for (int y = 0; y < H; y++) for (int z = 0; z < L; z++)
    setBlockVisLocal(Ivec3(x, y, z));
}

void Chunk::setVisBorderPosX(IteratorX itB) {
  for (Chunk::IteratorX itA = borderPosXBegin(); itA != borderPosXEnd(); itA++, itB++) {
    itA->setVisPosX(itB->isSolid());
    itB->setVisNegX(itA->isSolid());
  }
}

void Chunk::setVisBorderPosZ(IteratorZ itB) {
  for (Chunk::IteratorZ itA = borderPosZBegin(); itA != borderPosZEnd(); itA++, itB++) {
    itA->setVisPosZ(itB->isSolid());
    itB->setVisNegZ(itA->isSolid());
  }
}

void Chunk::setVisBorderNegX(IteratorX itB) {
  for (Chunk::IteratorX itA = borderNegXBegin(); itA != borderNegXEnd(); itA++, itB++) {
    itA->setVisNegX(itB->isSolid());
    itB->setVisPosX(itA->isSolid());
  }
}

void Chunk::setVisBorderNegZ(IteratorZ itB) {
  for (Chunk::IteratorZ itA = borderNegZBegin(); itA != borderNegZEnd(); itA++, itB++) {
    itA->setVisNegZ(itB->isSolid());
    itB->setVisPosZ(itA->isSolid());
  }
}

void Chunk::genBlocks() {
  for (int i = 0; i < W; i++) for (int j = 0; j < L; j++) {
    const int h = Noise::snoise(Vec2((position.x * W + i) * 0.01, (position.y * L + j) * 0.01)) * 20+50;
    for (int k = 0; k < h; k++)
      blocks[i][k][j] = 1;
  }
}

#endif // !defined(CHUNK_C)