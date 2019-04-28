#include "Board.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "Score.h"
#include <string>
using namespace std;
Board::Board(string name = "sequence.txt"){
	int i = 0, j = 0;
	ba_max = 0;
	lvl = 0;
//initialize my board
	my_board = new char *[18];
	for (int z=0; z<18; z++){
		my_board[z] = new char[10];
	}
	for(i = 0; i < 18; i++){
		for(j = 0; j < 10; j++){
			my_board[i][j] = ' ';
		}
	}
//initialize my reserve
	my_reserve = new char *[3];
	for (int g=0; g<3; g++){
		my_reserve[g] = new char[10];
	}
	for (int k=0; k<3; k++){
		for (int m=0; m<10; m++){
			my_reserve[k][m] = ' ';
		}
	}

	for (int x=0; x<151; x++){
		ba[x] = NULL;
	}
	my_level = NULL;
	my_score = Score::GetInstance();
	display_block = NULL;
	//GetDisplayBlock();
	//PutBlock();
	filename = name;
}

void Board::CleanScore(){
	my_score->CleanScore();
}


Board::~Board(){
	int i = 0;
	for(i = 0; i < 18; i++){
          delete [] my_board[i];
        }
	delete [] my_board;
	i = 0;
	for(i = 0; i < 3; i++){
          delete [] my_reserve[i];
        }
        delete [] my_reserve;

	if(my_level == NULL){}
        else{
          delete my_level;
        }
	
	for (int z=0; z<ba_max; z++){
		delete ba[z];
	}
	ba_max = 0;
}

void Board::PutBlock(){
	ba[ba_max] = display_block;
	ba_max++;
	GetDisplayBlock();
}

void Board::GetDisplayBlock(){
	display_block = my_level->CreateBlock();
}


void Board:: SetLevel (int i){
	lvl = i;
        if(my_level == NULL){}
        else{
          delete my_level;
        }
	if (i==0){
		my_level = new Level0(filename);
	}
	else if (i==1){
		 my_level = new Level1;
	}
	else if (i==2){
                 my_level = new Level2;
        }
	else if (i==3){
                 my_level = new Level3;
        }

}

/*void SetLevel(Level *ptr_to_lvl){
	my_level = ptr_to_lvl;
}*/

int Board:: Getlvl(){
	return lvl;
}

void Board::up_level(){
	lvl++;
	
}

void Board::down_level(){
	lvl--;
}
int Board:: GetScoreNum(){
	return my_score->GetScoreNum();
}

void Board:: AddScore(int amt){
	my_score->AddScore(amt);
}

void Board:: NotifyBlock(Block *blocky, Posn pos){
	blocky->notify(pos);	
}

