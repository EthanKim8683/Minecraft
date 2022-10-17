#if !defined(MAT3_H)
#define MAT3_H

#include <algorithm>

#include "Vec3.hpp"

struct Mat3 {
  double data[3][3];

  Mat3();
  Mat3(double);
  Mat3(double, double, double, double, double, double, double, double, double);

  Mat3& operator+=(const Mat3&);
  Mat3& operator-=(const Mat3&);
  Mat3& operator*=(const Mat3&);

  Mat3& operator+=(double);
  Mat3& operator-=(double);
  Mat3& operator*=(double);

  friend Mat3 operator+(Mat3, const Mat3&);
  friend Mat3 operator-(Mat3, const Mat3&);
  friend Mat3 operator*(Mat3, const Mat3&);

  friend Mat3 operator+(Mat3, double);
  friend Mat3 operator-(Mat3, double);
  friend Mat3 operator*(Mat3, double);
  
  friend Vec3 operator*(const Mat3&, const Vec3&);
  friend Vec3 operator*(const Vec3&, const Mat3&);

  static Mat3 transpose(const Mat3&);
  static Mat3 invert(const Mat3&);
};

#endif // !defined(MAT3_H)