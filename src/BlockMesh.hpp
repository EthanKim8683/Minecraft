#if !defined(BLOCKMESH_H)
#define BLOCKMESH_H

#include <stdint.h>
#include <vector>

#include "Block.hpp"
#include "BlockType.hpp"
#include "ChunkMesh.hpp"
#include "Vec3.hpp"
#include "Ivec3.hpp"

struct Block;
struct BlockType;
class ChunkMesh;
struct Vec3;
struct Ivec3;

class BlockMesh {
  public:
    BlockMesh(Block*, ChunkMesh*, const Ivec3&);

    void addSide(int);
    void removeSide(int);
    void setSide(int, bool);
    void updateBlockMesh();

  private:
    Vec3 position;
    Block* block;
    uint16_t cacheType = 0;
    ChunkMesh* chunkMesh;
    bool visible[7];
    std::vector<int> indices[7];
};

#endif // !defined(BLOCKMESH_H)