#if !defined(CHUNKMESH_C)
#define CHUNKMESH_C

#include "ChunkMesh.hpp"

ChunkMesh::ChunkMesh(Chunk& chunk) {
  for (int x = 0; x < W; x++) for (int y = 0; y < H; y++) for (int z = 0; z < L; z++)
    blockMeshes[x][y][z] = new BlockMesh(&chunk.blocks[x][y][z], this, Ivec3(x, y, z));
}

void ChunkMesh::init() {
  for (int x = 0; x < W; x++) for (int y = 0; y < H; y++) for (int z = 0; z < L; z++)
    blockMeshes[x][y][z]->update();
}

void ChunkMesh::update(const Ivec3 p) {
  if (!Chunk::isBound(p))
    return;
  blockMeshes[p.x][p.y][p.z]->update();
}

void ChunkMesh::addPosition(const Vec3 position) {
  positions.push_back(position.x);
  positions.push_back(position.y);
  positions.push_back(position.z);
}

void ChunkMesh::addTexcoord(const Vec2 texcoord) {
  texcoords.push_back(texcoord.x);
  texcoords.push_back(texcoord.y);
}

void ChunkMesh::addPoint(const Point& point) {
  addPosition(point.positions);
  addTexcoord(point.texcoords);
}

void ChunkMesh::addTriangle(const Triangle& triangle, int* index) {
  *index = indices.size();
  indices.push_back(index);
  addPoint(triangle.points[0]);
  addPoint(triangle.points[1]);
  addPoint(triangle.points[2]);
}

void ChunkMesh::removePosition(int i) {
  for (int j = 3 - 1; j >= 0; j--) {
    std::swap(positions[i + j], positions.back());
    positions.pop_back();
  }
}

void ChunkMesh::removeTexcoord(int i) {
  for (int j = 2 - 1; j >= 0; j--) {
    std::swap(texcoords[i + j], texcoords.back());
    texcoords.pop_back();
  }
}

void ChunkMesh::removePoint(int i) {
  removePosition(i * 3);
  removeTexcoord(i * 2);
}

void ChunkMesh::removeTriangle(int i) {
  *indices.back() = i;
  indices.pop_back();
  removePoint(i * 3 + 2);
  removePoint(i * 3 + 1);
  removePoint(i * 3 + 0);
}

#endif // !defined(CHUNKMESH_C)