void Board:: UpdateBoard(){
	int i = 0, j = 0;
	int i2 = 0, j2 = 0;
	int ba_c = 0;
	//Block *b = NULL;

	for(i2 = 0; i2 < 18; i2++){
                for(j2 = 0; j2 < 10; j2++){
                        my_board[i2][j2] = ' ';
                }
        }


	for (ba_c = 0; ba_c < ba_max; ba_c++){
			Block *bptr = ba[ba_c];	
			if ((bptr->First()).x != -1){
				my_board[(bptr->First()).x][(bptr->First()).y] = bptr->GetType();
			}
			if ((bptr->Second()).x != -1){
                        	my_board[(bptr->Second()).x][(bptr->Second()).y] = bptr->GetType();
                        }
			if ((bptr->Third()).x != -1){
                        	my_board[(bptr->Third()).x][(bptr->Third()).y] = bptr->GetType();
                        }
			if ((bptr->Forth()).x != -1){
                        	my_board[(bptr->Forth()).x][(bptr->Forth()).y] = bptr->GetType();
                        }
	}	
}
void Board:: Welcome(){
	cout << "+----------+" << endl;
/*01*/	cout << "|      L   |" << endl;
/*02*/  cout << "|OO    LLL |" << endl;
/*03*/	cout << "|OO        |" << endl;
/*04*/  cout << "|----------|" << endl;
/*05*/	cout << "|welcome   |" << endl;
/*06*/  cout << "|    to    |" << endl;
/*07*/	cout << "|   quadris|" << endl;
/*08*/  cout << "|----------|" << endl;
/*09*/	cout << "|      TTT |" << endl;
/*10*/  cout << "|  I    T  |" << endl;
/*11*/	cout << "|  I       |" << endl;
/*12*/  cout << "|  I       |" << endl;
/*13*/	cout << "|  I    ZZ |" << endl;
/*14*/  cout << "|        ZZ|" << endl;
/*15*/	cout << "|          |" << endl;
/*16*/  cout << "| (input:  |" << endl;
/*17*/	cout << "|      go) |" << endl;
/*18*/  cout << "|          |" << endl;
        cout << "+----------+" << endl;

}
void Board:: DisplayBoard(){
	//PRINT HEADER
	cout << "Level:    " << my_level->GetLevel() <<endl;
	cout << "Score:    " << my_score->GetScoreNum() <<endl;
	cout << "Hi Score: " << my_score->GetHigh() << endl;
	cout << "----------" << endl;
		
	//PRINT RESERVE
/*	for(int k = 0; k < 3; k++){
                for(int m = 0; m < 10; m++){
                        cout << my_reserve[k][m];
                }
                cout << endl;
        }
*/
	//PRINT BODY
	for(int i = 0; i < 18; i++){
                for(int j = 0; j < 10; j++){
                        cout << my_board[i][j];
                }
		cout << endl;
        }

	//PRINT BOTTOM (WHICH DISPLAYS THE NEXT BLOCK TYPE)
	cout << "----------" << endl;
	cout << "Next:" << endl;
	
	if (display_block->GetType() == 'I'){
	cout << "IIII" << endl;
	}
	if (display_block->GetType() == 'J'){
	cout << "J  " << endl;
	cout << "JJJ" << endl;
	}
	if (display_block->GetType() == 'L'){
        cout << "  L" << endl;
        cout << "LLL" << endl;
        }
	if (display_block->GetType() == 'O'){
        cout << "OO" << endl;
        cout << "OO" << endl;
        }
	if (display_block->GetType() == 'S'){
        cout << " SS" << endl;
        cout << "SS " << endl;
        }
	if (display_block->GetType() == 'Z'){
        cout << "ZZ " << endl;
        cout << " ZZ" << endl;
        }
	if (display_block->GetType() == 'T'){
        cout << "TTT" << endl;
        cout << " T " << endl;
        }
	
/*	cout << "Ba_max: " << ba_max << endl;
	Block *bptr = ba[ba_max-1];
	cout << "Current piece first: " << bptr->First().x <<
	"," << bptr->First().y << endl;
*/	
}

