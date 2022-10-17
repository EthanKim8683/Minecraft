#if !defined(MAT4_H)
#define MAT4_H

#include <algorithm>
#include <math.h>

#include "Vec4.hpp"

struct Mat4 {
  float data[4 * 4];

  Mat4();
  Mat4(float);
  Mat4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);

  Mat4& operator+=(const Mat4&);
  Mat4& operator-=(const Mat4&);
  Mat4& operator*=(const Mat4&);

  Mat4& operator+=(float);
  Mat4& operator-=(float);
  Mat4& operator*=(float);

  friend Mat4 operator+(Mat4, const Mat4&);
  friend Mat4 operator-(Mat4, const Mat4&);
  friend Mat4 operator*(Mat4, const Mat4&);

  friend Mat4 operator+(Mat4, float);
  friend Mat4 operator-(Mat4, float);
  friend Mat4 operator*(Mat4, float);
  
  friend Vec4 operator*(const Mat4&, const Vec4&);
  friend Vec4 operator*(const Vec4&, const Mat4&);

  static Mat4 transpose(const Mat4&);
  static Mat4 invert(const Mat4&);
  static Mat4 translation(const Vec3&);
  static Mat4 rotationX(float);
  static Mat4 rotationY(float);
  static Mat4 rotationZ(float);
  static Mat4 rotation(const Vec3&);
  static Mat4 scaling(const Vec3&);
  static Mat4 projection(float, float, float, float);
};

#endif // !defined(MAT4_H)