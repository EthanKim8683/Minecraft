#if !defined(CHUNK_H)
#define CHUNK_H

#include <algorithm>
#include <vector>
#include <assert.h>
#include <stdint.h>

#include "Block.hpp"
#include "Noise.hpp"
#include "ChunkMesh.hpp"
#include "Ivec3.hpp"

struct Block;
struct Noise;
class ChunkMesh;
struct Ivec3;

class Chunk {
  friend class ChunkMesh;

  public:
    const static size_t W = 16;
    const static size_t H = 256;
    const static size_t L = 16;

    struct IteratorX;
    struct IteratorY;
    struct IteratorZ;

    Chunk(const Ivec2);

    static bool isBound(const Ivec3&);

    Block getBlock(const Ivec3&);

    IteratorX borderPosXBegin();
    IteratorY borderPosYBegin();
    IteratorZ borderPosZBegin();
    IteratorX borderNegXBegin();
    IteratorY borderNegYBegin();
    IteratorZ borderNegZBegin();

    IteratorX borderPosXEnd();
    IteratorY borderPosYEnd();
    IteratorZ borderPosZEnd();
    IteratorX borderNegXEnd();
    IteratorY borderNegYEnd();
    IteratorZ borderNegZEnd();

    void setBlockVisLocal(const Ivec3&);
    void setVisLocal();

    void setVisBorderPosX(IteratorX);
    void setVisBorderPosZ(IteratorZ);
    void setVisBorderNegX(IteratorX);
    void setVisBorderNegZ(IteratorZ);

    void genBlocks();
  
  private:
    Block blocks[W][H][L] = {0};
    Ivec2 position;
};

#endif // !defined(CHUNK_H)