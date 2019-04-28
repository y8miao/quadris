#ifndef __GUARD_OBLOCK__
#define __GUARD_OBLOCK__
#include "block.h"
class OBlock:public Block{
  Posn first, second, third, forth;
  public:
    OBlock(int n);
    Posn First();
    Posn Second();
    Posn Third();
    Posn Forth();
    void SetFirst(Posn &p);
    void SetSecond(Posn &p);
    void SetThird(Posn &p);
    void SetForth(Posn &p);
    char GetType();
    void notify(Posn &p);
    int BottomLeft();
    int GetLevel();
    int Remain();
};
#endif
