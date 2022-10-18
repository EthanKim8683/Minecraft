#if !defined(VEC2_C)
#define VEC2_C

#include "Vec2.hpp"

Vec2::Vec2(): x(0), y(0) {}
Vec2::Vec2(float v): x(v), y(v) {}
Vec2::Vec2(float _x, float _y): x(_x), y(_y) {}
Vec2::Vec2(const Ivec2& v): x(v.x), y(v.y) {}

Vec2& Vec2::operator+=(const Vec2& b) { x += b.x, y += b.y; return *this; }
Vec2& Vec2::operator-=(const Vec2& b) { x -= b.x, y -= b.y; return *this; }
Vec2& Vec2::operator*=(const Vec2& b) { x *= b.x, y *= b.y; return *this; }
Vec2& Vec2::operator/=(const Vec2& b) { x /= b.x, y /= b.y; return *this; }

Vec2& Vec2::operator+=(float v) { x += v, y += v; return *this; }
Vec2& Vec2::operator-=(float v) { x -= v, y -= v; return *this; }
Vec2& Vec2::operator*=(float v) { x *= v, y *= v; return *this; }
Vec2& Vec2::operator/=(float v) { x /= v, y /= v; return *this; }

Vec2 Vec2::operator-() { return Vec2(-x, -y); }

Vec2 operator+(Vec2 a, const Vec2& b) { a += b; return a; }
Vec2 operator-(Vec2 a, const Vec2& b) { a -= b; return a; }
Vec2 operator*(Vec2 a, const Vec2& b) { a *= b; return a; }
Vec2 operator/(Vec2 a, const Vec2& b) { a /= b; return a; }

Vec2 operator+(Vec2 a, float b) { a += b; return a; }
Vec2 operator-(Vec2 a, float b) { a -= b; return a; }
Vec2 operator*(Vec2 a, float b) { a *= b; return a; }
Vec2 operator/(Vec2 a, float b) { a /= b; return a; }

Vec2 Vec2::floor(const Vec2& a) {
  return Vec2(std::floor(a.x), std::floor(a.y));
}

Vec2 Vec2::abs(const Vec2& a) {
  return Vec2(std::abs(a.x), std::abs(a.y));
}

Vec2 Vec2::fract(const Vec2& a) {
  return a - floor(a);
}

float Vec2::dot(const Vec2& a, const Vec2& b) {
  return a.x * b.x + a.y * b.y;
}

Vec2 Vec2::max(const Vec2& a, const Vec2& b) {
  return Vec2(std::max(a.x, b.x), std::max(a.y, b.y));
}

Vec2 Vec2::max(const Vec2& a, float b) {
  return Vec2(std::max(a.x, b), std::max(a.y, b));
}

Vec2 Vec2::min(const Vec2& a, const Vec2& b) {
  return Vec2(std::min(a.x, b.x), std::min(a.y, b.y));
}

Vec2 Vec2::min(const Vec2& a, float b) {
  return Vec2(std::min(a.x, b), std::min(a.y, b));
}

Vec2 Vec2::clamp(const Vec2& a, const Vec2& b, const Vec2& c) {
  return Vec2(std::clamp(a.x, b.x, c.x), std::clamp(a.y, b.y, c.y));
}

Vec2 Vec2::clamp(const Vec2& a, float b, float c) {
  return Vec2(std::clamp(a.x, b, c), std::clamp(a.y, b, c));
}

Vec2 Vec2::mix(const Vec2& a, const Vec2& b, const Vec2& c) {
  return Vec2(a.x * (1.0f - c.x) + b.x * c.x, a.y * (1.0f - c.y) + b.y * c.y);
}

Vec2 Vec2::mix(const Vec2& a, const Vec2& b, float c) {
  return Vec2(a.x * (1.0f - c) + b.x * c, a.y * (1.0f - c) + b.y * c);
}

float Vec2::length(const Vec2& a) {
  return sqrt(a.x * a.x + a.y * a.y);
}

Vec2 Vec2::normalize(const Vec2& a) {
  return a / length(a);
}

#endif // !defined(VEC2_C)