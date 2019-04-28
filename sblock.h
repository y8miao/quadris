#ifndef __GUARD_SBLOCK__
#define __GUARD_SBLOCK__
#include "block.h"
class SBlock:public Block{
  Posn first, second, third, forth;
  public:
    SBlock(int n);
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
    int GetLevel();
    int Remain();
    int BottomLeft();
};
#endif
