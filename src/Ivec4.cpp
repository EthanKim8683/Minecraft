#if !defined(IVEC4_C)
#define IVEC4_C

#include "Ivec4.hpp"

Ivec4::Ivec4(): x(0), y(0), z(0), w(0) {}
Ivec4::Ivec4(int v): x(v), y(v), z(v), w(v) {}
Ivec4::Ivec4(int _x, int _y, int _z, int _w): x(_x), y(_y), z(_z), w(_w) {}
Ivec4::Ivec4(const Ivec2& v): x(v.x), y(v.y), z(0), w(0) {}
Ivec4::Ivec4(const Ivec3& v): x(v.x), y(v.y), z(v.z), w(0) {}

Ivec4& Ivec4::operator+=(const Ivec4& b) { x += b.x, y += b.y, z += b.z, w += b.w; return *this; }
Ivec4& Ivec4::operator-=(const Ivec4& b) { x -= b.x, y -= b.y, z -= b.z, w -= b.w; return *this; }
Ivec4& Ivec4::operator*=(const Ivec4& b) { x *= b.x, y *= b.y, z *= b.z, w *= b.w; return *this; }
Ivec4& Ivec4::operator/=(const Ivec4& b) { x /= b.x, y /= b.y, z /= b.z, w /= b.w; return *this; }

Ivec4& Ivec4::operator+=(int v) { x += v, y += v, z += v, w += v; return *this; }
Ivec4& Ivec4::operator-=(int v) { x -= v, y -= v, z -= v, w -= v; return *this; }
Ivec4& Ivec4::operator*=(int v) { x *= v, y *= v, z *= v, w *= v; return *this; }
Ivec4& Ivec4::operator/=(int v) { x /= v, y /= v, z /= v, w /= v; return *this; }

Ivec4 Ivec4::operator-() { return Ivec4(-x, -y, -z, -w); }

Ivec4 operator+(Ivec4 a, const Ivec4& b) { a += b; return a; }
Ivec4 operator-(Ivec4 a, const Ivec4& b) { a -= b; return a; }
Ivec4 operator*(Ivec4 a, const Ivec4& b) { a *= b; return a; }
Ivec4 operator/(Ivec4 a, const Ivec4& b) { a /= b; return a; }

Ivec4 operator+(Ivec4 a, int b) { a += b; return a; }
Ivec4 operator-(Ivec4 a, int b) { a -= b; return a; }
Ivec4 operator*(Ivec4 a, int b) { a *= b; return a; }
Ivec4 operator/(Ivec4 a, int b) { a /= b; return a; }

Ivec4 Ivec4::floor(const Ivec4& a) {
  return Ivec4(std::floor(a.x), std::floor(a.y), std::floor(a.z), std::floor(a.w));
}

Ivec4 Ivec4::abs(const Ivec4& a) {
  return Ivec4(std::abs(a.x), std::abs(a.y), std::abs(a.z), std::abs(a.w));
}

Ivec4 Ivec4::fract(const Ivec4& a) {
  return a - floor(a);
}

int Ivec4::dot(const Ivec4& a, const Ivec4& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Ivec4 Ivec4::max(const Ivec4& a, const Ivec4& b) {
  return Ivec4(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z), std::max(a.w, b.w));
}

Ivec4 Ivec4::max(const Ivec4& a, int b) {
  return Ivec4(std::max(a.x, b), std::max(a.y, b), std::max(a.z, b), std::max(a.w, b));
}

Ivec4 Ivec4::min(const Ivec4& a, const Ivec4& b) {
  return Ivec4(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z), std::min(a.w, b.w));
}

Ivec4 Ivec4::min(const Ivec4& a, int b) {
  return Ivec4(std::min(a.x, b), std::min(a.y, b), std::min(a.z, b), std::min(a.w, b));
}

Ivec4 Ivec4::clamp(const Ivec4& a, const Ivec4& b, const Ivec4& c) {
  return Ivec4(std::clamp(a.x, b.x, c.x), std::clamp(a.y, b.y, c.y), std::clamp(a.z, b.z, c.z), std::clamp(a.w, b.w, c.w));
}

Ivec4 Ivec4::clamp(const Ivec4& a, int b, int c) {
  return Ivec4(std::clamp(a.x, b, c), std::clamp(a.y, b, c), std::clamp(a.z, b, c), std::clamp(a.w, b, c));
}

Vec4 Ivec4::mix(const Ivec4& a, const Ivec4& b, const Vec4& c) {
  return Vec4(a.x * (1.0f - c.x) + b.x * c.x, a.y * (1.0f - c.y) + b.y * c.y, a.z * (1.0f - c.z) + b.z * c.z, a.w * (1.0f - c.w) + b.w * c.w);
}

Vec4 Ivec4::mix(const Ivec4& a, const Ivec4& b, float c) {
  return Vec4(a.x * (1.0f - c) + b.x * c, a.y * (1.0f - c) + b.y * c, a.z * (1.0f - c) + b.z * c, a.w * (1.0f - c) + b.w * c);
}

float Ivec4::length(const Ivec4& a) {
  return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

Vec4 Ivec4::normalize(const Ivec4& a) {
  return a / length(a);
}

#endif // !defined(IVEC4_C)