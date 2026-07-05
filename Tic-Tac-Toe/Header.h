#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


int digitCount(int a) {
	int count = 0;
	while (a != 0) {
		a = a / 10;
		count++;
	}
	return count;
}

void printBoard(char board[][3]) {

cout<<"   1   2   3";
 	for (int i = 0;i < 3;i++) {
	cout<<endl;
		for (int j = 0;j < 3;j++) {


			if (board[i][j] == 'X') {
				if (j == 0) {
					cout <<i+1<< "| X |";
				}
				else if (j != 2) {
					cout << " X |";
				}
				else {
					cout << " X ";
				}
			}


			else if(board[i][j]=='O'){
				if (j == 0) {
					cout <<i+1<< "| O |";
				}
				else if (j != 2) {
					cout << " O |";
				}
				else {
					cout << " O ";
				}
			}

			else {
			
				 if (j == 0) {
					cout<<i+1 << "|   |";
				}
				else if (j != 2) {
					cout << "   |";
				}
				else {
					cout << "   ";
				}
			}

			}
		}
 }

bool Checkwin(char board[][3], char A) {
bool win=false;
int count=0;

//FOWARD CHECK 1 2 3
	for (int i = 0;i < 3;i++) {
	count=0;
		for (int j = 0;j < 3; j++) {
			if (board[i][j] == A) {
			count++;
				if (j == 2 && count==3) {
					win=true;
					break;
				}
			}

		}
	}

	//TOP DOWN CHECK

	for (int i = 0;i < 3;i++) {
		count = 0;
		for (int j = 0;j < 3; j++) {
			if (board[j][i] == A) {
				count++;

				if (j == 2 && count == 3) {
					win = true;
					break;
				}
			}

		}
	}


	//LEFT TO RIGHT DIAGONAL CHECK
	count=0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
		if(i==j){
		if(board[i][j]==A) {
		count++;
		if (j == 2 && count == 3) {
			win=true;
			break;
		}
		}
		}
		}
	}

	//RIGHT TO LEFT DIAGONAL CHECK

	count = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][2 - i] == A) {
			count++;
			if (i == 2 && count == 3) {
				win = true;
				break;
			}
		}
	}

	return win;
}


bool isFull(char board[][3]) {
bool full=true;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (board[i][j] == ' ') {
				full=false;
				return full;
			}
		}
}

return full;
}


bool Occupied(char board[][3], int i, int j) {
	if (board[i][j] != ' ') {
		return true;
	}
	return false;

}

void EasyAI(char Board[][3]) {


int ranI= rand() % 3;
int ranJ= rand()%3;
while (Occupied(Board, ranI, ranJ)) {
	 ranI = rand() % 3;
	 ranJ = rand() % 3;
}
Board[ranI][ranJ]='O';
return;

}
bool WouldWin(char Board[][3], int i, int j, char mark) {
	Board[i][j]= mark;
	if (Checkwin(Board, mark) == true) {
	Board[i][j]= ' ';
		return true;
	}
	
	Board[i][j]= ' ';
	return false;
}

void MediumAI(char Board[][3]) {

	// three checks

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
		//check 1: can i win
			if (!Occupied(Board, i, j) && WouldWin(Board, i, j, 'O')) {
				Board[i][j]= 'O';
				return;
	}
		}
}


//check 2: can i block opponent
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
		
			if (!Occupied(Board, i, j) && WouldWin(Board, i, j, 'X')) {
				Board[i][j]='O';
				return;
		  }
		}
	}

	
//case 3: call easy Ai for rand

EasyAI(Board);
return;

}//func end



int EvaluateBoard(char board[][3]) {

	
		if (Checkwin(board, 'O')) {
			return 1;
		}
		else if (Checkwin(board, 'X')) {
			return -1;
		}
		
		if (isFull(board)) {
			return 0;
		}

		else return 2;



} //func end
char Opposite(char mark) {
	if( mark=='X') return 'O';
	if(mark=='O')return 'X';
}



int minimax(char board[][3], char mark){

int result= EvaluateBoard(board);
if (result != 2) 
	return result;

	int maxO=-10000;
	int minX=100000;

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (!Occupied(board, i, j)) {
			board[i][j]=mark;
			int score= minimax(board, Opposite(mark));

			board[i][j]= ' ';
			if (mark == 'X') {
				if (score < minX) {
					minX=score;
				
				}
			

				}
			else if(mark=='O'){
				if (score > maxO) {
					maxO=score;
				
			}
			
			}

			}
		}
	

}

	if (mark == 'O') {
		return maxO;
	}
	else {
		return minX;
	}

} //func end

void HardAI(char board[][3]) {
int bestScore=-10000;
int bestI;
int bestJ;
for (int i = 0;i < 3;i++) {
	for (int j = 0;j < 3;j++) {

		if (!Occupied(board,i,j)) {
		board[i][j]='O';
		int result=minimax(board,'X');
		if(result>bestScore){
		bestScore=result;
		bestI=i;
		bestJ=j;
		}

		board[i][j]=' ';
	}




	}
}

board[bestI][bestJ]='O';
}//func end


void playGame(char Board[][3], int mode=0){
	int diff = 0;


	if (mode == 1) {
		cout << "Enter difficulty (0=easy, 1=medium, 2= hard) : " <<endl;
		cin>>diff;
	}



 int a;
	int turn = 0;
	int i = 0;
	int j = 0;

	while (true) {
		printBoard(Board);

		cout << endl;
		cout << endl;
		cout << endl;

		char mark= (turn%2==0)? 'X':'O';
		bool thisturnisHuman;

		if (mark == 'X' ) {
			thisturnisHuman=true;
		}
		else if( mark=='O' && mode==0) { thisturnisHuman = true; }

		else {
			thisturnisHuman=false;
		}


		if (mark == 'X') {
			cout<<"Player 1 Turn (X) "<<endl;
		}
		else if (mark == 'O' && mode==0) {
		    cout<<"Player 2 Turn (O) "<<endl;
		}
		else {
			cout<<"AI's Turn"<<endl;
		}
	



		turn++;
		
		if(thisturnisHuman==true){
		cout << "Enter Coordinates (11 for first entry etc):  ";
		cin >> a;
		int original = a;
		j = a % 10;
		a = a / 10;
		i = a % 10;



		while ((digitCount(original) != 2) || !(i > 0 && i <= 3 && j > 0 && j <= 3) || Board[i - 1][j - 1] != ' ') {
			cout << endl;
			cout << "Invalid Input, reEnter:  ";
			cin >> a;
			int original = a;
			j = a % 10;
			a = a / 10;
			i = a % 10;
		}


		i -= 1;
		j -= 1;




		Board[i][j]=mark;


		}//human check
		
		else {
		if(diff==0){
			EasyAI(Board);
			}

		else if (diff == 1) {
			MediumAI(Board);
		}
		else if (diff == 2) {
			HardAI(Board);

		}
		else {
			cout<<"Invalid difficulty"<<endl;
			return;
		}
		}


		if (Checkwin(Board, 'X')) {
			printBoard(Board);
			cout << endl;
			cout << endl;
			cout << "====== PLAYER 1 (X) WINS ===========";


			break;
		}
		else if (Checkwin(Board, 'O')) {
			printBoard(Board);
			cout << endl;
			cout << endl;
			cout << "====== Player 2 (O) WINS =========";
			break;
		}

		else if (isFull(Board)) {
			printBoard(Board);
			cout<<endl;
			cout<<endl;
			cout<<"=========DRAW===============";
			break;
		}

	}
}

