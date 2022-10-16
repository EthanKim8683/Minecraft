#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <array>

#include "Point.hpp"

struct Point;

struct Triangle {
  public:
    std::array<Point, 3> points;

    Triangle();
    Triangle(std::array<Point, 3>);

    Triangle translate(const Vec3&) const;
};

#endif // !defined(TRIANGLE_H)