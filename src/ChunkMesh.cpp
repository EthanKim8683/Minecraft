#if !defined(CHUNKMESH_C)
#define CHUNKMESH_C

#include "ChunkMesh.hpp"

int ChunkMesh::ctx = -1;
GLuint ChunkMesh::program = -1;
GLuint ChunkMesh::positionLocation = -1;
GLuint ChunkMesh::texcoordLocation = -1;

ChunkMesh::ChunkMesh(Chunk* chunk) {
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &positionBuffer);
  glGenBuffers(1, &texcoordBuffer);

  for (int x = 0; x < W; x++) for (int y = 0; y < H; y++) for (int z = 0; z < L; z++)
    blockMeshes[x][y][z] = new BlockMesh(&chunk->blocks[x][y][z], this, Ivec3(x, y, z));
}

void ChunkMesh::init(int _ctx) {
  ctx = _ctx;

  program = Helper::loadProgram("assets/chunk.vsh", "assets/chunk.fsh");
  glUseProgram(program);

  positionLocation = glGetAttribLocation(program, "a_position");
  texcoordLocation = glGetAttribLocation(program, "a_texcoord");
}

void ChunkMesh::updateBlockMesh(const Ivec3 p) {
  if (!Chunk::isBound(p))
    return;

  blockMeshes[p.x][p.y][p.z]->updateBlockMesh();
}

void ChunkMesh::updateChunkMesh() {
  for (int x = 0; x < W; x++) for (int y = 0; y < H; y++) for (int z = 0; z < L; z++)
    blockMeshes[x][y][z]->updateBlockMesh();
}

void ChunkMesh::updateVao() {
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
  glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), positions.data(), GL_DYNAMIC_DRAW);
  
  glEnableVertexAttribArray(positionLocation);
  glVertexAttribPointer(positionLocation, 3, GL_FLOAT, false, 0, 0);
  
  glBindBuffer(GL_ARRAY_BUFFER, texcoordBuffer);
  glBufferData(GL_ARRAY_BUFFER, texcoords.size() * sizeof(float), texcoords.data(), GL_DYNAMIC_DRAW);
  
  glEnableVertexAttribArray(texcoordLocation);
  glVertexAttribPointer(texcoordLocation, 2, GL_FLOAT, false, 0, 0);
  
  glBindVertexArray(0);
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

void ChunkMesh::draw() {
  glBindVertexArray(vao);

  glDrawArrays(GL_TRIANGLES, 0, 3);
  
  glBindVertexArray(0);
}

#endif // !defined(CHUNKMESH_C)