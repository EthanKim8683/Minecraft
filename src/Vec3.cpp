#if !defined(VEC3_C)
#define VEC3_C

#include "Vec3.hpp"

Vec3::Vec3(): x(0), y(0), z(0) {}
Vec3::Vec3(double v): x(v), y(v), z(v) {}
Vec3::Vec3(int v): x(v), y(v), z(v) {}
Vec3::Vec3(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
Vec3::Vec3(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
Vec3::Vec3(const Vec2& v): x(v.x), y(v.y), z(0) {}
Vec3::Vec3(const Ivec3& v): x(v.x), y(v.y), z(v.z) {}

Vec3& Vec3::operator+=(const Vec3& b) { x += b.x, y += b.y, z += b.z; return *this; }
Vec3& Vec3::operator-=(const Vec3& b) { x -= b.x, y -= b.y, z -= b.z; return *this; }
Vec3& Vec3::operator*=(const Vec3& b) { x *= b.x, y *= b.y, z *= b.z; return *this; }
Vec3& Vec3::operator/=(const Vec3& b) { x /= b.x, y /= b.y, z /= b.z; return *this; }

Vec3& Vec3::operator+=(double v) { x += v, y += v, z += v; return *this; }
Vec3& Vec3::operator-=(double v) { x -= v, y -= v, z -= v; return *this; }
Vec3& Vec3::operator*=(double v) { x *= v, y *= v, z *= v; return *this; }
Vec3& Vec3::operator/=(double v) { x /= v, y /= v, z /= v; return *this; }

Vec3 operator+(Vec3 a, const Vec3& b) { a += b; return a; }
Vec3 operator-(Vec3 a, const Vec3& b) { a -= b; return a; }
Vec3 operator*(Vec3 a, const Vec3& b) { a *= b; return a; }
Vec3 operator/(Vec3 a, const Vec3& b) { a /= b; return a; }

Vec3 operator+(Vec3 a, double b) { a += b; return a; }
Vec3 operator-(Vec3 a, double b) { a -= b; return a; }
Vec3 operator*(Vec3 a, double b) { a *= b; return a; }
Vec3 operator/(Vec3 a, double b) { a /= b; return a; }

Vec3 Vec3::floor(const Vec3& a) {
  return Vec3(std::floor(a.x), std::floor(a.y), std::floor(a.z));
}

Vec3 Vec3::abs(const Vec3& a) {
  return Vec3(std::abs(a.x), std::abs(a.y), std::abs(a.z));
}

Vec3 Vec3::fract(const Vec3& a) {
  return a - floor(a);
}

double Vec3::dot(const Vec3& a, const Vec3& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 Vec3::cross(const Vec3& a, const Vec3& b) {
  return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

Vec3 Vec3::max(const Vec3& a, const Vec3& b) {
  return Vec3(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
}

Vec3 Vec3::max(const Vec3& a, double b) {
  return Vec3(std::max(a.x, b), std::max(a.y, b), std::max(a.z, b));
}

Vec3 Vec3::min(const Vec3& a, const Vec3& b) {
  return Vec3(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}

Vec3 Vec3::min(const Vec3& a, double b) {
  return Vec3(std::min(a.x, b), std::min(a.y, b), std::min(a.z, b));
}

Vec3 Vec3::clamp(const Vec3& a, const Vec3& b, const Vec3& c) {
  return Vec3(std::clamp(a.x, b.x, c.x), std::clamp(a.y, b.y, c.y), std::clamp(a.z, b.z, c.z));
}

Vec3 Vec3::clamp(const Vec3& a, double b, double c) {
  return Vec3(std::clamp(a.x, b, c), std::clamp(a.y, b, c), std::clamp(a.z, b, c));
}

Vec3 Vec3::mix(const Vec3& a, const Vec3& b, const Vec3& c) {
  return Vec3(a.x * (1 - c.x) + b.x * c.x, a.y * (1 - c.y) + b.y * c.y, a.z * (1 - c.z) + b.z * c.z);
}

Vec3 Vec3::mix(const Vec3& a, const Vec3& b, double c) {
  return Vec3(a.x * (1 - c) + b.x * c, a.y * (1 - c) + b.y * c, a.z * (1 - c) + b.z * c);
}

double Vec3::length(const Vec3& a) {
  return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

Vec3 Vec3::normalize(const Vec3& a) {
  return a / length(a);
}

#endif // !defined(VEC3_C)