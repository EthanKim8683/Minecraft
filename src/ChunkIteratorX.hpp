#if !defined(CHUNKITERATORX_H)
#define CHUNKITERATORX_H

#include "Chunk.hpp"

struct Chunk::IteratorX {
  public:
    IteratorX(Block*, uint16_t, uint16_t);

    const Block& operator*();
    Block* operator->();

    friend bool operator==(const IteratorX&, const IteratorX&);
    friend bool operator!=(const IteratorX&, const IteratorX&);

    IteratorX& operator++();
    IteratorX operator++(int);
    
  private:
    Block* ptr;
    uint16_t y, z;
};

#endif // !defined(CHUNKITERATORX_H)