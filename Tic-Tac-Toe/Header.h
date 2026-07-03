#pragma once
#include<iostream>
using namespace std;

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
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (i == j) {
				if (board[j][i] == A) {
					count++;
					if (j == 2 && count == 3) {
						win = true;
						break;
					}
				}
			}
		}
	}
	return win;
}


