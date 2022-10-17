#if !defined(MAT2_H)
#define MAT2_H

#include <algorithm>

#include "Vec2.hpp"

struct Mat2 {
  double data[2][2];

  Mat2();
  Mat2(double);
  Mat2(double, double, double, double);

  Mat2& operator+=(const Mat2&);
  Mat2& operator-=(const Mat2&);
  Mat2& operator*=(const Mat2&);

  Mat2& operator+=(double);
  Mat2& operator-=(double);
  Mat2& operator*=(double);

  friend Mat2 operator+(Mat2, const Mat2&);
  friend Mat2 operator-(Mat2, const Mat2&);
  friend Mat2 operator*(Mat2, const Mat2&);

  friend Mat2 operator+(Mat2, double);
  friend Mat2 operator-(Mat2, double);
  friend Mat2 operator*(Mat2, double);
  
  friend Vec2 operator*(const Mat2&, const Vec2&);
  friend Vec2 operator*(const Vec2&, const Mat2&);

  static Mat2 transpose(const Mat2&);
  static Mat2 invert(const Mat2&);
};

#endif // !defined(MAT2_H)