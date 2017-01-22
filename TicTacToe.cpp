#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <ctime>
#include "Board.h"
#include "Player.h"

using namespace std;

int main() {
	Board gameBoard;
	gameBoard.clearBoard();
	gameBoard.getGameBoard();
	
	char x = 'X';
	char o = 'O';
	bool human = true;
	char select;
		
	Player player1 = Player(human, x);
	
	cout<<"Type 'c' to play against the computer, otherwise Player 2 will be Human"<<endl;
	cin>>select;
	if(select == 'c'){
		human = false;
	}
	
	Player player2 = Player(human, o);
	
	
	while(gameBoard.isWinner(player1.getMarker()) == false
	 && gameBoard.isWinner(player2.getMarker()) == false
	  && gameBoard.isCat() == false) {
		while(gameBoard.submitMove(player1.getPlayerMove(), player1.getMarker()) == false) {}
		gameBoard.getGameBoard();
		
		if(gameBoard.isWinner(player1.getMarker()) || gameBoard.isCat()) {
			break;
		}
		while(gameBoard.submitMove(player2.getPlayerMove(), player2.getMarker()) == false
			&& !gameBoard.isWinner(player1.getMarker())) {}
		gameBoard.getGameBoard();
	}
	if(gameBoard.isCat())
		cout<<"Cats Game!";
	return 0;
}
