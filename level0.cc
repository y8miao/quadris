#include <fstream>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "level0.h"
using namespace std;
Level0::Level0(string str):f(str.c_str()){
  fname = str;
}
int Level0::GetLevel(){
  return 0;
}
Block *Level0::CreateBlock(){
  char ch;
  if(f>>ch){
    if(ch == 'I'){
      Block *bptr = new IBlock(0);
      return bptr;
    }
    else if(ch == 'J'){
      Block *bptr = new JBlock(0);
      return bptr;
    }
    else if(ch == 'L'){
      Block *bptr = new LBlock(0);
      return bptr;
    }
    else if(ch == 'O'){
      Block *bptr = new OBlock(0);
      return bptr;
    }
    else if(ch == 'S'){
      Block *bptr = new SBlock(0);
      return bptr;
    }
    else if(ch == 'T'){
      Block *bptr = new TBlock(0);
      return bptr;
    }
    else{
      Block *bptr = new ZBlock(0);
      return bptr;
    }
  }
  else{
    f.close();
    f.open(fname.c_str());
    return CreateBlock();
  }
}
