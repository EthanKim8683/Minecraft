#if !defined(IVEC4_H)
#define IVEC4_H

#include <algorithm>
#include <cmath>

#include "Ivec2.hpp"
#include "Ivec3.hpp"
#include "Vec4.hpp"

struct Ivec2;
struct Ivec3;
struct Vec4;

struct Ivec4 {
  int x, y, z, w;

  Ivec4();
  Ivec4(int);
  Ivec4(int, int, int, int);
  Ivec4(const Ivec2&);
  Ivec4(const Ivec3&);

  Ivec4& operator+=(const Ivec4&);
  Ivec4& operator-=(const Ivec4&);
  Ivec4& operator*=(const Ivec4&);
  Ivec4& operator/=(const Ivec4&);

  Ivec4& operator+=(int);
  Ivec4& operator-=(int);
  Ivec4& operator*=(int);
  Ivec4& operator/=(int);

  Ivec4 operator-();

  friend Ivec4 operator+(Ivec4, const Ivec4&);
  friend Ivec4 operator-(Ivec4, const Ivec4&);
  friend Ivec4 operator*(Ivec4, const Ivec4&);
  friend Ivec4 operator/(Ivec4, const Ivec4&);

  friend Ivec4 operator+(Ivec4, int);
  friend Ivec4 operator-(Ivec4, int);
  friend Ivec4 operator*(Ivec4, int);
  friend Ivec4 operator/(Ivec4, int);

  static Ivec4 floor(const Ivec4&);
  static Ivec4 abs(const Ivec4&);
  static Ivec4 fract(const Ivec4&);
  static int dot(const Ivec4&, const Ivec4&);
  static Ivec4 max(const Ivec4&, const Ivec4&);
  static Ivec4 max(const Ivec4&, int);
  static Ivec4 min(const Ivec4&, const Ivec4&);
  static Ivec4 min(const Ivec4&, int);
  static Ivec4 clamp(const Ivec4&, const Ivec4&, const Ivec4&);
  static Ivec4 clamp(const Ivec4&, int, int);
  static Vec4 mix(const Ivec4&, const Ivec4&, const Vec4&);
  static Vec4 mix(const Ivec4&, const Ivec4&, float);
  static float length(const Ivec4&);
  static Vec4 normalize(const Ivec4&);
};

#endif // !defined(IVEC4_H)