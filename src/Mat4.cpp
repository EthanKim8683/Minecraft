#if !defined(MAT4_C)
#define MAT4_C

#include "Mat4.hpp"

Mat4::Mat4() {}

Mat4::Mat4(double v) {
  for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
    if (i == j)
      data[i][j] = v;
    else
      data[i][j] = 0;
  }
}

Mat4::Mat4(double v00, double v01, double v02, double v03, double v10, double v11, double v12, double v13, double v20, double v21, double v22, double v23, double v30, double v31, double v32, double v33) {
  data[0][0] = v00;
  data[0][1] = v01;
  data[0][2] = v02;
  data[0][3] = v03;
  data[1][0] = v10;
  data[1][1] = v11;
  data[1][2] = v12;
  data[1][3] = v13;
  data[2][0] = v20;
  data[2][1] = v21;
  data[2][2] = v22;
  data[2][3] = v23;
  data[3][0] = v30;
  data[3][1] = v31;
  data[3][2] = v32;
  data[3][3] = v33;
}

Mat4& Mat4::operator+=(const Mat4& b) {
  for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)
    data[i][j] += b.data[i][j];
  return *this;
}

Mat4& Mat4::operator-=(const Mat4& b) {
  for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)
    data[i][j] -= b.data[i][j];
  return *this;
}

Mat4& Mat4::operator*=(const Mat4& b) {
  int temp[4][4];
  std::copy(&data[0][0], &data[0][0] + 4 * 4, &temp[0][0]);
  data[0][0] = temp[0][0] * b.data[0][0] + temp[1][0] * b.data[0][1] + temp[2][0] * b.data[0][2] + temp[3][0] * b.data[0][3];
  data[0][1] = temp[0][1] * b.data[0][0] + temp[1][1] * b.data[0][1] + temp[2][1] * b.data[0][2] + temp[3][1] * b.data[0][3];
  data[0][2] = temp[0][2] * b.data[0][0] + temp[1][2] * b.data[0][1] + temp[2][2] * b.data[0][2] + temp[3][2] * b.data[0][3];
  data[0][3] = temp[0][3] * b.data[0][0] + temp[1][3] * b.data[0][1] + temp[2][3] * b.data[0][2] + temp[3][3] * b.data[0][3];
  data[1][0] = temp[0][0] * b.data[1][0] + temp[1][0] * b.data[1][1] + temp[2][0] * b.data[1][2] + temp[3][0] * b.data[1][3];
  data[1][1] = temp[0][1] * b.data[1][0] + temp[1][1] * b.data[1][1] + temp[2][1] * b.data[1][2] + temp[3][1] * b.data[1][3];
  data[1][2] = temp[0][2] * b.data[1][0] + temp[1][2] * b.data[1][1] + temp[2][2] * b.data[1][2] + temp[3][2] * b.data[1][3];
  data[1][3] = temp[0][3] * b.data[1][0] + temp[1][3] * b.data[1][1] + temp[2][3] * b.data[1][2] + temp[3][3] * b.data[1][3];
  data[2][0] = temp[0][0] * b.data[2][0] + temp[1][0] * b.data[2][1] + temp[2][0] * b.data[2][2] + temp[3][0] * b.data[2][3];
  data[2][1] = temp[0][1] * b.data[2][0] + temp[1][1] * b.data[2][1] + temp[2][1] * b.data[2][2] + temp[3][1] * b.data[2][3];
  data[2][2] = temp[0][2] * b.data[2][0] + temp[1][2] * b.data[2][1] + temp[2][2] * b.data[2][2] + temp[3][2] * b.data[2][3];
  data[2][3] = temp[0][3] * b.data[2][0] + temp[1][3] * b.data[2][1] + temp[2][3] * b.data[2][2] + temp[3][3] * b.data[2][3];
  data[3][0] = temp[0][0] * b.data[3][0] + temp[1][0] * b.data[3][1] + temp[2][0] * b.data[3][2] + temp[3][0] * b.data[3][3];
  data[3][1] = temp[0][1] * b.data[3][0] + temp[1][1] * b.data[3][1] + temp[2][1] * b.data[3][2] + temp[3][1] * b.data[3][3];
  data[3][2] = temp[0][2] * b.data[3][0] + temp[1][2] * b.data[3][1] + temp[2][2] * b.data[3][2] + temp[3][2] * b.data[3][3];
  data[3][3] = temp[0][3] * b.data[3][0] + temp[1][3] * b.data[3][1] + temp[2][3] * b.data[3][2] + temp[3][3] * b.data[3][3];
  return *this;
}

