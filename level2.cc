#include <cstdlib>
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "level2.h"
int Level2::GetLevel(){
  return 2;
}
Block *Level2::CreateBlock(){
  int rng = 0;
  rng = rand();
  if(rng % 7 == 0){
    Block *bptr = new IBlock(2);
    return bptr;
  }
  else if(rng % 7 == 1){
    Block *bptr = new JBlock(2);
    return bptr;
  }
  else if(rng % 7 == 2){
    Block *bptr = new LBlock(2);
    return bptr;
  }
  else if(rng % 7 == 3){
    Block *bptr = new OBlock(2);
    return bptr;
  }
  else if(rng % 7 == 4){
    Block *bptr = new SBlock(2);
    return bptr;
  }
  else if(rng % 7 == 5){
    Block *bptr = new ZBlock(2);
    return bptr;
  }
  else{
    Block *bptr = new TBlock(2);
    return bptr;
  }
}
