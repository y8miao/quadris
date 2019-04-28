#include <iostream>
#include "iblock.h"
using namespace std;
IBlock::IBlock(int n):first(Posn(3,0)), second(Posn(3,1)),third(Posn(3,2)),forth(Posn(3,3)){
  type = 'I';
  lvl = n;
  remain = 4;
}
Posn IBlock::First(){
  return first;
}
Posn IBlock::Second(){
  return second;
}
Posn IBlock::Third(){
  return third;
}
Posn IBlock::Forth(){
  return forth;
}
char IBlock::GetType(){
  return type;
}
void IBlock::SetFirst(Posn &p){
  first.x = p.x;
  first.y = p.y;
}
void IBlock::SetSecond(Posn &p){
  second.x = p.x;
  second.y = p.y;
}
void IBlock::SetThird(Posn &p){
  third.x = p.x;
  third.y = p.y;
}
void IBlock::SetForth(Posn &p){
  forth.x = p.x;
  forth.y = p.y;
}
void IBlock::notify(Posn &p){
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
int IBlock::GetLevel(){
  return lvl;
}
int IBlock:: Remain(){
  return remain;
}
int IBlock:: BottomLeft(){
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
