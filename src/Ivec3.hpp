#if !defined(IVEC3_H)
#define IVEC3_H

#include <algorithm>
#include <cmath>

#include "Ivec2.hpp"
#include "Vec3.hpp"

struct Ivec2;
struct Vec3;

struct Ivec3 {
  int x, y, z;

  Ivec3();
  Ivec3(int);
  Ivec3(int, int, int);
  Ivec3(const Ivec2&);

  Ivec3& operator+=(const Ivec3&);
  Ivec3& operator-=(const Ivec3&);
  Ivec3& operator*=(const Ivec3&);
  Ivec3& operator/=(const Ivec3&);

  Ivec3& operator+=(int);
  Ivec3& operator-=(int);
  Ivec3& operator*=(int);
  Ivec3& operator/=(int);

  Ivec3 operator-();

  friend Ivec3 operator+(Ivec3, const Ivec3&);
  friend Ivec3 operator-(Ivec3, const Ivec3&);
  friend Ivec3 operator*(Ivec3, const Ivec3&);
  friend Ivec3 operator/(Ivec3, const Ivec3&);

  friend Ivec3 operator+(Ivec3, int);
  friend Ivec3 operator-(Ivec3, int);
  friend Ivec3 operator*(Ivec3, int);
  friend Ivec3 operator/(Ivec3, int);

  static Ivec3 floor(const Ivec3&);
  static Ivec3 abs(const Ivec3&);
  static Ivec3 fract(const Ivec3&);
  static int dot(const Ivec3&, const Ivec3&);
  static Ivec3 cross(const Ivec3&, const Ivec3&);
  static Ivec3 max(const Ivec3&, const Ivec3&);
  static Ivec3 max(const Ivec3&, int);
  static Ivec3 min(const Ivec3&, const Ivec3&);
  static Ivec3 min(const Ivec3&, int);
  static Ivec3 clamp(const Ivec3&, const Ivec3&, const Ivec3&);
  static Ivec3 clamp(const Ivec3&, int, int);
  static Vec3 mix(const Ivec3&, const Ivec3&, const Vec3&);
  static Vec3 mix(const Ivec3&, const Ivec3&, float);
  static float length(const Ivec3&);
  static Vec3 normalize(const Ivec3&);
};

#endif // !defined(IVEC3_H)