void Board:: Left(){
  Block *bptr = ba[ba_max-1];
int orient = bptr->BottomLeft();

if ((bptr->GetType() == 'I')){
        if (orient == 1){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')//&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        //(my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        (//(my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}


if ((bptr->GetType() == 'J')){
        if (orient == 1){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        //(my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        (//(my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}
if ((bptr->GetType() == 'L')){
        if (orient == 1){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')
                        //(my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        (//(my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}
if ((bptr->GetType() == 'S')){
        if (orient == 1){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')//&&
                        //(my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        (//(my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}

if ((bptr->GetType() == 'Z')){
        if (orient == 1){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')//&&
                        //(my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        (//(my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}
if ((bptr->GetType() == 'T')){
        if (orient == 1){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')//&&
                        //(my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        (//(my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        //(my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        (my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        (my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}


if ((bptr->GetType() == 'O')){
                if (  ((((bptr->First()).y != 0) &&
                        ((bptr->Second()).y != 0) &&
                        ((bptr->Third()).y != 0) &&
                        ((bptr->Forth()).y != 0))
                        &&
                        ((my_board[((bptr->First()).x)] [((bptr->First()).y)-1] == ' ')&&
                        (my_board[((bptr->Second()).x)] [((bptr->Second()).y)-1] == ' ')//&&
                        //(my_board[((bptr->Third()).x)] [((bptr->Third()).y)-1] == ' ')&&
                        //(my_board[((bptr->Forth()).x)] [((bptr->Forth()).y)-1] == ' ')
                        ))
                        ) {

                        //MOVE PIECE LEFT BY 1
                        Posn pos1((((bptr->First()).x)), ((bptr->First()).y)-1);
                        Posn pos2((((bptr->Second()).x)), ((bptr->Second()).y)-1);
                        Posn pos3((((bptr->Third()).x)), ((bptr->Third()).y)-1);
                        Posn pos4((((bptr->Forth()).x)), ((bptr->Forth()).y)-1);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
}	
}

void Board:: Right(){
  Block *bptr = ba[ba_max-1];
  if(bptr->GetType() == 'I'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos3.y += 1;
        pos2.y += 1;
        pos1.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'J'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos3.y += 1;
        pos2.y += 1;
        pos1.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.y == 9)
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'L'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos3.y += 1;
        pos2.y += 1;
        pos1.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.y == 9)
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'S'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos3.y += 1;
        pos2.y += 1;
        pos1.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'Z'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos3.y += 1;
        pos2.y += 1;
        pos1.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'T'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos3.y += 1;
        pos2.y += 1;
        pos1.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.y += 1;
        pos3.y += 1;
        pos4.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
  }
}

void Board:: Down(){
        int flaggy = 0;
        Block *bptr = ba[ba_max-1];
        int orient = bptr->BottomLeft();
	
if ((bptr->GetType() == 'I')){
	if ((orient == 1) /*|| (orient == 3)*/){
        	if (  ((((bptr->First()).x != 17) &&
                	((bptr->Second()).x != 17) &&
                	((bptr->Third()).x != 17) &&
                	((bptr->Forth()).x != 17))
			&&
			((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
			(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
			(my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
			(my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
			))
                	) {

			//MOVE PIECE DOWN BY 1
                	Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                	Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                	Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                	Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                	bptr->SetFirst(pos1);	
                	bptr->SetSecond(pos2);
                	bptr->SetThird(pos3);
                	bptr->SetForth(pos4);
        	}
	}
	if (orient == 2){
		if (  ((((bptr->First()).x != 17) &&
        	                ((bptr->Second()).x != 17) &&
                	        ((bptr->Third()).x != 17) &&
                        	((bptr->Forth()).x != 17))
                       		&&
				(my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' '))){
				
        	                //MOVE PIECE DOWN BY 1
	                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
  	                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                                Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                  	        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        	bptr->SetFirst(pos1);
	                        bptr->SetSecond(pos2);
        	                bptr->SetThird(pos3);
	                        bptr->SetForth(pos4);
		}	
	}

	if (orient == 3){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
		}
        }


	if (orient == 4){
		if (  ((((bptr->First()).x != 17) &&
                                ((bptr->Second()).x != 17) &&
                                ((bptr->Third()).x != 17) &&
                                ((bptr->Forth()).x != 17))
                                &&
				((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')))){
				//MOVE PIECE DOWN BY 1
                                Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                                Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                                Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                                Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                                bptr->SetFirst(pos1);
                                bptr->SetSecond(pos2);
                                bptr->SetThird(pos3);
                                bptr->SetForth(pos4);
		}
	}
}

if ((bptr->GetType() == 'J')){
	if (orient == 1){
		if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        (
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

	}
	if (orient == 2){
		if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

	}
	if (orient == 3){
		if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

	}
	if (orient == 4){
		if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	
	}
}

if ((bptr->GetType() == 'L')){
        if (orient == 1){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')
                        
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        (//(my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        //(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        //(my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        //(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        //(my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}

if ((bptr->GetType() == 'S')){
        if (orient == 1){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        //(my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        (//(my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        //(my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        //(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        //(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')
                        //(my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}

if ((bptr->GetType() == 'Z')){
        if (orient == 1){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        //(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        (//(my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        //(my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        //(my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        //(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')
                        //(my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}

if ((bptr->GetType() == 'T')){
        if (orient == 1){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        //(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 2){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        (//(my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        //(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }
	}
	if (orient == 3){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        //(my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')&&
                        (my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
        if (orient == 4){
                if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        ((my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        //(my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')
                        //(my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

        }
}

if ((bptr->GetType() == 'O')){
               if (  ((((bptr->First()).x != 17) &&
                        ((bptr->Second()).x != 17) &&
                        ((bptr->Third()).x != 17) &&
                        ((bptr->Forth()).x != 17))
                        &&
                        (//(my_board[((bptr->First()).x)+1] [((bptr->First()).y)] == ' ')&&
                        (my_board[((bptr->Second()).x)+1] [((bptr->Second()).y)] == ' ')&&
                        (my_board[((bptr->Third()).x)+1] [((bptr->Third()).y)] == ' ')
                        //(my_board[((bptr->Forth()).x)+1] [((bptr->Forth()).y)] == ' ')
                        ))
                        ) {

                        //MOVE PIECE DOWN BY 1
                        Posn pos1((((bptr->First()).x) + 1), (bptr->First()).y);
                        Posn pos2((((bptr->Second()).x) + 1), (bptr->Second()).y);
                        Posn pos3((((bptr->Third()).x) + 1), (bptr->Third()).y);
                        Posn pos4((((bptr->Forth()).x) +1), (bptr->Forth()).y);

                        bptr->SetFirst(pos1);
                        bptr->SetSecond(pos2);
                        bptr->SetThird(pos3);
                        bptr->SetForth(pos4);
                }

}



// End of down
}
void Board:: Bottom(){
	for (int i = 0; i<18; i++){
	Down();
	UpdateBoard();
	}
}

Posn Board::Bottom(Posn pos){
	Posn n_pos = pos;
	n_pos.x += 1;
	return n_pos;
}

int Board::LineFull(int n){
  int j = 0;
  for(j = 0; j < 10; j++){
    if(my_board[n][j] == ' '){
      return 0;
    }
    else continue;
  }
  return 1;
}

void Board::ClearBoard(){
        //Make everything on the board space
	for(int i = 0; i < 18; i++){
                for(int j = 0; j < 10; j++){
                        my_board[i][j] = ' ';
                }
        }
	for (int i = 0; i<ba_max ; i++){
		delete ba[i];
	}
	
	ba_max = 0;
	ba[ba_max]=NULL;
		
}

void Board::LineClear(){
  int numLine = 0, numScore = 0;
  int i = 0, j = 0, k = 0, l = 0, m = 0;
  for(i = 17; i > 2; i--){
    if(LineFull(i)){
      numLine++;
      for(j = 0; j < 10; j++){
        for(k = 0; k < ba_max; k++){
          Block * bptr = ba[k];
          if((bptr->First()).x == i && (bptr->First()).y == j){
            Posn p(i, j);
            bptr->notify(p);
            UpdateBoard();
            if((bptr->Remain()) == 0){
              numScore += ((bptr->GetLevel())+1) * ((bptr->GetLevel())+1);
              delete ba[k];
              int posi = 0;
              for(posi = k; posi < ba_max-1; posi++){
                ba[posi] = ba[posi+1];
              }
              ba_max--;
            }
            else {}
          }
          else if((bptr->Second()).x == i && (bptr->Second()).y == j){
            Posn p(i, j);
            bptr->notify(p);
            UpdateBoard();
            if((bptr->Remain()) == 0){
              numScore += ((bptr->GetLevel())+1) * ((bptr->GetLevel())+1);
              delete ba[k];
              int posi = 0;
              for(posi = k; posi < ba_max-1; posi++){
                ba[posi] = ba[posi+1];
              }
              ba_max--;
            }
            else {}
          }
          else if((bptr->Third()).x == i && (bptr->Third()).y == j){
            Posn p(i, j);
            bptr->notify(p);
            UpdateBoard();
            if((bptr->Remain()) == 0){
              numScore += ((bptr->GetLevel())+1) * ((bptr->GetLevel())+1);
              delete ba[k];
              int posi = 0;
              for(posi = k; posi < ba_max-1; posi++){
                ba[posi] = ba[posi+1];
              }
              ba_max--;
            }
            else {}
          }
          else if((bptr->Forth()).x == i && (bptr->Forth()).y == j){
            Posn p(i, j);
            bptr->notify(p);
            UpdateBoard();
            if((bptr->Remain()) == 0){
              numScore += ((bptr->GetLevel())+1) * ((bptr->GetLevel())+1);
              delete ba[k];
              int posi = 0;
              for(posi = k; posi < ba_max-1; posi++){
                ba[posi] = ba[posi+1];
              }
              ba_max--;
            }
            else {}
          }
        }
      }
      if(i == 3){}
      else{
        for(l = i - 1; l > -1; l--){
          for(j = 0; j < 10; j++){
            for(m = 0; m < ba_max; m++){
              Block * bptr = ba[m];
              if((bptr->First()).x == l && (bptr->First()).y == j){
                Posn p(l, j);
                p = Bottom(p);
                bptr->SetFirst(p);
              }
              else if((bptr->Second()).x == l && (bptr->Second()).y == j){
                Posn p(l, j);
                p = Bottom(p);
                bptr->SetSecond(p);
              }
              else if((bptr->Third()).x == l && (bptr->Third()).y == j){
                Posn p(l, j);
                p = Bottom(p);
                bptr->SetThird(p);
              }
              else if((bptr->Forth()).x == l && (bptr->Forth()).y == j){
                Posn p(l, j);
                p = Bottom(p);
                bptr->SetForth(p);
              }
              else continue;
            }
          }
        }
      UpdateBoard();
      }
    i++;
    }
  }
  if(numLine == 0){}
  else{
    numScore += (lvl+numLine) * (lvl+numLine);
  }
  AddScore(numScore);
}

//begin
void Board::ClockWise(){
  Block *bptr = ba[ba_max-1];
  if(bptr->GetType() == 'I'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.x == 0)
         ||(pos1.x == 1)
         ||(pos1.x == 2)
         ||(my_board[(pos1.x - 3)][pos1.y] != ' ')
         ||(my_board[(pos1.x-2)][pos1.y] != ' ')
         ||(my_board[(pos1.x-1)][pos1.y] != ' ')){
        return;
      }
      else{
        pos1.x -= 3;
        pos2.x -= 2;
        pos2.y -= 1;
        pos3.x -= 1;
        pos3.y -= 2;
        pos4.y -= 3;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y+3 > 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+2)] != ' ')
         ||(my_board[pos4.x][(pos4.y+3)] != ' ')){
        return;
      }
      else{
        pos1.x += 3;
        pos1.y += 3;
        pos2.x += 2;
        pos2.y += 2;
        pos3.x += 1;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.x == 0)
         ||(pos4.x == 1)
         ||(pos4.x == 2)
         ||(my_board[(pos4.x - 3)][pos4.y] != ' ')
         ||(my_board[(pos4.x-2)][pos4.y] != ' ')
         ||(my_board[(pos4.x-1)][pos4.y] != ' ')){
        return;
      }
      else{
        pos4.x -= 3;
        pos3.x -= 2;
        pos3.y -= 1;
        pos2.x -= 1;
        pos2.y -= 2;
        pos1.y -= 3;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y+3 > 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+2)] != ' ')
         ||(my_board[pos1.x][(pos1.y+3)] != ' ')){
        return;
      }
      else{
        pos4.x += 3;
        pos4.y += 3;
        pos3.x += 2;
        pos3.y += 2;
        pos2.x += 1;
        pos2.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'J'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.x == 0)
         ||(my_board[(pos1.x-1)][(pos1.y+1)] != ' ')
         ||(my_board[(pos1.x-1)][pos1.y] != ' ')){
        return;
      }
      else{
        pos3 = pos1;
        pos4 = pos2;
        pos1.y += 1;
        pos1.x -= 1;
        pos2.x -= 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[(pos1.x+1)][pos1.y] != ' ')
         ||(my_board[(pos1.x+1)][(pos1.y+1)] != ' ')
         ||(my_board[(pos1.x+2)][(pos1.y+1)] != ' ')){
        return;
      }
      else{
        pos4.x -= 1;
        pos3.y += 1;
        pos2.x += 1;
        pos2.y += 2;
        pos1.x += 2;
        pos1.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.x == 0)
         ||(my_board[(pos3.x-1)][pos3.y] != ' ')
         ||(my_board[(pos3.x+1)][pos3.y] != ' ')
         ||(my_board[pos1.x][(pos1.y-2)] != ' ')){
        return;
      }
      else{
        pos4.x -= 1;
        pos4.y += 1;
        pos2.x += 1;
        pos2.y -= 1;
        pos1.y -= 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.y == 9)
         ||(my_board[(pos1.x-1)][pos1.y] != ' ')
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')){
        return;
      }
      else{
        pos4.x += 2;
        pos4.y += 1;
        pos3.x += 1;
        pos2.y -= 1;
        pos1.x -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'L'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.x == 0)
         ||(my_board[(pos1.x-2)][pos1.y] != ' ')
         ||(my_board[(pos1.x-1)][pos1.y] != ' ')){
        return;
      }
      else{
        pos3 = pos1;
        pos4 = pos2;
        pos1.x -= 2;
        pos2.x -= 1;
        pos2.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[(pos4.x-1)][pos4.y] != ' ')
         ||(my_board[pos2.x][(pos2.y+2)] != ' ')){
        return;
      }
      else{
        pos4.y -= 1;
        pos3.x -= 1;
        pos2.y += 1;
        pos1.x += 1;
        pos1.y += 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.x == 0)
         ||(my_board[(pos3.x-1)][pos3.y] != ' ')
         ||(my_board[(pos2.x-1)][pos2.y] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.x -= 2;
        pos3.x -= 1;
        pos3.y += 1;
        pos1.x += 1;
        pos1.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.y == 9)
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[(pos4.x+2)][pos4.y] != ' ')){
        return;
      }
      else{
        pos4.x += 1;
        pos4.y += 2;
        pos3.x += 2;
        pos3.y += 1;
        pos2.x += 1;
        pos1.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'L'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.x == 0)
         ||(my_board[(pos1.x-2)][pos1.y] != ' ')
         ||(my_board[(pos1.x-1)][pos1.y] != ' ')){
        return;
      }
      else{
        pos3 = pos1;
        pos4 = pos2;
        pos1.x -= 2;
        pos2.x -= 1;
        pos2.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[(pos4.x-1)][pos4.y] != ' ')
         ||(my_board[pos2.x][(pos2.y+2)] != ' ')){
        return;
      }
      else{
        pos4.y -= 1;
        pos3.x -= 1;
        pos2.y += 1;
        pos1.x += 1;
        pos1.y += 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.x == 0)
         ||(my_board[(pos3.x-1)][pos3.y] != ' ')
         ||(my_board[(pos2.x-1)][pos2.y] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.x -= 2;
        pos3.x -= 1;
        pos3.y += 1;
        pos1.x += 1;
        pos1.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.y == 9)
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[(pos4.x+2)][pos4.y] != ' ')){
        return;
      }
      else{
        pos4.x += 1;
        pos4.y += 2;
        pos3.x += 2;
        pos3.y += 1;
        pos2.x += 1;
        pos1.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'S'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.x == 0)
         ||(my_board[(pos1.x-1)][pos1.y] != ' ')
         ||(my_board[(pos1.x-2)][pos1.y] != ' ')){
        return;
      }
      else{
        pos4 = pos2;
        pos1.x -= 2;
        pos2.x -= 1;
        pos2.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.y == 9)
         ||(my_board[pos4.x][(pos4.y-1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')){
        return;
      }
      else{
        pos1.x += 1;
        pos1.y += 2;
        pos2.y += 1;
        pos3.x += 1;
        pos4.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.x == 0)
         ||(my_board[(pos4.x-1)][pos4.y] != ' ')
         ||(my_board[(pos4.x-2)][pos4.y] != ' ')){
        return;
      }
      else{
        pos4.x -= 2;
        pos3.x -= 1;
        pos3.y -= 1;
        pos1.x += 1;
        pos1.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.y == 9)
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y-1)] != ' ')){
        return;
      }
      else{
        pos4.x += 1;
        pos4.y += 2;
        pos3.y += 1;
        pos2.x += 1;
        pos1.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'Z'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.x == 0)
         ||(my_board[(pos2.x-1)][pos2.y] != ' ')
         ||(my_board[pos3.x][(pos3.y-1)] != ' ')){
        return;
      }
      else{
        pos1.x -= 1;
        pos1.y += 1;
        pos3.x -= 1;
        pos3.y -= 1;
        pos4.y -= 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+2)] != ' ')){
        return;
      }
      else{
        pos1.x += 2;
        pos1.y += 1;
        pos2.x += 1;
        pos3.y += 1;
        pos4.x -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.x == 0)
         ||(my_board[(pos3.x-1)][pos3.y] != ' ')
         ||(my_board[(pos4.x+1)][pos4.y] != ' ')){
        return;
      }
      else{
        pos4.x -= 1;
        pos4.y += 1;
        pos2.x -= 1;
        pos2.y -= 1;
        pos1.y -= 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+2)] != ' ')){
        return;
      }
      else{
        pos4.x += 2;
        pos4.y += 1;
        pos3.x += 1;
        pos2.y += 1;
        pos1.x -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'T'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.x == 0)
         ||(my_board[(pos2.x-1)][pos2.y] != ' ')){
        return;
      }
      else{
        pos1.x -= 1;
        pos1.y += 1;
        pos4.x += 1;
        pos4.y -= 1;
        pos3.x -= 1;
        pos3.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y-1)] != ' ')){
        return;
      }
      else{
        pos1.x += 2;
        pos1.y += 1;
        pos2.x += 1;
        pos3.y += 1;
        pos4.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.x == 0)
         ||(my_board[(pos4.x-1)][pos4.y] != ' ')
         ||(my_board[(pos4.x-2)][pos4.y] != ' ')){
        return;
      }
      else{
        pos4.x -= 2;
        pos2.x -= 1;
        pos2.y -= 1;
        pos1.y -= 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.y == 9)
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[(pos3.x+1)][pos3.y] != ' ')){
        return;
      }
      else{
        pos4.x += 1;
        pos4.y += 2;
        pos3.x += 1;
        pos2.y += 1;
        pos1.x -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else{
    return;
  }
}


