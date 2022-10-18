#if !defined(MAT2_C)
#define MAT2_C

#include "Mat2.hpp"

Mat2::Mat2() {
  for (int i = 0; i < 2; i++)
    data[i * 2 + i] = 1.0f;
}

Mat2::Mat2(float v) {
  for (int i = 0; i < 2; i++)
    data[i * 2 + i] = v;
}

Mat2::Mat2(float v00, float v01, float v10, float v11) {
  data[0 * 2 + 0] = v00;
  data[0 * 2 + 1] = v01;
  data[1 * 2 + 0] = v10;
  data[1 * 2 + 1] = v11;
}

Mat2& Mat2::operator+=(const Mat2& b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i * 2 + j] += b.data[i * 2 + j];
  return *this;
}

Mat2& Mat2::operator-=(const Mat2& b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i * 2 + j] -= b.data[i * 2 + j];
  return *this;
}

Mat2& Mat2::operator*=(const Mat2& b) {
  static float temp[2 * 2];
  std::copy_n(&data[0 * 2 + 0], 2 * 2, &temp[0 * 2 + 0]);
  data[0 * 2 + 0] = temp[0 * 2 + 0] * b.data[0 * 2 + 0] + temp[1 * 2 + 0] * b.data[0 * 2 + 1];
  data[0 * 2 + 1] = temp[0 * 2 + 1] * b.data[0 * 2 + 0] + temp[1 * 2 + 1] * b.data[0 * 2 + 1];
  data[1 * 2 + 0] = temp[0 * 2 + 0] * b.data[1 * 2 + 0] + temp[1 * 2 + 0] * b.data[1 * 2 + 1];
  data[1 * 2 + 1] = temp[0 * 2 + 1] * b.data[1 * 2 + 0] + temp[1 * 2 + 1] * b.data[1 * 2 + 1];
  return *this;
}

Mat2& Mat2::operator+=(float b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i * 2 + j] += b;
  return *this;
}

Mat2& Mat2::operator-=(float b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i * 2 + j] -= b;
  return *this;
}

Mat2& Mat2::operator*=(float b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i * 2 + j] *= b;
  return *this;
}

Mat2 operator+(Mat2 a, const Mat2& b) { a += b; return a; }
Mat2 operator-(Mat2 a, const Mat2& b) { a -= b; return a; }
Mat2 operator*(Mat2 a, const Mat2& b) { a *= b; return a; }

Mat2 operator+(Mat2 a, float b) { a += b; return a; }
Mat2 operator-(Mat2 a, float b) { a -= b; return a; }
Mat2 operator*(Mat2 a, float b) { a *= b; return a; }

Vec2 operator*(const Mat2& a, const Vec2& b) {
  return Vec2(
    a.data[0 * 2 + 0] * b.x + a.data[1 * 2 + 0] * b.y,
    a.data[0 * 2 + 1] * b.x + a.data[1 * 2 + 1] * b.y
  );
}

Vec2 operator*(const Vec2& a, const Mat2& b) {
  return Vec2(
    b.data[0 * 2 + 0] * a.x + b.data[1 * 2 + 0] * a.y,
    b.data[0 * 2 + 1] * a.x + b.data[1 * 2 + 1] * a.y
  );
}

Mat2 Mat2::transpose(const Mat2& a) {
  return Mat2(
    a.data[0 * 2 + 0], a.data[1 * 2 + 0],
    a.data[0 * 2 + 1], a.data[1 * 2 + 1]
  );
}

Mat2 Mat2::invert(const Mat2& a) {
  float v00 = a.data[0 * 2 + 0];
  float v01 = a.data[0 * 2 + 1];
  float v10 = a.data[1 * 2 + 0];
  float v11 = a.data[1 * 2 + 1];
  Mat2 result;
  result.data[0 * 2 + 0] = 1 / v00;
  v01 *= result.data[0 * 2 + 0];
  v11 -= v01 * v10;
  result.data[1 * 2 + 0] = -result.data[0 * 2 + 0] * v10;
  result.data[1 * 2 + 1] = 1 / v11;
  result.data[1 * 2 + 0] *= result.data[1 * 2 + 1];
  result.data[0 * 2 + 0] -= result.data[1 * 2 + 0] * v01;
  result.data[0 * 2 + 1] = -result.data[1 * 2 + 1] * v01;
  return result;
}

#endif // !defined(MAT2_C)