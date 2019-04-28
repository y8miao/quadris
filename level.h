#ifndef __GUARD_LEVEL__
#define __GUARD_LEVEL__
class Block;
class Level{
  
  public:
  virtual int GetLevel() =0;
  virtual Block *CreateBlock()=0;
  virtual ~Level()=0;
};
#endif
