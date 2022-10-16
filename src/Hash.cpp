#if !defined(HASH_C)
#define HASH_C

#include "Hash.hpp"

uint64_t Hash::magic(uint64_t x) {
  x = (x | (x << 16)) & 0x0000FFFF0000FFFF;
  x = (x | (x << 8 )) & 0x00FF00FF00FF00FF;
  x = (x | (x << 4 )) & 0x0F0F0F0F0F0F0F0F;
  x = (x | (x << 2 )) & 0x3333333333333333;
  x = (x | (x << 1 )) & 0x5555555555555555;
  return x;
}

uint64_t Hash::mortonEncode(Ivec2 p) {
  return magic(p.x) | magic(p.y) << 1;
}

#endif // !defined(HASH_C)