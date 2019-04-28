#include <iostream>
#include "sblock.h"
using namespace std;
SBlock::SBlock(int n):first(Posn(4,0)),second(Posn(4,1)),third(Posn(3,1)),forth(Posn(3,2)){
  type = 'S';
  lvl = n;
  remain = 4;
}
Posn SBlock::First(){
  return first;
}
Posn SBlock::Second(){
  return second;
}
Posn SBlock::Third(){
  return third;
}
Posn SBlock::Forth(){
  return forth;
}
char SBlock::GetType(){
  return type;
}
void SBlock::SetFirst(Posn &p){
  first.x = p.x;
  first.y = p.y;
}
void SBlock::SetSecond(Posn &p){
  second.x = p.x;
  second.y = p.y;
}
void SBlock::SetThird(Posn &p){
  third.x = p.x;
  third.y = p.y;
}
void SBlock::SetForth(Posn &p){
  forth.x = p.x;
  forth.y = p.y;
}
void SBlock::notify(Posn &p){
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
int SBlock::GetLevel(){
  return lvl;
}
int SBlock:: Remain(){
  return remain;
}
int SBlock::BottomLeft(){
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
