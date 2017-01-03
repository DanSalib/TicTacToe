#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <string>

using namespace std;

class Board
{
	public:
		char gameBoard[3][3];
		
	Board()
	{
		for(int i = 0; i < 3; i++)
		{
			for(int k = 0; k < 3; k++)
			{
				this->gameBoard[i][k] = ' ';
			}
		}
	}
	
	Board(char gameBoard0[][2])
	{
		this->gameBoard[2][2] = gameBoard0[2][2];
	}

	void clearBoard()
	{
		for(int i = 0; i < 3; i++)
		{
			for(int k = 0; k < 3; k++)
			{
				this->gameBoard[i][k] = ' ';
			}
		}
	}

	void getGameBoard()
	{
		char letters[3] = {'A', 'B', 'C'};
		cout<<" 123"<<endl;
		for (int i = 0; i<3; i++)
		{
			cout<<letters[i];
			for (int k = 0; k<3; k++)
			{
				cout<<gameBoard[i][k];
			}
			cout<<endl;
		}
	}
	
	bool submitMove(string move, char player)
	{
		int x,y;
		string clearMove = move;
		if (clearMove.length() != 2) return false;
		if (clearMove[0] != 'A' && clearMove[0] != 'B' && clearMove[0] != 'C')
		{
			return false;
		}
		if (clearMove[1] != '1' && clearMove[1] != '2' && clearMove[1] != '3') 
		{
			return false;
		}
			
		x = clearMove[0] - 'A';
		y = clearMove[1] - '1';
		
		if(gameBoard[x][y] == ' ')
		{
			gameBoard[x][y] = player;
			return true;
		}
		
	}
	
	bool isWinner(char player) const
	{
		int count  = 0;
		for(int i = 0; i<3; i++)
		{
			for(int k = 0; k<3; k++)
			{
				if(gameBoard[i][k] == player)
					count++;
				else
					count  = 0;
			}
			if(count == 3)
			{
				cout<<player<<" wins"<<endl;
				return true;
			}
			else
				count  = 0;
		}
		
		for(int i = 0; i<3; i++)
		{
			for(int k = 0; k<3; k++)
			{
				if(gameBoard[k][i] == player)
					count++;
				else
					count  = 0;
			}
			if(count == 3)
			{
				cout<<player<<" wins"<<endl;
				return true;
			}
			else
				count  = 0;
		}
		
		
		
		if(gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player || gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player)
		{
			cout<<player<<" wins"<<endl;
			return true;
		}
		else
			return false;
	}
	
	bool isCat() const 
	{
		bool cat = false;
		for(int i = 0; i < 3; i++)
		{
			for(int k = 0; k<3; k++)
			{
				if(gameBoard[i][k] != ' ')
					cat = true;
			}
		}
	}
	
	
};

class Player
{
	public:
		char marker;
		bool isHuman;
		
	Player()
	{
		this->marker = 'X';
		this->isHuman = true;
	}
	
	Player(bool inIsHuman)
	{
		this->isHuman = inIsHuman;
		if(inIsHuman)
			this->marker = 'X';
		else
			this->marker = 'O';
	}
	
	Player(bool inIsHuman, char inMarker)
	{
		this->isHuman  = inIsHuman;
		if(inMarker == 'X')
			this->marker = 'X';
		else
			this->marker = 'O';
	}
	
	char getMarker() const
	{
		return this->marker;
	}
	
	bool getIsHuman() const
	{
		return this->isHuman;
	}
	
	string getPlayerMove() 
	{
		if(this->isHuman == true)
			return getHumanMove();
		else
			return generateComputerMove();
	}
	
	string getHumanMove() const
	{
		string move;
		cout<<"Input a move"<<endl;
		cin>>move;
		return move;
	}
	
	string generateComputerMove()
	{
		string move;
		int x, y;
		x = (rand() % 3);
		y = (rand() % 3);
		
		switch(x)
		{
			case 0:
				switch(y)
				{
					case 0:
						move = "A1";
						break;
					case 1:
						move = "A2";
						break;
					case 2:
						move = "A3";
						break;
					default:
						move = "N";
						break;
				}
			case 1:
				switch(y)
				{
					case 0:
						move = "B1";
						break;
					case 1:
						move = "B2";
						break;
					case 2:
						move = "B3";
						break;
					default:
						move = "N";
						break;
				}
			case 2:
				switch(y)
				{
					case 0:
						move = "C1";
						break;
					case 1:
						move = "C2";
						break;
					case 2:
						move = "C3";
						break;
					default:
						move = "N";
						break;
				}
			default:
				move = "N";
				break;
				
		}
		return move;
		
	}
	
	
};

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
