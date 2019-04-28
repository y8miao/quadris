#ifndef __GUARD_LEVEL3__
#define __GUARD_LEVEL3__
#include "level.h"
class Block;
class Level3: public Level{
  public:
    int GetLevel();
    Block *CreateBlock();
};
#endif
