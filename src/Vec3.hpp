#if !defined(VEC3_H)
#define VEC3_H

#include <algorithm>
#include <cmath>

#include "Vec2.hpp"
#include "Ivec3.hpp"

struct Vec2;
struct Ivec3;

struct Vec3 {
  double x, y, z;

  Vec3();
  Vec3(double);
  Vec3(int);
  Vec3(double, double, double);
  Vec3(int, int, int);
  Vec3(const Vec2&);
  Vec3(const Ivec3&);

  Vec3& operator+=(const Vec3&);
  Vec3& operator-=(const Vec3&);
  Vec3& operator*=(const Vec3&);
  Vec3& operator/=(const Vec3&);

  Vec3& operator+=(double);
  Vec3& operator-=(double);
  Vec3& operator*=(double);
  Vec3& operator/=(double);

  friend Vec3 operator+(Vec3, const Vec3&);
  friend Vec3 operator-(Vec3, const Vec3&);
  friend Vec3 operator*(Vec3, const Vec3&);
  friend Vec3 operator/(Vec3, const Vec3&);

  friend Vec3 operator+(Vec3, double);
  friend Vec3 operator-(Vec3, double);
  friend Vec3 operator*(Vec3, double);
  friend Vec3 operator/(Vec3, double);

  static Vec3 floor(const Vec3&);
  static Vec3 abs(const Vec3&);
  static Vec3 fract(const Vec3&);
  static double dot(const Vec3&, const Vec3&);
  static Vec3 cross(const Vec3&, const Vec3&);
  static Vec3 max(const Vec3&, const Vec3&);
  static Vec3 max(const Vec3&, double);
  static Vec3 min(const Vec3&, const Vec3&);
  static Vec3 min(const Vec3&, double);
  static Vec3 clamp(const Vec3&, const Vec3&, const Vec3&);
  static Vec3 clamp(const Vec3&, double, double);
  static Vec3 mix(const Vec3&, const Vec3&, const Vec3&);
  static Vec3 mix(const Vec3&, const Vec3&, double);
  static double length(const Vec3&);
  static Vec3 normalize(const Vec3&);
};

#endif // !defined(VEC3_H)