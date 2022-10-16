#if !defined(IVEC2_C)
#define IVEC2_C

#include "Ivec2.hpp"

Ivec2::Ivec2(): x(0), y(0) {}
Ivec2::Ivec2(int v): x(v), y(v) {}
Ivec2::Ivec2(int _x, int _y): x(_x), y(_y) {}

Ivec2& Ivec2::operator+=(const Ivec2& b) { x += b.x, y += b.y; return *this; }
Ivec2& Ivec2::operator-=(const Ivec2& b) { x -= b.x, y -= b.y; return *this; }
Ivec2& Ivec2::operator*=(const Ivec2& b) { x *= b.x, y *= b.y; return *this; }
Ivec2& Ivec2::operator/=(const Ivec2& b) { x /= b.x, y /= b.y; return *this; }

Ivec2& Ivec2::operator+=(int v) { x += v, y += v; return *this; }
Ivec2& Ivec2::operator-=(int v) { x -= v, y -= v; return *this; }
Ivec2& Ivec2::operator*=(int v) { x *= v, y *= v; return *this; }
Ivec2& Ivec2::operator/=(int v) { x /= v, y /= v; return *this; }

Ivec2 operator+(Ivec2 a, const Ivec2& b) { a += b; return a; }
Ivec2 operator-(Ivec2 a, const Ivec2& b) { a -= b; return a; }
Ivec2 operator*(Ivec2 a, const Ivec2& b) { a *= b; return a; }
Ivec2 operator/(Ivec2 a, const Ivec2& b) { a /= b; return a; }

Ivec2 operator+(Ivec2 a, int b) { a += b; return a; }
Ivec2 operator-(Ivec2 a, int b) { a -= b; return a; }
Ivec2 operator*(Ivec2 a, int b) { a *= b; return a; }
Ivec2 operator/(Ivec2 a, int b) { a /= b; return a; }

Ivec2 Ivec2::floor(const Ivec2& a) {
  return Ivec2(std::floor(a.x), std::floor(a.y));
}

Ivec2 Ivec2::abs(const Ivec2& a) {
  return Ivec2(std::abs(a.x), std::abs(a.y));
}

Ivec2 Ivec2::fract(const Ivec2& a) {
  return a - floor(a);
}

int Ivec2::dot(const Ivec2& a, const Ivec2& b) {
  return a.x * b.x + a.y * b.y;
}

Ivec2 Ivec2::max(const Ivec2& a, const Ivec2& b) {
  return Ivec2(std::max(a.x, b.x), std::max(a.y, b.y));
}

Ivec2 Ivec2::max(const Ivec2& a, int b) {
  return Ivec2(std::max(a.x, b), std::max(a.y, b));
}

Ivec2 Ivec2::min(const Ivec2& a, const Ivec2& b) {
  return Ivec2(std::min(a.x, b.x), std::min(a.y, b.y));
}

Ivec2 Ivec2::min(const Ivec2& a, int b) {
  return Ivec2(std::min(a.x, b), std::min(a.y, b));
}

Ivec2 Ivec2::clamp(const Ivec2& a, const Ivec2& b, const Ivec2& c) {
  return Ivec2(std::clamp(a.x, b.x, c.x), std::clamp(a.y, b.y, c.y));
}

Ivec2 Ivec2::clamp(const Ivec2& a, int b, int c) {
  return Ivec2(std::clamp(a.x, b, c), std::clamp(a.y, b, c));
}

Vec2 Ivec2::mix(const Ivec2& a, const Ivec2& b, const Vec2& c) {
  return Vec2(a.x * (1 - c.x) + b.x * c.x, a.y * (1 - c.y) + b.y * c.y);
}

Vec2 Ivec2::mix(const Ivec2& a, const Ivec2& b, double c) {
  return Vec2(a.x * (1 - c) + b.x * c, a.y * (1 - c) + b.y * c);
}

double Ivec2::length(const Ivec2& a) {
  return sqrt(a.x * a.x + a.y * a.y);
}

Vec2 Ivec2::normalize(const Ivec2& a) {
  return a / length(a);
}

#endif // !defined(IVEC2_C)