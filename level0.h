#ifndef __GUARD_LEVEL0__
#define __GUARD_LEVEL0__
#include <fstream>
#include <string>
#include "level.h"
class Level0: public Level{
    std::string fname;
    std::ifstream f;
  public:
    Level0(std::string str);
    int GetLevel();
    Block *CreateBlock();
};

#endif
