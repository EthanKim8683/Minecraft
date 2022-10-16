#if !defined(BLOCKTYPE_C)
#define BLOCKTYPE_C

#include "BlockType.hpp"

const std::array<std::vector<Triangle>, 7> BlockType::meshes[] = {
  /* Cube */ {
    std::vector<Triangle>({
      Triangle({Point({1, 0, 0}, {0, 0}),
                Point({1, 1, 1}, {0, 1}),
                Point({1, 0, 1}, {1, 1})}),
      Triangle({Point({1, 0, 0}, {0, 0}),
                Point({1, 1, 0}, {1, 1}),
                Point({1, 1, 1}, {1, 0})})
    }),
    std::vector<Triangle>({
      Triangle({Point({0, 1, 0}, {0, 0}),
                Point({0, 1, 1}, {0, 1}),
                Point({1, 1, 1}, {1, 1})}),
      Triangle({Point({0, 1, 0}, {0, 0}),
                Point({1, 1, 1}, {1, 1}),
                Point({1, 1, 0}, {1, 0})})
    }),
    std::vector<Triangle>({
      Triangle({Point({0, 0, 1}, {0, 0}),
                Point({1, 1, 1}, {0, 1}),
                Point({0, 1, 1}, {1, 1})}),
      Triangle({Point({0, 0, 1}, {0, 0}),
                Point({1, 0, 1}, {1, 1}),
                Point({1, 1, 1}, {1, 0})})
    }),
    std::vector<Triangle>({
      Triangle({Point({0, 0, 0}, {0, 0}),
                Point({0, 0, 1}, {0, 1}),
                Point({0, 1, 1}, {1, 1})}),
      Triangle({Point({0, 0, 0}, {0, 0}),
                Point({0, 1, 1}, {1, 1}),
                Point({0, 1, 0}, {1, 0})})
    }),
    std::vector<Triangle>({
      Triangle({Point({0, 0, 0}, {0, 0}),
                Point({1, 0, 1}, {1, 1}),
                Point({0, 0, 1}, {1, 0})}),
      Triangle({Point({0, 0, 0}, {0, 0}),
                Point({1, 0, 0}, {0, 1}),
                Point({1, 0, 1}, {1, 1})})
    }),
    std::vector<Triangle>({
      Triangle({Point({0, 0, 0}, {0, 0}),
                Point({0, 1, 0}, {0, 1}),
                Point({1, 1, 0}, {1, 1})}),
      Triangle({Point({0, 0, 0}, {0, 0}),
                Point({1, 1, 0}, {1, 1}),
                Point({1, 0, 0}, {1, 0})})
    }),
    std::vector<Triangle>({})
  }
};

const BlockType BlockType::types[] = {
  /* Air   */ {false, NULL      },
  /* Dirt  */ {true,  &meshes[0]},
  /* Grass */ {true,  &meshes[0]}
};

BlockType::BlockType(bool $isSolid, const std::array<std::vector<Triangle>, 7>* $meshes): _isSolid($isSolid), _meshes($meshes) {}

bool BlockType::isSolid() const {
  return _isSolid;
}

const std::vector<Triangle> BlockType::getSide(int i) const {
  return (*_meshes)[i];
}

#endif // !defined(BLOCKTYPE_C)