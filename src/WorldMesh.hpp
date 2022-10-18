#if !defined(WORLDMESH_H)
#define WORLDMESH_H

#include <stdint.h>
#include <unordered_map>

#include "World.hpp"
#include "ChunkMesh.hpp"
#include "Hash.hpp"
#include "Ivec2.hpp"

class World;
class ChunkMesh;
struct Hash;
struct Ivec2;

class WorldMesh {
  public:
    WorldMesh(World*);

    ChunkMesh* createChunkMesh(const Ivec2&);
    ChunkMesh* getChunkMesh(const Ivec2&);
    ChunkMesh* getOrCreateChunkMesh(const Ivec2&);

    bool isChunkMeshCreated(const Ivec2&);

    void draw();

  private:
    World* world;

    std::unordered_map<uint64_t, ChunkMesh*> chunkMeshes;
};

#endif // !defined(WORLDMESH_H)