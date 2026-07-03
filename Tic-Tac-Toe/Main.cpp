#include<iostream>
using namespace std;
#include"Header.h"

void printBoard(char board[][3]);

bool Checkwin(char board[][3], char player);

int digitCount(int a) {
int count=0;
	while (a != 0) {
     a=a/10;
	 count++;
	}
	return count;
}

int main() {
char Board[3][3];

for (int r = 0; r < 3; r++) {
	for (int c = 0; c < 3; c++) {
		Board[r][c] = ' ';
	}
}
int a;

int turn=0;
int i=0;
int j=0;
while (true) {
	printBoard(Board);

	cout<<endl;
	cout << endl;
	cout << endl;
	if (turn % 2 == 0) {
		cout<<"==== PLAYER 1 TURN (X)===="<<endl;
		}
    else{
		cout << "==== PLAYER 2 TURN (O)====" << endl;
	}
	turn++;
	cout<<"Enter Coordinates (11 for first entry etc):  ";
	cin>>a;
	int original = a;
	j = a % 10;
	a = a / 10;
	i = a % 10;



	while ((digitCount(original) != 2) || !(i > 0 && i <= 3 && j > 0 && j <= 3) || Board[i - 1][j - 1] != ' ') {
	cout<<endl;
	cout<<"Invalid Input, reEnter:  ";
	cin>>a;
	int original = a;
	j = a % 10;
	a = a / 10;
	i = a % 10;
	}


	i -= 1;
	j -= 1;
	



	if (turn % 2 == 0) {

		Board[i][j]='O';
	}
	else {
		Board[i][j]='X';
	}

	if (Checkwin(Board, 'X')) {
		printBoard(Board);
		cout<<endl;
		cout<<endl;
		cout<<"PLAYER 1 (X) WINS GG EZ";


		break;
	}
	else if (Checkwin(Board, 'O')) {
		printBoard(Board);
		cout << endl;
		cout << endl;
		cout<<"Player 2 (O) WINS GG EZ";
		break;
	}

}



	
}

