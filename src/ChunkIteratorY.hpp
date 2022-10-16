#if !defined(CHUNKITERATORY_H)
#define CHUNKITERATORY_H

#include "Chunk.hpp"

struct Chunk::IteratorY {
  public:
    IteratorY(Block*, uint16_t, uint16_t);

    const Block& operator*();
    Block* operator->();

    friend bool operator==(const IteratorY&, const IteratorY&);
    friend bool operator!=(const IteratorY&, const IteratorY&);

    IteratorY& operator++();
    IteratorY operator++(int);
    
  private:
    Block* ptr;
    uint16_t x, z;
};

#endif // !defined(CHUNKITERATORY_H)