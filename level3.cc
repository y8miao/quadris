#include <cstdlib>
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "level3.h"
int Level3::GetLevel(){
  return 3;
}
Block *Level3::CreateBlock(){
  int rng = 0;
  rng = rand();
  if(rng % 9 == 0){
    Block *bptr = new IBlock(3);
    return bptr;
  }
  else if(rng % 9 == 1){
    Block *bptr = new JBlock(3);
    return bptr;
  }
  else if(rng % 9 == 2){
    Block *bptr = new LBlock(3);
    return bptr;
  }
  else if(rng % 9 == 3){
    Block *bptr = new OBlock(3);
    return bptr;
  }
  else if(rng % 9 == 4 || rng % 9 == 5){
    Block *bptr = new SBlock(3);
    return bptr;
  }
  else if(rng % 9 == 6 || rng % 9 == 7){
    Block *bptr = new ZBlock(3);
    return bptr;
  }
  else{
    Block *bptr = new TBlock(3);
    return bptr;
  }
}
