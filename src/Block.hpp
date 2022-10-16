#if !defined(BLOCK_H)
#define BLOCK_H

#include <stdint.h>

#include "BlockType.hpp"

struct BlockType;

struct Block {
  public:
    Block();
    Block(uint16_t);
    Block(const Block&);

    friend bool operator==(const Block&, const Block&);
    friend bool operator==(const Block&, uint16_t);

    void setVisPosX(bool);
    void setVisPosY(bool);
    void setVisPosZ(bool);
    void setVisNegX(bool);
    void setVisNegY(bool);
    void setVisNegZ(bool);

    bool getVisPosX() const;
    bool getVisPosY() const;
    bool getVisPosZ() const;
    bool getVisNegX() const;
    bool getVisNegY() const;
    bool getVisNegZ() const;

    uint16_t getType() const;
    uint16_t getVis() const;
    
    bool isSolid() const;

    void setVisAll(bool, bool, bool, bool, bool, bool);

  private:
    uint16_t bits;
};

#endif // !defined(BLOCK_H)