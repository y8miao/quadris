#ifndef __GUARD_LBLOCK__
#define __GUARD_LBLOCK__
#include "block.h"
class LBlock:public Block{
  Posn first, second, third, forth;
  public:
    LBlock(int n);
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
