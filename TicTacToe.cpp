#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include "Board.h"
#include "Player.h"

using namespace std;

int main()
{
	Board gameBoard;
	gameBoard.clearBoard();
	gameBoard.getGameBoard();
	
	char x = 'X';
	char o = 'O';
	bool human = true;
		
	Player player1 = Player(human, x);
	Player player2 = Player(human, o);
	
	while(gameBoard.isWinner(player1.getMarker()) == false
	 && gameBoard.isWinner(player2.getMarker()) == false
	  && gameBoard.isCat() == false)
	{
		while(gameBoard.submitMove(player1.getHumanMove(), player1.getMarker()) == false)
		{}
		gameBoard.getGameBoard();
		
		if(gameBoard.isWinner(player1.getMarker()) && gameBoard.isCat())
		{
			break;
		}
		while(gameBoard.submitMove(player2.getHumanMove(), player2.getMarker()) == false
			&& !gameBoard.isWinner(player1.getMarker()))
		{}
		gameBoard.getGameBoard();
	}
	return 0;
}
