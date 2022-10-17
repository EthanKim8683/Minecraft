#if !defined(MAT4_H)
#define MAT4_H

#include <algorithm>
#include <math.h>

#include "Vec4.hpp"

struct Mat4 {
  double data[4][4];

  Mat4();
  Mat4(double);
  Mat4(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);

  Mat4& operator+=(const Mat4&);
  Mat4& operator-=(const Mat4&);
  Mat4& operator*=(const Mat4&);

  Mat4& operator+=(double);
  Mat4& operator-=(double);
  Mat4& operator*=(double);

  friend Mat4 operator+(Mat4, const Mat4&);
  friend Mat4 operator-(Mat4, const Mat4&);
  friend Mat4 operator*(Mat4, const Mat4&);

  friend Mat4 operator+(Mat4, double);
  friend Mat4 operator-(Mat4, double);
  friend Mat4 operator*(Mat4, double);
  
  friend Vec4 operator*(const Mat4&, const Vec4&);
  friend Vec4 operator*(const Vec4&, const Mat4&);

  static Mat4 transpose(const Mat4&);
  static Mat4 invert(const Mat4&);
  static Mat4 translation(const Vec3&);
  static Mat4 rotationX(double);
  static Mat4 rotationY(double);
  static Mat4 rotationZ(double);
  static Mat4 rotation(const Vec3&);
  static Mat4 scaling(const Vec3&);
  static Mat4 projection(double, double, double, double);
};

#endif // !defined(MAT4_H)