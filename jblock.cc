#include <iostream>
#include "jblock.h"
using namespace std;
JBlock::JBlock(int n):first(Posn(3, 0)),second(Posn(4,0)),third(Posn(4,1)),forth(Posn(4,2)){
  type = 'J';
  lvl = n;
  remain = 4;
}
Posn JBlock::First(){
  return first;
}
Posn JBlock::Second(){
  return second;
}
Posn JBlock::Third(){
  return third;
}
Posn JBlock::Forth(){
  return forth;
}
char JBlock::GetType(){
  return type;
}
void JBlock::SetFirst(Posn &p){
  first.x = p.x;
  first.y = p.y;
}
void JBlock::SetSecond(Posn &p){
  second.x = p.x;
  second.y = p.y;
}
void JBlock::SetThird(Posn &p){
  third.x = p.x;
  third.y = p.y;
}
void JBlock::SetForth(Posn &p){
  forth.x = p.x;
  forth.y = p.y;
}
void JBlock::notify(Posn &p){
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
int JBlock::GetLevel(){
  return lvl;
}
int JBlock:: Remain(){
  return remain;
}
int JBlock::BottomLeft(){
  if(first.x == (second.x - 1)){
    return 1;
  }
  else if(first.y == (second.y + 1)){
    return 2;
  }
  else if(first.x == (second.x + 1)){
    return 3;
  }
  else{
    return 4;
  }
}