Mat4& Mat4::operator+=(double b) {
  for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)
    data[i][j] += b;
  return *this;
}

Mat4& Mat4::operator-=(double b) {
  for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)
    data[i][j] -= b;
  return *this;
}

Mat4& Mat4::operator*=(double b) {
  for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)
    data[i][j] *= b;
  return *this;
}

Mat4 operator+(Mat4 a, const Mat4& b) { a += b; return a; }
Mat4 operator-(Mat4 a, const Mat4& b) { a -= b; return a; }
Mat4 operator*(Mat4 a, const Mat4& b) { a *= b; return a; }

Mat4 operator+(Mat4 a, double b) { a += b; return a; }
Mat4 operator-(Mat4 a, double b) { a -= b; return a; }
Mat4 operator*(Mat4 a, double b) { a *= b; return a; }

Vec4 operator*(const Mat4& a, const Vec4& b) {
  return Vec4(
    a.data[0][0] * b.x + a.data[1][0] * b.y + a.data[2][0] * b.z + a.data[3][0] * b.w,
    a.data[0][1] * b.x + a.data[1][1] * b.y + a.data[2][1] * b.z + a.data[3][1] * b.w,
    a.data[0][2] * b.x + a.data[1][2] * b.y + a.data[2][2] * b.z + a.data[3][2] * b.w,
    a.data[0][3] * b.x + a.data[1][3] * b.y + a.data[2][3] * b.z + a.data[3][3] * b.w
  );
}

Vec4 operator*(const Vec4& a, const Mat4& b) {
  return Vec4(
    b.data[0][0] * a.x + b.data[1][0] * a.y + b.data[2][0] * a.z + b.data[3][0] * a.w,
    b.data[0][1] * a.x + b.data[1][1] * a.y + b.data[2][1] * a.z + b.data[3][1] * a.w,
    b.data[0][2] * a.x + b.data[1][2] * a.y + b.data[2][2] * a.z + b.data[3][2] * a.w,
    b.data[0][3] * a.x + b.data[1][3] * a.y + b.data[2][3] * a.z + b.data[3][3] * a.w
  );
}

Mat4 Mat4::transpose(const Mat4& a) {
  return Mat4(
    a.data[0][0], a.data[1][0], a.data[2][0], a.data[3][0],
    a.data[0][1], a.data[1][1], a.data[2][1], a.data[3][1],
    a.data[0][2], a.data[1][2], a.data[2][2], a.data[3][2],
    a.data[0][3], a.data[1][3], a.data[2][3], a.data[3][3]
  );
}

