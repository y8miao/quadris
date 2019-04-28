#include <iostream>
#include "zblock.h"
using namespace std;
ZBlock::ZBlock(int n):first(Posn(3,0)),second(Posn(3,1)),third(Posn(4,1)),forth(Posn(4,2)){
  type = 'Z';
  lvl = n;
  remain = 4;
}
Posn ZBlock::First(){
  return first;
}
Posn ZBlock::Second(){
  return second;
}
Posn ZBlock::Third(){
  return third;
}
Posn ZBlock::Forth(){
  return forth;
}
char ZBlock::GetType(){
  return type;
}
void ZBlock::SetFirst(Posn &p){
  first.x = p.x;
  first.y = p.y;
}
void ZBlock::SetSecond(Posn &p){
  second.x = p.x;
  second.y = p.y;
}
void ZBlock::SetThird(Posn &p){
  third.x = p.x;
  third.y = p.y;
}
void ZBlock::SetForth(Posn &p){
  forth.x = p.x;
  forth.y = p.y;
}
void ZBlock::notify(Posn &p){
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
int ZBlock::GetLevel(){
  return lvl;
}
int ZBlock:: Remain(){
  return remain;
}
int ZBlock::BottomLeft(){
  if(first.y == (second.y - 1)){
    return 1;
  }
  else if(first.x == (second.x - 1)){
    return 2;
  }
  else if(first.y == (second.y + 1)){
    return 3;
  }
  else{
    return 4;
  }
}
