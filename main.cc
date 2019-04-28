#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Board.h"
#include "Score.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
using namespace std;

int main(int num_items, char *cmd_array[]){
	bool done = false;
	/*Board();
	SetLevel(0);
	GetScoreNum();
	GetDisplayBlock();
	PutBlock();
	UpdateBoard();*/
	
	int new_level_num = 0;
	string new_scriptfile = "sequence.txt";
	unsigned int seed = 1; 
	bool show_graphics = 1;
	string first_input;

	for (int i=1; i <num_items; i++){
		string Inputy;
		Inputy = cmd_array[i];
		if (Inputy == "-startlevel"){
				i++;
				string s = cmd_array[i];
				istringstream ss(s);
				ss>>new_level_num;
				//Board.SetLevel(new_level_num);	
			}
			else if (Inputy == "-scriptfile"){
				i++;
				new_scriptfile = cmd_array[i];
				//WE NEED TO CHANGE SCRIPTFILE
			}
			else if (Inputy == "-seed"){
				i++;
				string s = cmd_array[i];
                                istringstream ss(s);
				ss>>seed;
			}
			else if (Inputy =="-text"){
				show_graphics = 0;	
			}
			else {
				//continue;
				break;
			}
		
	}	
	
	srand(seed);

	Board *new_board = new Board(new_scriptfile);
        new_board->SetLevel(new_level_num);
        new_board->GetScoreNum();
        new_board->GetDisplayBlock();
        new_board->PutBlock();
        new_board->UpdateBoard();		
	
	new_board->Welcome();
	while (cin>>first_input){
		if (first_input == "go"){
			break;
		}
		else if (first_input == "Go"){
			break;
		}
		else{
			continue;
		}
	}

	new_board->DisplayBoard();

	
	while(!done){
		if (cin.eof()) break;
		//new_board.DisplayBoard();
		string Input;
		string Input_backup;
		cin >> Input;
		Input_backup = Input;
		char ch;
		istringstream ss(Input_backup);
		ss >> ch;
		
			if (Input == "quit"){
				done = true;
			}

			if (ch == 'c'){
				ss>>ch;
				if (ch == 'l'){
					//clockwise
					new_board->ClockWise();
                	                new_board->UpdateBoard();
        	                        new_board->DisplayBoard();
	
				}
				if (ch == 'o'){
					//counterclockwise
					new_board->CClockWise();
        	                        new_board->UpdateBoard();
	                                new_board->DisplayBoard();

				}
			}

			if (ch == 'd'){
				ss>>ch;
				if (ch == 'o'){
					//down
					new_board->Down();
                                                new_board->UpdateBoard();
                                                new_board->DisplayBoard();
				}
				if (ch == 'r'){
					//drop
					new_board->Bottom();
	                                new_board->LineClear();
        	                        new_board->UpdateBoard();
                	                new_board->PutBlock();
                                	//new_board->LineClear();
                        	        new_board->UpdateBoard();
                                	new_board->DisplayBoard();
		
				}
				
			}
			if (ch == 'r'){
				ss>>ch;
				if (ch == 'i'){
					//right
					new_board->Right();
                                                new_board->UpdateBoard();
                                                new_board->DisplayBoard();
				}
				if (ch == 'e'){
					//restart
					new_board->ClearBoard();
                                new_board->CleanScore();
                                delete new_board;

                                new_board= new Board(new_scriptfile);
                                //new_board.SetLevel(new_level_num);
                                //new_board.S

                        //new_board.GetScoreNum();
                                //new_board.GetDisplayBlock();
                                //new_board.PutBlock();
                                //new_board.UpdateBoard();
                                //new_board.DisplayBoard();


                                new_level_num = 0;
                                new_board->SetLevel(0);
                                new_board->GetScoreNum();
                                new_board->GetDisplayBlock();
                                new_board->PutBlock();


                                new_board->UpdateBoard();
                                new_board->DisplayBoard();

				}
			}
			if (ch == 'l'){
				ss>>ch;
				ss>>ch;
				if (ch == 'f'){
					//left
					new_board->Left();
                                        new_board->UpdateBoard();
                                        new_board->DisplayBoard();

				}
				if (ch == 'v'){
					ss>>ch;
					ss>>ch;
					ss>>ch;
					if (ch == 'u'){
						//levelup
						 if(new_level_num !=3){
                                                                new_level_num++;
                                                                new_board->SetLevel(new_level_num);
                                                             }
                                                                new_board->UpdateBoard();
                                                                new_board->DisplayBoard();
					}
					if (ch == 'd'){
						//leveldown
						if(new_level_num != 0){
                                                                new_level_num--;
                                                                new_board->SetLevel(new_level_num);
                                                             }
                                                                new_board->UpdateBoard();
                                                                new_board->DisplayBoard();
					}
				}
			}
			if ((ch >= '0')&&(ch <='9')){
				int n;
				n= ch - '0';
				ss >> ch;
				
					if (ch == 'l'){
						ss>>ch;
						ss>>ch;
						if (ch == 'f'){
						  for (int z1 = 0; z1<n; z1++){
							new_board->Left();
        		                        	new_board->UpdateBoard();
	                	                	new_board->DisplayBoard();
						  }
						}
						else{
							ss>>ch;
							ss>>ch;
							ss>>ch;
							if (ch == 'u'){
							  for (int z2 = 0; z2<n; z2++){
								/*new_board.up_level();
                                				new_board.Getlvl(); */
							     if(new_level_num !=3){	
								new_level_num++;
								new_board->SetLevel(new_level_num);
                                			     }	
								new_board->UpdateBoard();
                                				new_board->DisplayBoard();
							  }
							}
							if (ch == 'd'){
							  for (int z3 = 0; z3<n; z3++){
								/*new_board.down_level();
				                                new_board.Getlvl(); */
							     if(new_level_num != 0){	
								new_level_num--;
								new_board->SetLevel(new_level_num);
                                			     }	
								new_board->UpdateBoard();
                               					new_board->DisplayBoard();
							  }
							}
						}
					}
					else if (ch == 'r'){
					  for (int z4 = 0; z4<n; z4++){
						new_board->Right();
                        		        new_board->UpdateBoard();
                	               		new_board->DisplayBoard();
					  }
					}
					else if (ch == 'd'){
					  for (int z5 = 0; z5<n; z5++){
						new_board->Down();
                                		new_board->UpdateBoard();
                                		new_board->DisplayBoard();
					  }
					}
				
			}
	/*	
			else if (Input == "left"){
				new_board->Left();
				new_board->UpdateBoard();
				new_board->DisplayBoard();
			}
			else if (Input == "right"){
				new_board->Right();
				new_board->UpdateBoard();
				new_board->DisplayBoard();
			}
			else if (Input == "down"){
				new_board->Down();
				new_board->UpdateBoard();
				new_board->DisplayBoard();
			}

			else if (Input =="clockwise"){
				new_board->ClockWise();
				new_board->UpdateBoard();
				new_board->DisplayBoard();
			}
			else if (Input =="counterclockwise"){
				new_board->CClockWise();
				new_board->UpdateBoard();
				new_board->DisplayBoard();
			}

			else if (Input =="drop"){
				new_board->Bottom();
				new_board->LineClear();
				new_board->UpdateBoard();
				new_board->PutBlock();
				//new_board->LineClear();
				new_board->UpdateBoard();
				new_board->DisplayBoard();
			}
			else if (Input =="levelup"){
				//new_board.up_level();
				//new_board.Getlvl();
			   if(new_level_num != 3){
				new_level_num++;
                                new_board->SetLevel(new_level_num);
			   }
				new_board->UpdateBoard();
				new_board->DisplayBoard();
			}
			else if (Input =="leveldown"){
				//new_board.down_level();
				//new_board.Getlvl(); 
			   if(new_level_num != 0){	
				new_level_num--;
                                new_board->SetLevel(new_level_num);
			   }
				new_board->UpdateBoard();
				new_board->DisplayBoard();
			}
			else if (Input =="restart"){
				new_board->ClearBoard();
				new_board->CleanScore();
				delete new_board;
				
				new_board= new Board(new_scriptfile);
			        //new_board.SetLevel(new_level_num);
			        //new_board.S 
				
			//new_board.GetScoreNum();
			        //new_board.GetDisplayBlock();
			        //new_board.PutBlock();
			        //new_board.UpdateBoard();
			        //new_board.DisplayBoard();


				new_level_num = 0;
				new_board->SetLevel(0);
				new_board->GetScoreNum();
				new_board->GetDisplayBlock();
                                new_board->PutBlock();


				new_board->UpdateBoard();
				new_board->DisplayBoard();
			}*/
			else{
				continue;
			}
		}
	return 0;
}


