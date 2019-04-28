#ifndef __GUARD_LEVEL2__
#define __GUARD_LEVEL2__
#include "level.h"
class Block;
class Level2: public Level{
  public:
    int GetLevel();
    Block *CreateBlock();
};
#endif
