#if !defined(CHUNKMESH_H)
#define CHUNKMESH_H

#include <iostream>
#include <stdint.h>
#include <vector>

#include "Chunk.hpp"
#include "BlockMesh.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Ivec3.hpp"

class Chunk;
class BlockMesh;
struct Point;
struct Triangle;
struct Vec3;
struct Vec2;
struct Ivec3;

class ChunkMesh {
  public:
    const static size_t W = 16;
    const static size_t H = 256;
    const static size_t L = 16;

    ChunkMesh(Chunk&);

    void init();
    void update(const Ivec3);

    void addPosition(const Vec3);
    void addTexcoord(const Vec2);
    void addPoint(const Point&);
    void addTriangle(const Triangle&, int*);

    void removePosition(int);
    void removeTexcoord(int);
    void removePoint(int);
    void removeTriangle(int);

  private:
    std::vector<double> positions;
    std::vector<double> texcoords;
    std::vector<int*> indices;

    BlockMesh* blockMeshes[W][H][L];
};

#endif // !defined(CHUNKMESH_H)