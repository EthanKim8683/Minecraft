#if !defined(NOISE_H)
#define NOISE_H

#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"

struct Vec2;
struct Vec3;
struct Vec4;

struct Noise {
  public:
    static double snoise(Vec2 v);
    
  private:
    static Vec3 mod289(Vec3 x);
    static Vec2 mod289(Vec2 x);
    static Vec3 permute(Vec3 x);
};

#endif // !defined(NOISE_H)