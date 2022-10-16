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
  double x, y, z, w;

  Vec4();
  Vec4(double);
  Vec4(int);
  Vec4(double, double, double, double);
  Vec4(int, int, int, int);
  Vec4(const Vec2&);
  Vec4(const Vec3&);
  Vec4(const Ivec4&);

  Vec4& operator+=(const Vec4&);
  Vec4& operator-=(const Vec4&);
  Vec4& operator*=(const Vec4&);
  Vec4& operator/=(const Vec4&);

  Vec4& operator+=(double);
  Vec4& operator-=(double);
  Vec4& operator*=(double);
  Vec4& operator/=(double);

  friend Vec4 operator+(Vec4, const Vec4&);
  friend Vec4 operator-(Vec4, const Vec4&);
  friend Vec4 operator*(Vec4, const Vec4&);
  friend Vec4 operator/(Vec4, const Vec4&);

  friend Vec4 operator+(Vec4, double);
  friend Vec4 operator-(Vec4, double);
  friend Vec4 operator*(Vec4, double);
  friend Vec4 operator/(Vec4, double);

  static Vec4 floor(const Vec4&);
  static Vec4 abs(const Vec4&);
  static Vec4 fract(const Vec4&);
  static double dot(const Vec4&, const Vec4&);
  static Vec4 max(const Vec4&, const Vec4&);
  static Vec4 max(const Vec4&, double);
  static Vec4 min(const Vec4&, const Vec4&);
  static Vec4 min(const Vec4&, double);
  static Vec4 clamp(const Vec4&, const Vec4&, const Vec4&);
  static Vec4 clamp(const Vec4&, double, double);
  static Vec4 mix(const Vec4&, const Vec4&, const Vec4&);
  static Vec4 mix(const Vec4&, const Vec4&, double);
  static double length(const Vec4&);
  static Vec4 normalize(const Vec4&);
};

#endif // !defined(VEC4_H)