#if !defined(CHUNKITERATORZ_H)
#define CHUNKITERATORZ_H

#include "Chunk.hpp"

struct Chunk::IteratorZ {
  public:
    IteratorZ(Block*, uint16_t, uint16_t);

    const Block& operator*();
    Block* operator->();

    friend bool operator==(const IteratorZ&, const IteratorZ&);
    friend bool operator!=(const IteratorZ&, const IteratorZ&);

    IteratorZ& operator++();
    IteratorZ operator++(int);
    
  private:
    Block* ptr;
    uint16_t x, y;
};

#endif // !defined(CHUNKITERATORZ_H)