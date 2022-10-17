#if !defined(IVEC3_C)
#define IVEC3_C

#include "Ivec3.hpp"

Ivec3::Ivec3(): x(0), y(0), z(0) {}
Ivec3::Ivec3(int v): x(v), y(v), z(v) {}
Ivec3::Ivec3(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
Ivec3::Ivec3(const Ivec2& v): x(v.x), y(v.y), z(0) {}

Ivec3& Ivec3::operator+=(const Ivec3& b) { x += b.x, y += b.y, z += b.z; return *this; }
Ivec3& Ivec3::operator-=(const Ivec3& b) { x -= b.x, y -= b.y, z -= b.z; return *this; }
Ivec3& Ivec3::operator*=(const Ivec3& b) { x *= b.x, y *= b.y, z *= b.z; return *this; }
Ivec3& Ivec3::operator/=(const Ivec3& b) { x /= b.x, y /= b.y, z /= b.z; return *this; }

Ivec3& Ivec3::operator+=(int v) { x += v, y += v, z += v; return *this; }
Ivec3& Ivec3::operator-=(int v) { x -= v, y -= v, z -= v; return *this; }
Ivec3& Ivec3::operator*=(int v) { x *= v, y *= v, z *= v; return *this; }
Ivec3& Ivec3::operator/=(int v) { x /= v, y /= v, z /= v; return *this; }

Ivec3 Ivec3::operator-() { return Ivec3(-x, -y, -z); }

Ivec3 operator+(Ivec3 a, const Ivec3& b) { a += b; return a; }
Ivec3 operator-(Ivec3 a, const Ivec3& b) { a -= b; return a; }
Ivec3 operator*(Ivec3 a, const Ivec3& b) { a *= b; return a; }
Ivec3 operator/(Ivec3 a, const Ivec3& b) { a /= b; return a; }

Ivec3 operator+(Ivec3 a, int b) { a += b; return a; }
Ivec3 operator-(Ivec3 a, int b) { a -= b; return a; }
Ivec3 operator*(Ivec3 a, int b) { a *= b; return a; }
Ivec3 operator/(Ivec3 a, int b) { a /= b; return a; }

Ivec3 Ivec3::floor(const Ivec3& a) {
  return Ivec3(std::floor(a.x), std::floor(a.y), std::floor(a.z));
}

Ivec3 Ivec3::abs(const Ivec3& a) {
  return Ivec3(std::abs(a.x), std::abs(a.y), std::abs(a.z));
}

Ivec3 Ivec3::fract(const Ivec3& a) {
  return a - floor(a);
}

int Ivec3::dot(const Ivec3& a, const Ivec3& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Ivec3 Ivec3::cross(const Ivec3& a, const Ivec3& b) {
  return Ivec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

Ivec3 Ivec3::max(const Ivec3& a, const Ivec3& b) {
  return Ivec3(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
}

Ivec3 Ivec3::max(const Ivec3& a, int b) {
  return Ivec3(std::max(a.x, b), std::max(a.y, b), std::max(a.z, b));
}

Ivec3 Ivec3::min(const Ivec3& a, const Ivec3& b) {
  return Ivec3(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}

Ivec3 Ivec3::min(const Ivec3& a, int b) {
  return Ivec3(std::min(a.x, b), std::min(a.y, b), std::min(a.z, b));
}

Ivec3 Ivec3::clamp(const Ivec3& a, const Ivec3& b, const Ivec3& c) {
  return Ivec3(std::clamp(a.x, b.x, c.x), std::clamp(a.y, b.y, c.y), std::clamp(a.z, b.z, c.z));
}

Ivec3 Ivec3::clamp(const Ivec3& a, int b, int c) {
  return Ivec3(std::clamp(a.x, b, c), std::clamp(a.y, b, c), std::clamp(a.z, b, c));
}

Vec3 Ivec3::mix(const Ivec3& a, const Ivec3& b, const Vec3& c) {
  return Vec3(a.x * (1.0f - c.x) + b.x * c.x, a.y * (1.0f - c.y) + b.y * c.y, a.z * (1.0f - c.z) + b.z * c.z);
}

Vec3 Ivec3::mix(const Ivec3& a, const Ivec3& b, float c) {
  return Vec3(a.x * (1.0f - c) + b.x * c, a.y * (1.0f - c) + b.y * c, a.z * (1.0f - c) + b.z * c);
}

float Ivec3::length(const Ivec3& a) {
  return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

Vec3 Ivec3::normalize(const Ivec3& a) {
  return a / length(a);
}

#endif // !defined(IVEC3_C)