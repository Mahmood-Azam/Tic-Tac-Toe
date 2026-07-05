#include<iostream>
using namespace std;
#include"Header.h"

void printBoard(char board[][3]);

bool Checkwin(char board[][3], char player);

int digitCount(int a);

void playGame(char board[][3], int mode);

int main() {
char Board[3][3];

for (int r = 0; r < 3; r++) {
	for (int c = 0; c < 3; c++) {
		Board[r][c] = ' ';
	}
}


int mode=0;
cout << "Enter mode ( 0 for player and 1 for AI) : ";
cin >> mode;

while(mode!=1 && mode!=0){
cout<<"Enter mode ( 0 for player and 1 for AI) : ";
cin>>mode;
}
srand(time(0));

playGame(Board,mode);

	
}

