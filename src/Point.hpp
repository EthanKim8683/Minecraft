#if !defined(POINT_H)
#define POINT_H

#include "Vec3.hpp"
#include "Vec2.hpp"

struct Vec3;
struct Vec2;

struct Point {
  public:
    Vec3 positions;
    Vec2 texcoords;

    Point();
    Point(const Vec3&, const Vec2&);

    Point translate(const Vec3&) const;
};

#endif // !defined(POINT_H)