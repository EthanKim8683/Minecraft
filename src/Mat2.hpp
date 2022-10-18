#if !defined(MAT2_H)
#define MAT2_H

#include <algorithm>

#include "Vec2.hpp"

struct Mat2 {
  float data[2 * 2] = {0};

  Mat2();
  Mat2(float);
  Mat2(float, float, float, float);

  Mat2& operator+=(const Mat2&);
  Mat2& operator-=(const Mat2&);
  Mat2& operator*=(const Mat2&);

  Mat2& operator+=(float);
  Mat2& operator-=(float);
  Mat2& operator*=(float);

  friend Mat2 operator+(Mat2, const Mat2&);
  friend Mat2 operator-(Mat2, const Mat2&);
  friend Mat2 operator*(Mat2, const Mat2&);

  friend Mat2 operator+(Mat2, float);
  friend Mat2 operator-(Mat2, float);
  friend Mat2 operator*(Mat2, float);
  
  friend Vec2 operator*(const Mat2&, const Vec2&);
  friend Vec2 operator*(const Vec2&, const Mat2&);

  static Mat2 transpose(const Mat2&);
  static Mat2 invert(const Mat2&);
};

#endif // !defined(MAT2_H)