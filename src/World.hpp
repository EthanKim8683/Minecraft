#if !defined(WORLD_H)
#define WORLD_H

#include <stdint.h>
#include <unordered_map>

#include "Chunk.hpp"
#include "ChunkIteratorX.hpp"
#include "ChunkIteratorY.hpp"
#include "ChunkIteratorZ.hpp"
#include "Hash.hpp"
#include "Ivec2.hpp"

class Chunk;
struct Hash;

class World {
  public:
    Chunk* createChunk(Ivec2);
    Chunk* getChunk(Ivec2);
    Chunk* getOrCreateChunk(Ivec2);

    bool isChunkCreated(Ivec2);

    void setChunkVisibilityGlobal(Ivec2);
    
  private:
    std::unordered_map<uint64_t, Chunk*> chunks;
};

#endif // !defined(WORLD_H)