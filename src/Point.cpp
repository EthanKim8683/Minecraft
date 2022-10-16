#if !defined(POINT_C)
#define POINT_C

#include "Point.hpp"

Point::Point(): positions(), texcoords() {}
Point::Point(Vec3 _positions, Vec2 _texcoords): positions(_positions), texcoords(_texcoords) {}

Point Point::translate(const Vec3& delta) const {
  return Point(positions + delta, texcoords);
}

#endif // !defined(POINT_C)