#if !defined(BLOCK_C)
#define BLOCK_C

#include "Block.hpp"

Block::Block(): bits() {}
Block::Block(uint16_t _bits): bits(_bits) {}
Block::Block(const Block& block): bits(block.bits) {}

bool operator==(const Block& a, const Block& b) {
  return a.bits == b.bits;
}

bool operator==(const Block& a, uint16_t b) {
  return a.bits == b;
}

void Block::setVisPosX(bool vis) { bits = (bits & ~0b0000010000000000) | (vis << 10); }
void Block::setVisPosY(bool vis) { bits = (bits & ~0b0000100000000000) | (vis << 11); }
void Block::setVisPosZ(bool vis) { bits = (bits & ~0b0001000000000000) | (vis << 12); }
void Block::setVisNegX(bool vis) { bits = (bits & ~0b0010000000000000) | (vis << 13); }
void Block::setVisNegY(bool vis) { bits = (bits & ~0b0100000000000000) | (vis << 14); }
void Block::setVisNegZ(bool vis) { bits = (bits & ~0b1000000000000000) | (vis << 15); }

bool Block::getVisPosX() const { return (bits & 0b0000010000000000) >> 10; }
bool Block::getVisPosY() const { return (bits & 0b0000100000000000) >> 11; }
bool Block::getVisPosZ() const { return (bits & 0b0001000000000000) >> 12; }
bool Block::getVisNegX() const { return (bits & 0b0010000000000000) >> 13; }
bool Block::getVisNegY() const { return (bits & 0b0100000000000000) >> 14; }
bool Block::getVisNegZ() const { return (bits & 0b1000000000000000) >> 15; }

uint16_t Block::getType() const { return (bits & 0b0000001111111111) >> 0; }
uint16_t Block::getVis() const { return (bits & 0b1111110000000000) >> 10; }

bool Block::isSolid() const { return BlockType::types[getType()].isSolid(); }

void Block::setVisAll(bool posX, bool posY, bool posZ, bool negX, bool negY, bool negZ) {
  bits = (bits & ~0b1111110000000000) |
         (posX << 10) | (posY << 11) | (posZ << 12) |
         (negX << 13) | (negY << 14) | (negZ << 15);
}

#endif // !defined(BLOCK_C)