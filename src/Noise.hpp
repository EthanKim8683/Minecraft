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
    static float snoise(const Vec2& v);
    
  private:
    static Vec3 mod289(const Vec3& x);
    static Vec2 mod289(const Vec2& x);
    static Vec3 permute(const Vec3& x);
};

#endif // !defined(NOISE_H)