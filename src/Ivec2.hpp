#if !defined(IVEC2_H)
#define IVEC2_H

#include <algorithm>
#include <cmath>

#include "Vec2.hpp"

struct Vec2;

struct Ivec2 {
  int x, y;

  Ivec2();
  Ivec2(int);
  Ivec2(int, int);

  Ivec2& operator+=(const Ivec2&);
  Ivec2& operator-=(const Ivec2&);
  Ivec2& operator*=(const Ivec2&);
  Ivec2& operator/=(const Ivec2&);

  Ivec2& operator+=(int);
  Ivec2& operator-=(int);
  Ivec2& operator*=(int);
  Ivec2& operator/=(int);

  friend Ivec2 operator+(Ivec2, const Ivec2&);
  friend Ivec2 operator-(Ivec2, const Ivec2&);
  friend Ivec2 operator*(Ivec2, const Ivec2&);
  friend Ivec2 operator/(Ivec2, const Ivec2&);

  friend Ivec2 operator+(Ivec2, int);
  friend Ivec2 operator-(Ivec2, int);
  friend Ivec2 operator*(Ivec2, int);
  friend Ivec2 operator/(Ivec2, int);

  static Ivec2 floor(const Ivec2&);
  static Ivec2 abs(const Ivec2&);
  static Ivec2 fract(const Ivec2&);
  static int dot(const Ivec2&, const Ivec2&);
  static Ivec2 max(const Ivec2&, const Ivec2&);
  static Ivec2 max(const Ivec2&, int);
  static Ivec2 min(const Ivec2&, const Ivec2&);
  static Ivec2 min(const Ivec2&, int);
  static Ivec2 clamp(const Ivec2&, const Ivec2&, const Ivec2&);
  static Ivec2 clamp(const Ivec2&, int, int);
  static Vec2 mix(const Ivec2&, const Ivec2&, const Vec2&);
  static Vec2 mix(const Ivec2&, const Ivec2&, double);
  static double length(const Ivec2&);
  static Vec2 normalize(const Ivec2&);
};

#endif // !defined(IVEC2_H)