#include "Score.h"
#include <string>
#include <cstdlib>
Score *Score:: instance = 0;

Score *Score:: GetInstance (){
	if (!instance){
		instance = new Score;
		atexit(cleanup);
	}
	return instance;
}

Score:: Score(): score_num (0), high_scr(0) {}

void Score:: AddScore(int amt){score_num += amt;}
void Score:: SetScoreNum(int amt){score_num = amt;} 

void Score:: cleanup(){
	delete instance;
}
void Score::CleanScore(){
	score_num = 0;
	high_scr = 0;
}


int Score:: GetScoreNum(){
	return score_num;
}

int Score:: GetHigh(){
	return high_scr;
} 
