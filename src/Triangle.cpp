#if !defined(TRIANGLE_C)
#define TRIANGLE_C

#include "Triangle.hpp"

Triangle::Triangle(): points() {}
Triangle::Triangle(std::array<Point, 3> _points): points(_points) {}

Triangle Triangle::translate(const Vec3& delta) const {
  return Triangle({
    points[0].translate(delta),
    points[1].translate(delta),
    points[2].translate(delta)
  });
}

#endif // !defined(TRIANGLE_C)