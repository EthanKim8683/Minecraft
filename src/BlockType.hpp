#if !defined(BLOCKTYPE_H)
#define BLOCKTYPE_H

#include <stdint.h>
#include <array>
#include <vector>

#include "Point.hpp"
#include "Triangle.hpp"

struct Point;
struct Triangle;

struct BlockType {
  public:
    const static BlockType types[];

    BlockType(bool, const std::array<std::vector<Triangle>, 7>*);

    bool isSolid() const;

    const std::vector<Triangle> getSide(int) const;
    
  private:
    const static std::array<std::vector<Triangle>, 7> meshes[];
    bool _isSolid;
    const std::array<std::vector<Triangle>, 7>* _meshes;
};

#endif // !defined(BLOCKTYPE_H)