#ifndef __GUARD_BLOCK__
#define __GUARD_BLOCK__
#include "posn.h"
class Block{
  protected:
    char type;
    int lvl;
    int remain;
  public:
    virtual Posn First() = 0;
    virtual Posn Second() = 0;
    virtual Posn Third() = 0;
    virtual Posn Forth() = 0;
    virtual void SetFirst(Posn &p)=0;
    virtual void SetSecond(Posn &p)=0;
    virtual void SetThird(Posn &p)=0;
    virtual void SetForth(Posn &p)=0;
    virtual ~Block()= 0;
    virtual char GetType()=0;
    virtual void notify(Posn &p) = 0;
    virtual int Remain()=0;
    virtual int GetLevel()=0;
    virtual int BottomLeft()=0;
};
#endif
