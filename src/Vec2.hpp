#if !defined(VEC2_H)
#define VEC2_H

#include <algorithm>
#include <cmath>

#include "Ivec2.hpp"

struct Ivec2;

struct Vec2 {
  float x, y;

  Vec2();
  Vec2(float);
  Vec2(int);
  Vec2(float, float);
  Vec2(int, int);
  Vec2(const Ivec2&);

  Vec2& operator+=(const Vec2&);
  Vec2& operator-=(const Vec2&);
  Vec2& operator*=(const Vec2&);
  Vec2& operator/=(const Vec2&);

  Vec2& operator+=(float);
  Vec2& operator-=(float);
  Vec2& operator*=(float);
  Vec2& operator/=(float);

  Vec2 operator-();

  friend Vec2 operator+(Vec2, const Vec2&);
  friend Vec2 operator-(Vec2, const Vec2&);
  friend Vec2 operator*(Vec2, const Vec2&);
  friend Vec2 operator/(Vec2, const Vec2&);

  friend Vec2 operator+(Vec2, float);
  friend Vec2 operator-(Vec2, float);
  friend Vec2 operator*(Vec2, float);
  friend Vec2 operator/(Vec2, float);

  static Vec2 floor(const Vec2&);
  static Vec2 abs(const Vec2&);
  static Vec2 fract(const Vec2&);
  static float dot(const Vec2&, const Vec2&);
  static Vec2 max(const Vec2&, const Vec2&);
  static Vec2 max(const Vec2&, float);
  static Vec2 min(const Vec2&, const Vec2&);
  static Vec2 min(const Vec2&, float);
  static Vec2 clamp(const Vec2&, const Vec2&, const Vec2&);
  static Vec2 clamp(const Vec2&, float, float);
  static Vec2 mix(const Vec2&, const Vec2&, const Vec2&);
  static Vec2 mix(const Vec2&, const Vec2&, float);
  static float length(const Vec2&);
  static Vec2 normalize(const Vec2&);
};

#endif // !defined(VEC2_H)