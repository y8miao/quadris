#include <cstdlib>
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "level1.h"
int Level1::GetLevel(){
  return 1;
}
Block *Level1::CreateBlock(){
  int rng = 0;
  rng = rand();
  if(rng % 12 == 0 || rng % 12 == 1){
    Block *bptr = new IBlock(1);
    return bptr;
  }
  else if(rng % 12 == 2 || rng % 12 == 3){
    Block *bptr = new JBlock(1);
    return bptr;
  }
  else if(rng % 12 == 4 || rng % 12 == 5){
    Block *bptr = new LBlock(1);
    return bptr;
  }
  else if(rng % 12 == 6 || rng % 12 == 7){
    Block *bptr = new OBlock(1);
    return bptr;
  }
  else if(rng % 12 == 8){
    Block *bptr = new SBlock(1);
    return bptr;
  }
  else if(rng % 12 == 9){
    Block *bptr = new ZBlock(1);
    return bptr;
  }
  else{
    Block *bptr = new TBlock(1);
    return bptr;
  }
}
