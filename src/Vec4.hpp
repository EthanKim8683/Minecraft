#if !defined(VEC4_H)
#define VEC4_H

#include <algorithm>
#include <cmath>

#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Ivec4.hpp"

struct Vec2;
struct Vec3;
struct Ivec4;

struct Vec4 {
  float x, y, z, w;

  Vec4();
  Vec4(float);
  Vec4(float, float, float, float);
  Vec4(const Vec2&);
  Vec4(const Vec3&);
  Vec4(const Ivec4&);

  Vec4& operator+=(const Vec4&);
  Vec4& operator-=(const Vec4&);
  Vec4& operator*=(const Vec4&);
  Vec4& operator/=(const Vec4&);

  Vec4& operator+=(float);
  Vec4& operator-=(float);
  Vec4& operator*=(float);
  Vec4& operator/=(float);

  Vec4 operator-();

  friend Vec4 operator+(Vec4, const Vec4&);
  friend Vec4 operator-(Vec4, const Vec4&);
  friend Vec4 operator*(Vec4, const Vec4&);
  friend Vec4 operator/(Vec4, const Vec4&);

  friend Vec4 operator+(Vec4, float);
  friend Vec4 operator-(Vec4, float);
  friend Vec4 operator*(Vec4, float);
  friend Vec4 operator/(Vec4, float);

  static Vec4 floor(const Vec4&);
  static Vec4 abs(const Vec4&);
  static Vec4 fract(const Vec4&);
  static float dot(const Vec4&, const Vec4&);
  static Vec4 max(const Vec4&, const Vec4&);
  static Vec4 max(const Vec4&, float);
  static Vec4 min(const Vec4&, const Vec4&);
  static Vec4 min(const Vec4&, float);
  static Vec4 clamp(const Vec4&, const Vec4&, const Vec4&);
  static Vec4 clamp(const Vec4&, float, float);
  static Vec4 mix(const Vec4&, const Vec4&, const Vec4&);
  static Vec4 mix(const Vec4&, const Vec4&, float);
  static float length(const Vec4&);
  static Vec4 normalize(const Vec4&);
};

#endif // !defined(VEC4_H)