#if !defined(CHUNKITERATORZ_C)
#define CHUNKITERATORZ_C

#include "ChunkIteratorZ.hpp"

Chunk::IteratorZ::IteratorZ(Block* _ptr, uint16_t _x, uint16_t _y): ptr(_ptr), x(_x), y(_y) {}

const Block& Chunk::IteratorZ::operator*() { return *ptr; }
Block* Chunk::IteratorZ::operator->() { return ptr; }

bool operator==(const Chunk::IteratorZ& a, const Chunk::IteratorZ& b) { return a.ptr == b.ptr; }
bool operator!=(const Chunk::IteratorZ& a, const Chunk::IteratorZ& b) { return a.ptr != b.ptr; }

Chunk::IteratorZ& Chunk::IteratorZ::operator++() {
  if (x < W) {
    ptr += L, y++;
    if (y == H) {
      y -= H, ptr -= H * L;
      x += 1, ptr += H * L;
    }
  }
  return *this;
}

Chunk::IteratorZ Chunk::IteratorZ::operator++(int) { const auto temp = *this; ++(*this); return temp; }

#endif // !defined(CHUNKITERATORZ_C)