Mat4 Mat4::invert(const Mat4& a) {
  double v00 = a.data[0][0];
  double v01 = a.data[0][1];
  double v02 = a.data[0][2];
  double v03 = a.data[0][3];
  double v10 = a.data[1][0];
  double v11 = a.data[1][1];
  double v12 = a.data[1][2];
  double v13 = a.data[1][3];
  double v20 = a.data[2][0];
  double v21 = a.data[2][1];
  double v22 = a.data[2][2];
  double v23 = a.data[2][3];
  double v30 = a.data[3][0];
  double v31 = a.data[3][1];
  double v32 = a.data[3][2];
  double v33 = a.data[3][3];
  Mat4 result;
  result.data[0][0] = 1 / v00;
  v01 *= result.data[0][0];
  v02 *= result.data[0][0];
  v03 *= result.data[0][0];
  v11 -= v01 * v10;
  v12 -= v02 * v10;
  v13 -= v03 * v10;
  result.data[1][0] = -result.data[0][0] * v10;
  v21 -= v01 * v20;
  v22 -= v02 * v20;
  v23 -= v03 * v20;
  result.data[2][0] = -result.data[0][0] * v20;
  v31 -= v01 * v30;
  v32 -= v02 * v30;
  v33 -= v03 * v30;
  result.data[3][0] = -result.data[0][0] * v30;
  result.data[1][1] = 1 / v11;
  v12 *= result.data[1][1];
  v13 *= result.data[1][1];
  result.data[1][0] *= result.data[1][1];
  v02 -= v12 * v01;
  v03 -= v13 * v01;
  result.data[0][0] -= result.data[1][0] * v01;
  result.data[0][1] = -result.data[1][1] * v01;
  v22 -= v12 * v21;
  v23 -= v13 * v21;
  result.data[2][0] -= result.data[1][0] * v21;
  result.data[2][1] = -result.data[1][1] * v21;
  v32 -= v12 * v31;
  v33 -= v13 * v31;
  result.data[3][0] -= result.data[1][0] * v31;
  result.data[3][1] = -result.data[1][1] * v31;
  result.data[2][2] = 1 / v22;
  v23 *= result.data[2][2];
  result.data[2][0] *= result.data[2][2];
  result.data[2][1] *= result.data[2][2];
  v03 -= v23 * v02;
  result.data[0][0] -= result.data[2][0] * v02;
  result.data[0][1] -= result.data[2][1] * v02;
  result.data[0][2] = -result.data[2][2] * v02;
  v13 -= v23 * v12;
  result.data[1][0] -= result.data[2][0] * v12;
  result.data[1][1] -= result.data[2][1] * v12;
  result.data[1][2] = -result.data[2][2] * v12;
  v33 -= v23 * v32;
  result.data[3][0] -= result.data[2][0] * v32;
  result.data[3][1] -= result.data[2][1] * v32;
  result.data[3][2] = -result.data[2][2] * v32;
  result.data[3][3] = 1 / v33;
  result.data[3][0] *= result.data[3][3];
  result.data[3][1] *= result.data[3][3];
  result.data[3][2] *= result.data[3][3];
  result.data[0][0] -= result.data[3][0] * v03;
  result.data[0][1] -= result.data[3][1] * v03;
  result.data[0][2] -= result.data[3][2] * v03;
  result.data[0][3] = -result.data[3][3] * v03;
  result.data[1][0] -= result.data[3][0] * v13;
  result.data[1][1] -= result.data[3][1] * v13;
  result.data[1][2] -= result.data[3][2] * v13;
  result.data[1][3] = -result.data[3][3] * v13;
  result.data[2][0] -= result.data[3][0] * v23;
  result.data[2][1] -= result.data[3][1] * v23;
  result.data[2][2] -= result.data[3][2] * v23;
  result.data[2][3] = -result.data[3][3] * v23;
  return result;
}

Mat4 translation(const Vec3& a) {
  return Mat4(
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    a.x, a.y, a.z, 1
  );
}

Mat4 rotationX(double a) {
  double c = cos(a);
  double s = sin(a);
  return Mat4(
    1, 0, 0, 0,
    0, c, -s, 0,
    0, s, c, 0,
    0, 0, 0, 1
  );
}

Mat4 rotationY(double a) {
  double c = cos(a);
  double s = sin(a);
  return Mat4(
    c, 0, s, 0,
    0, 1, 0, 0,
    -s, 0, c, 0,
    0, 0, 0, 1
  );
}

Mat4 rotationZ(double a) {
  double c = cos(a);
  double s = sin(a);
  return Mat4(
    c, -s, 0, 0,
    s, c, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
  );
}

Mat4 rotation(const Vec3& a) {
  return rotationX(a.x) * rotationY(a.y) * rotationZ(a.z);
}

Mat4 scaling(const Vec3& a) {
  return Mat4(
    a.x, 0, 0, 0,
    0, a.y, 0, 0,
    0, 0, a.z, 0,
    0, 0, 0, 1
  );
}

Mat4 projection(double fov, double aspect, double near, double far) {
  double f = 1 / tan(fov / 2);
  double rangeInv = 1 / (near - far);
  return Mat4(
    f / aspect, 0, 0, 0,
    0, f, 0, 0,
    0, 0, (near + far) * rangeInv, -1,
    0, 0, near * far * rangeInv * 2, 0
  );
}

#endif // !defined(MAT4_C)