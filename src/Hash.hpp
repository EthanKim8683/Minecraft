#if !defined(HASH_H)
#define HASH_H

#include <stdint.h>

#include "Ivec2.hpp"

struct Ivec2;

struct Hash {
  public:
    static uint64_t mortonEncode(Ivec2);
    
  private:
    static uint64_t magic(uint64_t);
};

#endif // !defined(HASH_H)