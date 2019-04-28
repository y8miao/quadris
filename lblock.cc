#include <iostream>
#include "lblock.h"
using namespace std;
LBlock::LBlock(int n):first(Posn(4,0)),second(Posn(4,1)),third(Posn(4,2)),forth(Posn(3,2)){
  type = 'L';
  lvl = n;
  remain = 4;
}
Posn LBlock::First(){
  return first;
}
Posn LBlock::Second(){
  return second;
}
Posn LBlock::Third(){
  return third;
}
Posn LBlock::Forth(){
  return forth;
}
char LBlock::GetType(){
  return type;
}
void LBlock::SetFirst(Posn &p){
  first.x = p.x;
  first.y = p.y;
}
void LBlock::SetSecond(Posn &p){
  second.x = p.x;
  second.y = p.y;
}
void LBlock::SetThird(Posn &p){
  third.x = p.x;
  third.y = p.y;
}
void LBlock::SetForth(Posn &p){
  forth.x = p.x;
  forth.y = p.y;
}
void LBlock::notify(Posn &p){
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
int LBlock::GetLevel(){
  return lvl;
}
int LBlock:: Remain(){
  return remain;
}
int LBlock::BottomLeft(){
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
