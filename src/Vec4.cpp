#if !defined(VEC4_C)
#define VEC4_C

#include "Vec4.hpp"

Vec4::Vec4(): x(0), y(0), z(0), w(0) {}
Vec4::Vec4(double v): x(v), y(v), z(v), w(v) {}
Vec4::Vec4(int v): x(v), y(v), z(v), w(v) {}
Vec4::Vec4(double _x, double _y, double _z, double _w): x(_x), y(_y), z(_z), w(_w) {}
Vec4::Vec4(int _x, int _y, int _z, int _w): x(_x), y(_y), z(_z), w(_w) {}
Vec4::Vec4(const Vec2& v): x(v.x), y(v.y), z(0), w(0) {}
Vec4::Vec4(const Vec3& v): x(v.x), y(v.y), z(v.z), w(0) {}
Vec4::Vec4(const Ivec4& v): x(v.x), y(v.y), z(v.z), w(v.w) {}

Vec4& Vec4::operator+=(const Vec4& b) { x += b.x, y += b.y, z += b.z, w += b.w; return *this; }
Vec4& Vec4::operator-=(const Vec4& b) { x -= b.x, y -= b.y, z -= b.z, w -= b.w; return *this; }
Vec4& Vec4::operator*=(const Vec4& b) { x *= b.x, y *= b.y, z *= b.z, w *= b.w; return *this; }
Vec4& Vec4::operator/=(const Vec4& b) { x /= b.x, y /= b.y, z /= b.z, w /= b.w; return *this; }

Vec4& Vec4::operator+=(double v) { x += v, y += v, z += v, w += v; return *this; }
Vec4& Vec4::operator-=(double v) { x -= v, y -= v, z -= v, w -= v; return *this; }
Vec4& Vec4::operator*=(double v) { x *= v, y *= v, z *= v, w *= v; return *this; }
Vec4& Vec4::operator/=(double v) { x /= v, y /= v, z /= v, w /= v; return *this; }

Vec4 operator+(Vec4 a, const Vec4& b) { a += b; return a; }
Vec4 operator-(Vec4 a, const Vec4& b) { a -= b; return a; }
Vec4 operator*(Vec4 a, const Vec4& b) { a *= b; return a; }
Vec4 operator/(Vec4 a, const Vec4& b) { a /= b; return a; }

Vec4 operator+(Vec4 a, double b) { a += b; return a; }
Vec4 operator-(Vec4 a, double b) { a -= b; return a; }
Vec4 operator*(Vec4 a, double b) { a *= b; return a; }
Vec4 operator/(Vec4 a, double b) { a /= b; return a; }

Vec4 Vec4::floor(const Vec4& a) {
  return Vec4(std::floor(a.x), std::floor(a.y), std::floor(a.z), std::floor(a.w));
}

Vec4 Vec4::abs(const Vec4& a) {
  return Vec4(std::abs(a.x), std::abs(a.y), std::abs(a.z), std::abs(a.w));
}

Vec4 Vec4::fract(const Vec4& a) {
  return a - floor(a);
}

double Vec4::dot(const Vec4& a, const Vec4& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vec4 Vec4::max(const Vec4& a, const Vec4& b) {
  return Vec4(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z), std::max(a.w, b.w));
}

Vec4 Vec4::max(const Vec4& a, double b) {
  return Vec4(std::max(a.x, b), std::max(a.y, b), std::max(a.z, b), std::max(a.w, b));
}

Vec4 Vec4::min(const Vec4& a, const Vec4& b) {
  return Vec4(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z), std::min(a.w, b.w));
}

Vec4 Vec4::min(const Vec4& a, double b) {
  return Vec4(std::min(a.x, b), std::min(a.y, b), std::min(a.z, b), std::min(a.w, b));
}

Vec4 Vec4::clamp(const Vec4& a, const Vec4& b, const Vec4& c) {
  return Vec4(std::clamp(a.x, b.x, c.x), std::clamp(a.y, b.y, c.y), std::clamp(a.z, b.z, c.z), std::clamp(a.w, b.w, c.w));
}

Vec4 Vec4::clamp(const Vec4& a, double b, double c) {
  return Vec4(std::clamp(a.x, b, c), std::clamp(a.y, b, c), std::clamp(a.z, b, c), std::clamp(a.w, b, c));
}

Vec4 Vec4::mix(const Vec4& a, const Vec4& b, const Vec4& c) {
  return Vec4(a.x * (1 - c.x) + b.x * c.x, a.y * (1 - c.y) + b.y * c.y, a.z * (1 - c.z) + b.z * c.z, a.w * (1 - c.w) + b.w * c.w);
}

Vec4 Vec4::mix(const Vec4& a, const Vec4& b, double c) {
  return Vec4(a.x * (1 - c) + b.x * c, a.y * (1 - c) + b.y * c, a.z * (1 - c) + b.z * c, a.w * (1 - c) + b.w * c);
}

double Vec4::length(const Vec4& a) {
  return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

Vec4 Vec4::normalize(const Vec4& a) {
  return a / length(a);
}

#endif // !defined(VEC4_C)