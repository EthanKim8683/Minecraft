#if !defined(CHUNKITERATORY_C)
#define CHUNKITERATORY_C

#include "ChunkIteratorY.hpp"

Chunk::IteratorY::IteratorY(Block* _ptr, uint16_t _x, uint16_t _z): ptr(_ptr), x(_x), z(_z) {}

const Block& Chunk::IteratorY::operator*() { return *ptr; }
Block* Chunk::IteratorY::operator->() { return ptr; }

bool operator==(const Chunk::IteratorY& a, const Chunk::IteratorY& b) { return a.ptr == b.ptr; }
bool operator!=(const Chunk::IteratorY& a, const Chunk::IteratorY& b) { return a.ptr != b.ptr; }

Chunk::IteratorY& Chunk::IteratorY::operator++() {
  if (x < W) {
    ptr += 1, z++;
    if (z == L) {
      z -= L, ptr -= L;
      x += 1, ptr += H * L;
    }
  }
  return *this;
}

Chunk::IteratorY Chunk::IteratorY::operator++(int) { const auto temp = *this; ++(*this); return temp; }

#endif // !defined(CHUNKITERATORY_C)