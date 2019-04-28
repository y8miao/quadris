#include <iostream>
#include "oblock.h"
using namespace std;
OBlock::OBlock(int n):first(Posn(3,0)),second(Posn(4,0)),third(Posn(4,1)),forth(Posn(3,1)){
  type = 'O';
  lvl = n;
  remain = 4;
}
Posn OBlock::First(){
  return first;
}
Posn OBlock::Second(){
  return second;
}
Posn OBlock::Third(){
  return third;
}
Posn OBlock::Forth(){
  return forth;
}
char OBlock::GetType(){
  return type;
}
void OBlock::SetFirst(Posn &p){
  first.x = p.x;
  first.y = p.y;
}
void OBlock::SetSecond(Posn &p){
  second.x = p.x;
  second.y = p.y;
}
void OBlock::SetThird(Posn &p){
  third.x = p.x;
  third.y = p.y;
}
void OBlock::SetForth(Posn &p){
  forth.x = p.x;
  forth.y = p.y;
}
void OBlock::notify(Posn &p){
  if(first.x == p.x && first.y == p.y){
    first.x = -1;
    first.y = -1;
  }
  else if(second.x == p.x && second.y == p.y){
    second.x = -1;
    second.y = -1;
  }
  else if(third.x == p.x && third.y == p.y){
    third.x = -1;
    third.y = -1;
  }
  else if(forth.x == p.x && forth.y == p.y){
    forth.x = -1;
    forth.y = -1;
  }
  else{
    cerr<<"wrong block called!"<<endl;
  }
  remain--;
}
int OBlock::BottomLeft(){
  return 0;
}
int OBlock::GetLevel(){
  return lvl;
}
int OBlock:: Remain(){
  return remain;
}
