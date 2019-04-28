#ifndef __GUARD_JBLOCK__
#define __GUARD_JBLOCK__
#include "block.h"
class JBlock:public Block{
  Posn first, second, third, forth;
  public:
    JBlock(int n);
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
