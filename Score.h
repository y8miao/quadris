#ifndef __SCORE_GUARD__
#define __SCORE_GUARD__
#include <string>

class Score {
	int score_num; 	//This is our integery score value
	int high_scr;
	static Score *instance;	
	public:
	//The following is our pointer to instance, for the... 
	//...singleton pattern. 
	static Score *GetInstance ();
	
	Score(); //Constructor MAKE THIS LINE PRIVATE
	
	void AddScore (int amt); //Adds amt to score_num
	void SetScoreNum (int amt);
	static void cleanup(); 
	void CleanScore();
	
	int GetScoreNum();	//Returns score_num
	int GetHigh();	//Returns high_scr	
};
#endif
