#ifndef __BOARD_GUARD__
#define __BOARD_GUARD__
#include "block.h"
#include "posn.h"
#include <string>
#include <iostream>
#include <string>
class Level;
class Score;
class Board{
	char **my_board;
	char **my_reserve;
	Block *ba [151];	//Array of the blocks pointers 
				//that are on the
				//board.
	
	int ba_max;		//		
	int lvl;
	Block *display_block;
	Level *my_level;
	Score *my_score;
	
	std::string filename;
	int LineFull(int n);
	public:
	Board(std::string name);
	void PutBlock();	//Puts the display Block to 
				//the board and gets a new
				//display block
	void GetDisplayBlock ();	//Gets a new display block
	void SetLevel(int i);	//Sets my_level to 
						//to ptr_to_lvl
	int Getlvl();		//Returns the current level so that
				//main can know what level we are on
        void up_level();
        void down_level();
	int GetScoreNum();
	void AddScore(int amt);
	void ClearBoard();
	void LineClear();
	void NotifyBlock(Block *blocky, Posn pos);
	void UpdateBoard();
	void DisplayBoard();
	void Welcome();
	//Void
	void Left();
	void Right();
	void Down();
	void Bottom();
	Posn Bottom(Posn pos);
	void CleanScore();

	
	void ClockWise();
	void CClockWise();
	~Board();
};
#endif
