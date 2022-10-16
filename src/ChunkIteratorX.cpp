#if !defined(CHUNKITERATORX_C)
#define CHUNKITERATORX_C

#include "ChunkIteratorX.hpp"

Chunk::IteratorX::IteratorX(Block* _ptr, uint16_t _y, uint16_t _z): ptr(_ptr), y(_y), z(_z) {}

const Block& Chunk::IteratorX::operator*() { return *ptr; }
Block* Chunk::IteratorX::operator->() { return ptr; }

bool operator==(const Chunk::IteratorX& a, const Chunk::IteratorX& b) { return a.ptr == b.ptr; }
bool operator!=(const Chunk::IteratorX& a, const Chunk::IteratorX& b) { return a.ptr != b.ptr; }

Chunk::IteratorX& Chunk::IteratorX::operator++() {
  if (y < H) {
    ptr += 1, z++;
    if (z == L) {
      z -= L, ptr -= L;
      y += 1, ptr += L;
    }
  }
  return *this;
}

Chunk::IteratorX Chunk::IteratorX::operator++(int) { const auto temp = *this; ++(*this); return temp; }

#endif // !defined(CHUNKITERATORX_C)