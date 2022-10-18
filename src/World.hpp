#if !defined(WORLD_H)
#define WORLD_H

#include <stdint.h>
#include <unordered_map>
#include <math.h>

#include "Chunk.hpp"
#include "ChunkIteratorX.hpp"
#include "ChunkIteratorY.hpp"
#include "ChunkIteratorZ.hpp"
#include "Hash.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Ivec2.hpp"
#include "WorldMesh.hpp"
#include "Mat4.hpp"

class Chunk;
struct Hash;
struct Vec2;
struct Vec3;
struct Ivec2;
class WorldMesh;
struct Mat4;

class World {
  friend class WorldMesh;

  public:
    Chunk* createChunk(const Ivec2&);
    Chunk* getChunk(const Ivec2&);
    Chunk* getOrCreateChunk(const Ivec2&);

    bool isChunkCreated(const Ivec2&);

    void setChunkVisGlobal(const Ivec2&);

    void rotate(const Vec2&);
    void moveForward(float);
    void moveBackward(float);
    void moveLeftward(float);
    void moveRightward(float);
    void moveUpward(float);
    void moveDownward(float);

    Mat4 getViewMatrix();
    
  private:
    Vec2 rotation{0};
    Vec3 translation{32, 70, 32};

    std::unordered_map<uint64_t, Chunk*> chunks;
};

#endif // !defined(WORLD_H)