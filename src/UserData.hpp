#if !defined(USER_DATA_H)
#define USER_DATA_H

#include "World.hpp"
#include "WorldMesh.hpp"
#include "Env.hpp"

class World;
class WorldMesh;
struct Env;

struct UserData {
  int ctx;

  int width, height;
  float fov, aspect, near, far;
  
  Env* env;
  World* world;
  WorldMesh* worldMesh;
};

#endif // !defined(USER_DATA_H)