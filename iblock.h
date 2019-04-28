#ifndef __GUARD_IBLOCK__
#define __GUARD_IBLOCK__
#include "block.h"
class IBlock:public Block{
  Posn first, second, third, forth;
  public:
    IBlock(int n);
    Posn First();
    Posn Second();
    Posn Third();
    Posn Forth();
    void SetFirst(Posn &p);
    void SetSecond(Posn &p);
    void SetThird(Posn &p);
    void SetForth(Posn &p);
    void notify(Posn &p);
    char GetType();
    int GetLevel();
    int Remain();
    int BottomLeft();
};
#endif