void Board::CClockWise(){
  Block *bptr = ba[ba_max-1];
  if(bptr->GetType() == 'I'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.x == 0)
         ||(pos1.x == 1)
         ||(pos1.x == 2)
         ||(my_board[(pos1.x - 3)][pos1.y] != ' ')
         ||(my_board[(pos1.x-2)][pos1.y] != ' ')
         ||(my_board[(pos1.x-1)][pos1.y] != ' ')){
        return;
      }
      else{
        pos2.x -= 1;
        pos2.y -= 1;
        pos3.x -= 2;
        pos3.y -= 2;
        pos4.y -= 3;
        pos4.x -= 3;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==4){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y+3 > 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+2)] != ' ')
         ||(my_board[pos1.x][(pos1.y+3)] != ' ')){
        return;
      }
      else{
        pos4.x += 3;
        pos1.y += 3;
        pos2.x += 1;
        pos2.y += 2;
        pos3.x += 2;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.x == 0)
         ||(pos4.x == 1)
         ||(pos4.x == 2)
         ||(my_board[(pos4.x - 3)][pos4.y] != ' ')
         ||(my_board[(pos4.x-2)][pos4.y] != ' ')
         ||(my_board[(pos4.x-1)][pos4.y] != ' ')){
        return;
      }
      else{
        pos3.x -= 1;
        pos3.y -= 1;
        pos2.x -= 2;
        pos2.y -= 2;
        pos1.x -= 3;
        pos1.y -= 3;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y+3 > 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+2)] != ' ')
         ||(my_board[pos4.x][(pos4.y+3)] != ' ')){
        return;
      }
      else{
        pos4.y += 3;
        pos1.x += 3;
        pos3.x += 1;
        pos3.y += 2;
        pos2.x += 2;
        pos2.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'J'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.x == 0)
         ||(my_board[(pos3.x - 2)][pos3.y] != ' ')
         ||(my_board[(pos3.x - 1)][pos3.y] != ' ')){
        return;
      }
      else{
        pos1.x += 1;
        pos2.y += 1;
        pos3.x -= 1;
        pos4.y -= 1;
        pos4.x -= 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos4.x][(pos4.y+2)] != ' ')){
        return;
      }
      else{
        pos4.y += 2;
        pos1.x += 1;
        pos1.y -= 1;
        pos2.x += 2;
        pos3.x += 1;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.x == 0)
         ||(my_board[(pos4.x+1)][pos4.y] != ' ')
         ||(my_board[(pos4.x-1)][pos4.y] != ' ')
         ||(my_board[(pos3.x-1)][pos3.y] != ' ')){
        return;
      }
      else{
        pos4.x += 1;
        pos3.y -= 1;
        pos2.x -= 1;
        pos2.y -= 2;
        pos1.x -= 2;
        pos1.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.y == 9)
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos3.x][(pos3.y+1)] != ' ')
         ||(my_board[(pos1.x-1)][pos1.y] != ' ')){
        return;
      }
      else{
        pos1.y += 2;
        pos4.x += 1;
        pos4.y -= 1;
        pos2.x -= 1;
        pos2.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'L'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.x == 0)
         ||(my_board[(pos2.x - 2)][pos2.y] != ' ')
         ||(my_board[(pos2.x - 1)][pos2.y] != ' ')
         ||(my_board[(pos1.x - 2)][pos1.y] != ' ')){
        return;
      }
      else{
        pos1.y += 1;
        pos2.x -= 1;
        pos3.x -= 2;
        pos3.y -= 1;
        pos4.y -= 2;
        pos4.x -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos4.y == 9)
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y+2)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos4.x -= 1;
        pos1.x += 2;
        pos2.x += 1;
        pos2.y += 1;
        pos3.y += 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.x == 0)
         ||(my_board[(pos3.x-1)][pos3.y] != ' ')
         ||(my_board[pos4.x][(pos4.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos3.x += 1;
        pos2.y -= 1;
        pos1.x -= 1;
        pos1.y -= 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.y == 9)
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')
         ||(my_board[pos2.x][(pos2.y-1)] != ' ')
         ||(my_board[pos1.x][(pos1.y-1)] != ' ')){
        return;
      }
      else{
        pos1.x -= 1;
        pos1.y += 1;
        pos4.x += 2;
        pos3.x += 1;
        pos3.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else if(bptr->GetType() == 'S'){
    ClockWise();
  }
  else if(bptr->GetType() == 'Z'){
    ClockWise();
  }
  else if(bptr->GetType() == 'T'){
    if(bptr->BottomLeft()==1){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos1.x == 0)
         ||(my_board[(pos1.x - 1)][pos1.y] != ' ')
         ||(my_board[(pos1.x + 1)][pos1.y] != ' ')){
        return;
      }
      else{
        pos1.x += 1;
        pos2.y -= 1;
        pos3.x -= 1;
        pos4.y -= 2;
        pos4.x -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==2){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos2.y == 9)
         ||(my_board[pos2.x][(pos2.y+1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos4.x -= 1;
        pos1.x += 1;
        pos1.y -= 1;
        pos3.x += 1;
        pos3.y += 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else if(bptr->BottomLeft()==3){
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.x == 0)
         ||(my_board[(pos3.x-1)][pos3.y] != ' ')
         ||(my_board[pos3.x][(pos3.y-1)] != ' ')){
        return;
      }
      else{
        pos4.y += 1;
        pos3.y -= 1;
        pos2.x -= 1;
        pos1.x -= 2;
        pos1.y -= 1;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    else{
      Posn pos1 = bptr->First();
      Posn pos2 = bptr->Second();
      Posn pos3 = bptr->Third();
      Posn pos4 = bptr->Forth();
      if((pos3.y == 9)
         ||(my_board[pos1.x][(pos1.y+1)] != ' ')
         ||(my_board[pos1.x][(pos1.y+2)] != ' ')){
        return;
      }
      else{
        pos1.y += 2;
        pos2.x += 1;
        pos2.y += 1;
        pos4.x += 2;
        bptr->SetFirst(pos1);
        bptr->SetSecond(pos2);
        bptr->SetThird(pos3);
        bptr->SetForth(pos4);
      }
    }
    return;
  }
  else{
    return;
  }
}

