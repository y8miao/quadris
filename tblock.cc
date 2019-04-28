#include <iostream>
#include "tblock.h"
using namespace std;
TBlock::TBlock(int n):first(Posn(3,0)),second(Posn(3,1)),third(Posn(4,1)),forth(Posn(3,2)){
  type = 'T';
  lvl = n;
  remain = 4;
}
Posn TBlock::First(){
  return first;
}
Posn TBlock::Second(){
  return second;
}
Posn TBlock::Third(){
  return third;
}
Posn TBlock::Forth(){
  return forth;
}
char TBlock::GetType(){
  return type;
}
void TBlock::SetFirst(Posn &p){
  first.x = p.x;
  first.y = p.y;
}
void TBlock::SetSecond(Posn &p){
  second.x = p.x;
  second.y = p.y;
}
void TBlock::SetThird(Posn &p){
  third.x = p.x;
  third.y = p.y;
}
void TBlock::SetForth(Posn &p){
  forth.x = p.x;
  forth.y = p.y;
}
void TBlock::notify(Posn &p){
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
int TBlock::GetLevel(){
  return lvl;
}
int TBlock:: Remain(){
  return remain;
}
int TBlock::BottomLeft(){
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
