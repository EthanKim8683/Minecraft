#if !defined(NOISE_C)
#define NOISE_C

#include "Noise.hpp"

// https://github.com/stegu/webgl-noise

Vec3 Noise::mod289(Vec3 x) { return x - Vec3::floor(x * (1.0 / 289.0)) * 289.0; }
Vec2 Noise::mod289(Vec2 x) { return x - Vec2::floor(x * (1.0 / 289.0)) * 289.0; }
Vec3 Noise::permute(Vec3 x) { return Noise::mod289(((x * 34.0) + 10.0) + x); }

double Noise::snoise(Vec2 v) {
  const Vec4 C = Vec4(0.211324865405187, 0.366025403784439, -0.577350269189626, 0.024390243902439);

  Vec2 i  = Vec2::floor(v + Vec2::dot(v, C.y));
  Vec2 x0 = v - i + Vec2::dot(i, C.x);

  Vec2 i1 = x0.x > x0.y ? Vec2(1.0, 0.0) : Vec2(0.0, 1.0);
  Vec2 x1 = x0 + C.x - i1;
  Vec2 x2 = x0 + C.z;

  i = Noise::mod289(i);
  Vec3 p = Noise::permute(Noise::permute(i.y + Vec3(0.0, i1.y, 1.0)) + i.x + Vec3(0.0, i1.x, 1.0));

  Vec3 m = Vec3::max(0.5 - Vec3(Vec2::dot(x0, x0), Vec2::dot(x1, x1), Vec2::dot(x2, x2)), 0.0);
  m *= m;
  m *= m;

  Vec3 x = 2.0 * Vec3::fract(p * C.w) - 1.0;
  Vec3 h = Vec3::abs(x) - 0.5;
  Vec3 ox = Vec3::floor(x + 0.5);
  Vec3 a0 = x - ox;

  m *= 1.79284291400159 - 0.85373472095314 * (a0 * a0 + h * h);

  Vec3 g  = a0 * Vec3(x0.x, x1.x, x2.x) + h * Vec3(x0.y, x1.y, x2.y);
  return 130.0 * Vec3::dot(m, g);
}

#endif // !defined(NOISE_C)