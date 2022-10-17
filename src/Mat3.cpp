#if !defined(MAT3_C)
#define MAT3_C

#include "Mat3.hpp"

Mat3::Mat3() {}

Mat3::Mat3(double v) {
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
    if (i == j)
      data[i][j] = v;
    else
      data[i][j] = 0;
  }
}

Mat3::Mat3(double v00, double v01, double v02, double v10, double v11, double v12, double v20, double v21, double v22) {
  data[0][0] = v00;
  data[0][1] = v01;
  data[0][2] = v02;
  data[1][0] = v10;
  data[1][1] = v11;
  data[1][2] = v12;
  data[2][0] = v20;
  data[2][1] = v21;
  data[2][2] = v22;
}

Mat3& Mat3::operator+=(const Mat3& b) {
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
    data[i][j] += b.data[i][j];
  return *this;
}

Mat3& Mat3::operator-=(const Mat3& b) {
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
    data[i][j] -= b.data[i][j];
  return *this;
}

Mat3& Mat3::operator*=(const Mat3& b) {
  int temp[3][3];
  std::copy(&data[0][0], &data[0][0] + 3 * 3, &temp[0][0]);
  data[0][0] = temp[0][0] * b.data[0][0] + temp[1][0] * b.data[0][1] + temp[2][0] * b.data[0][2];
  data[0][1] = temp[0][1] * b.data[0][0] + temp[1][1] * b.data[0][1] + temp[2][1] * b.data[0][2];
  data[0][2] = temp[0][2] * b.data[0][0] + temp[1][2] * b.data[0][1] + temp[2][2] * b.data[0][2];
  data[1][0] = temp[0][0] * b.data[1][0] + temp[1][0] * b.data[1][1] + temp[2][0] * b.data[1][2];
  data[1][1] = temp[0][1] * b.data[1][0] + temp[1][1] * b.data[1][1] + temp[2][1] * b.data[1][2];
  data[1][2] = temp[0][2] * b.data[1][0] + temp[1][2] * b.data[1][1] + temp[2][2] * b.data[1][2];
  data[2][0] = temp[0][0] * b.data[2][0] + temp[1][0] * b.data[2][1] + temp[2][0] * b.data[2][2];
  data[2][1] = temp[0][1] * b.data[2][0] + temp[1][1] * b.data[2][1] + temp[2][1] * b.data[2][2];
  data[2][2] = temp[0][2] * b.data[2][0] + temp[1][2] * b.data[2][1] + temp[2][2] * b.data[2][2];
  return *this;
}

Mat3& Mat3::operator+=(double b) {
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
    data[i][j] += b;
  return *this;
}

Mat3& Mat3::operator-=(double b) {
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
    data[i][j] -= b;
  return *this;
}

Mat3& Mat3::operator*=(double b) {
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
    data[i][j] *= b;
  return *this;
}

Mat3 operator+(Mat3 a, const Mat3& b) { a += b; return a; }
Mat3 operator-(Mat3 a, const Mat3& b) { a -= b; return a; }
Mat3 operator*(Mat3 a, const Mat3& b) { a *= b; return a; }

Mat3 operator+(Mat3 a, double b) { a += b; return a; }
Mat3 operator-(Mat3 a, double b) { a -= b; return a; }
Mat3 operator*(Mat3 a, double b) { a *= b; return a; }

Vec3 operator*(const Mat3& a, const Vec3& b) {
  return Vec3(
    a.data[0][0] * b.x + a.data[1][0] * b.y + a.data[2][0] * b.z,
    a.data[0][1] * b.x + a.data[1][1] * b.y + a.data[2][1] * b.z,
    a.data[0][2] * b.x + a.data[1][2] * b.y + a.data[2][2] * b.z
  );
}

Vec3 operator*(const Vec3& a, const Mat3& b) {
  return Vec3(
    b.data[0][0] * a.x + b.data[1][0] * a.y + b.data[2][0] * a.z,
    b.data[0][1] * a.x + b.data[1][1] * a.y + b.data[2][1] * a.z,
    b.data[0][2] * a.x + b.data[1][2] * a.y + b.data[2][2] * a.z
  );
}

Mat3 Mat3::transpose(const Mat3& a) {
  return Mat3(
    a.data[0][0], a.data[1][0], a.data[2][0],
    a.data[0][1], a.data[1][1], a.data[2][1],
    a.data[0][2], a.data[1][2], a.data[2][2]
  );
}

Mat3 Mat3::invert(const Mat3& a) {
  double v00 = a.data[0][0];
  double v01 = a.data[0][1];
  double v02 = a.data[0][2];
  double v10 = a.data[1][0];
  double v11 = a.data[1][1];
  double v12 = a.data[1][2];
  double v20 = a.data[2][0];
  double v21 = a.data[2][1];
  double v22 = a.data[2][2];
  Mat3 result;
  result.data[0][0] = 1 / v00;
  v01 *= result.data[0][0];
  v02 *= result.data[0][0];
  v11 -= v01 * v10;
  v12 -= v02 * v10;
  result.data[1][0] = -result.data[0][0] * v10;
  v21 -= v01 * v20;
  v22 -= v02 * v20;
  result.data[2][0] = -result.data[0][0] * v20;
  result.data[1][1] = 1 / v11;
  v12 *= result.data[1][1];
  result.data[1][0] *= result.data[1][1];
  v02 -= v12 * v01;
  result.data[0][0] -= result.data[1][0] * v01;
  result.data[0][1] = -result.data[1][1] * v01;
  v22 -= v12 * v21;
  result.data[2][0] -= result.data[1][0] * v21;
  result.data[2][1] = -result.data[1][1] * v21;
  result.data[2][2] = 1 / v22;
  result.data[2][0] *= result.data[2][2];
  result.data[2][1] *= result.data[2][2];
  result.data[0][0] -= result.data[2][0] * v02;
  result.data[0][1] -= result.data[2][1] * v02;
  result.data[0][2] = -result.data[2][2] * v02;
  result.data[1][0] -= result.data[2][0] * v12;
  result.data[1][1] -= result.data[2][1] * v12;
  result.data[1][2] = -result.data[2][2] * v12;
  return result;
}

#endif // !defined(MAT3_C)