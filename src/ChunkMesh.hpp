#if !defined(CHUNKMESH_H)
#define CHUNKMESH_H

#include <iostream>
#include <stdint.h>
#include <vector>
#include <GLES3/gl3.h>

#include "Chunk.hpp"
#include "BlockMesh.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Ivec3.hpp"
#include "Helper.hpp"
#include "Mat4.hpp"
#include "Env.hpp"

class Chunk;
class BlockMesh;
struct Point;
struct Triangle;
struct Vec3;
struct Vec2;
struct Ivec3;
struct Helper;
struct Mat4;
struct Env;

class ChunkMesh {
  public:
    const static size_t W = 16;
    const static size_t H = 256;
    const static size_t L = 16;

    ChunkMesh(Chunk*);
    
    void updateBlockMesh(const Ivec3&);
    void updateChunkMesh();
    void updateVao(Env*);

    void addPosition(const Vec3&);
    void addTexcoord(const Vec2&);
    void addPoint(const Point&);
    void addTriangle(const Triangle&, int*);

    void removePosition(int);
    void removeTexcoord(int);
    void removePoint(int);
    void removeTriangle(int);

    void draw();

  private:
    GLuint vao;
    GLuint positionBuffer;
    GLuint texcoordBuffer;
    
    std::vector<float> positions;
    std::vector<float> texcoords;
    std::vector<int*> indices;

    BlockMesh* blockMeshes[W][H][L];
};

#endif // !defined(CHUNKMESH_H)