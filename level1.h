#ifndef __GUARD_LEVEL1__
#define __GUARD_LEVEL1__
#include "level.h"
class Block;
class Level1: public Level{
  public:
    int GetLevel();
    Block *CreateBlock();
};
#endif
