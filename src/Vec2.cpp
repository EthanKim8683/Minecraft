#if !defined(VEC2_C)
#define VEC2_C

#include "Vec2.hpp"

Vec2::Vec2(): x(0), y(0) {}
Vec2::Vec2(double v): x(v), y(v) {}
Vec2::Vec2(int v): x(v), y(v) {}
Vec2::Vec2(double _x, double _y): x(_x), y(_y) {}
Vec2::Vec2(int _x, int _y): x(_x), y(_y) {}
Vec2::Vec2(const Ivec2& v): x(v.x), y(v.y) {}

Vec2& Vec2::operator+=(const Vec2& b) { x += b.x, y += b.y; return *this; }
Vec2& Vec2::operator-=(const Vec2& b) { x -= b.x, y -= b.y; return *this; }
Vec2& Vec2::operator*=(const Vec2& b) { x *= b.x, y *= b.y; return *this; }
Vec2& Vec2::operator/=(const Vec2& b) { x /= b.x, y /= b.y; return *this; }

Vec2& Vec2::operator+=(double v) { x += v, y += v; return *this; }
Vec2& Vec2::operator-=(double v) { x -= v, y -= v; return *this; }
Vec2& Vec2::operator*=(double v) { x *= v, y *= v; return *this; }
Vec2& Vec2::operator/=(double v) { x /= v, y /= v; return *this; }

Vec2 operator+(Vec2 a, const Vec2& b) { a += b; return a; }
Vec2 operator-(Vec2 a, const Vec2& b) { a -= b; return a; }
Vec2 operator*(Vec2 a, const Vec2& b) { a *= b; return a; }
Vec2 operator/(Vec2 a, const Vec2& b) { a /= b; return a; }

Vec2 operator+(Vec2 a, double b) { a += b; return a; }
Vec2 operator-(Vec2 a, double b) { a -= b; return a; }
Vec2 operator*(Vec2 a, double b) { a *= b; return a; }
Vec2 operator/(Vec2 a, double b) { a /= b; return a; }

Vec2 Vec2::floor(const Vec2& a) {
  return Vec2(std::floor(a.x), std::floor(a.y));
}

Vec2 Vec2::abs(const Vec2& a) {
  return Vec2(std::abs(a.x), std::abs(a.y));
}

Vec2 Vec2::fract(const Vec2& a) {
  return a - floor(a);
}

double Vec2::dot(const Vec2& a, const Vec2& b) {
  return a.x * b.x + a.y * b.y;
}

Vec2 Vec2::max(const Vec2& a, const Vec2& b) {
  return Vec2(std::max(a.x, b.x), std::max(a.y, b.y));
}

Vec2 Vec2::max(const Vec2& a, double b) {
  return Vec2(std::max(a.x, b), std::max(a.y, b));
}

Vec2 Vec2::min(const Vec2& a, const Vec2& b) {
  return Vec2(std::min(a.x, b.x), std::min(a.y, b.y));
}

Vec2 Vec2::min(const Vec2& a, double b) {
  return Vec2(std::min(a.x, b), std::min(a.y, b));
}

Vec2 Vec2::clamp(const Vec2& a, const Vec2& b, const Vec2& c) {
  return Vec2(std::clamp(a.x, b.x, c.x), std::clamp(a.y, b.y, c.y));
}

Vec2 Vec2::clamp(const Vec2& a, double b, double c) {
  return Vec2(std::clamp(a.x, b, c), std::clamp(a.y, b, c));
}

Vec2 Vec2::mix(const Vec2& a, const Vec2& b, const Vec2& c) {
  return Vec2(a.x * (1 - c.x) + b.x * c.x, a.y * (1 - c.y) + b.y * c.y);
}

Vec2 Vec2::mix(const Vec2& a, const Vec2& b, double c) {
  return Vec2(a.x * (1 - c) + b.x * c, a.y * (1 - c) + b.y * c);
}

double Vec2::length(const Vec2& a) {
  return sqrt(a.x * a.x + a.y * a.y);
}

Vec2 Vec2::normalize(const Vec2& a) {
  return a / length(a);
}

#endif // !defined(VEC2_C)