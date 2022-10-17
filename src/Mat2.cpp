#if !defined(MAT2_C)
#define MAT2_C

#include "Mat2.hpp"

Mat2::Mat2() {}

Mat2::Mat2(double v) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
    if (i == j)
      data[i][j] = v;
    else
      data[i][j] = 0;
  }
}

Mat2::Mat2(double v00, double v01, double v10, double v11) {
  data[0][0] = v00;
  data[0][1] = v01;
  data[1][0] = v10;
  data[1][1] = v11;
}

Mat2& Mat2::operator+=(const Mat2& b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i][j] += b.data[i][j];
  return *this;
}

Mat2& Mat2::operator-=(const Mat2& b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i][j] -= b.data[i][j];
  return *this;
}

Mat2& Mat2::operator*=(const Mat2& b) {
  int temp[2][2];
  std::copy(&data[0][0], &data[0][0] + 2 * 2, &temp[0][0]);
  data[0][0] = temp[0][0] * b.data[0][0] + temp[1][0] * b.data[0][1];
  data[0][1] = temp[0][1] * b.data[0][0] + temp[1][1] * b.data[0][1];
  data[1][0] = temp[0][0] * b.data[1][0] + temp[1][0] * b.data[1][1];
  data[1][1] = temp[0][1] * b.data[1][0] + temp[1][1] * b.data[1][1];
  return *this;
}

Mat2& Mat2::operator+=(double b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i][j] += b;
  return *this;
}

Mat2& Mat2::operator-=(double b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i][j] -= b;
  return *this;
}

Mat2& Mat2::operator*=(double b) {
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    data[i][j] *= b;
  return *this;
}

Mat2 operator+(Mat2 a, const Mat2& b) { a += b; return a; }
Mat2 operator-(Mat2 a, const Mat2& b) { a -= b; return a; }
Mat2 operator*(Mat2 a, const Mat2& b) { a *= b; return a; }

Mat2 operator+(Mat2 a, double b) { a += b; return a; }
Mat2 operator-(Mat2 a, double b) { a -= b; return a; }
Mat2 operator*(Mat2 a, double b) { a *= b; return a; }

Vec2 operator*(const Mat2& a, const Vec2& b) {
  return Vec2(
    a.data[0][0] * b.x + a.data[1][0] * b.y,
    a.data[0][1] * b.x + a.data[1][1] * b.y
  );
}

Vec2 operator*(const Vec2& a, const Mat2& b) {
  return Vec2(
    b.data[0][0] * a.x + b.data[1][0] * a.y,
    b.data[0][1] * a.x + b.data[1][1] * a.y
  );
}

Mat2 Mat2::transpose(const Mat2& a) {
  return Mat2(
    a.data[0][0], a.data[1][0],
    a.data[0][1], a.data[1][1]
  );
}

Mat2 Mat2::invert(const Mat2& a) {
  double v00 = a.data[0][0];
  double v01 = a.data[0][1];
  double v10 = a.data[1][0];
  double v11 = a.data[1][1];
  Mat2 result;
  result.data[0][0] = 1 / v00;
  v01 *= result.data[0][0];
  v11 -= v01 * v10;
  result.data[1][0] = -result.data[0][0] * v10;
  result.data[1][1] = 1 / v11;
  result.data[1][0] *= result.data[1][1];
  result.data[0][0] -= result.data[1][0] * v01;
  result.data[0][1] = -result.data[1][1] * v01;
  return result;
}

#endif // !defined(MAT2_C)