#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

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
	
	Board(char inBoard[][3])
	{
		this->gameBoard = inBoard;
	}

	void getGameBoard()
	{
		cout<<" ABC"<<endl;
		for (int i = 0; i<3; i++)
		{
			cout<<i+1;
			for (int k = 0; k<3; k++)
			{
				cout<<gameBoard[i][k];
			}
			cout<<endl;
		}
	}
	
	bool submitMove(string move, char player)
	{
		int x, y;
		switch(move)
		{
			case "A1":
				x = 0;
				y = 0;
				break;
			case "A2":
				x = 0;
				y = 1;
				break;
			case "A3":
				x = 0;
				y = 2;
				break;
			case "B1":
				x = 1;
				y = 0;
				break;
			case "B2":
				x = 1;
				y = 1;
				break;
			case "B3":
				x = 1;
				y = 2;
				break;
			case "C1":
				x = 2;
				y = 0;
				break;
			case "C2":
				x = 2;
				y = 1;
				break;
			case "C3":
				x = 2;
				y = 2;
				break;
			default:
				cout<<"Invalid Input"<<endl;
				break;
		}
		if(gameBoard[x][y] == ' ')
		{
			gameBoard[x][y] = player;
			return true;
		}
		else
			return false;
				
	}
	
	bool isWinner(char player)
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
				return true;
			else
				count  = 0;
		}
		if(gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player || gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player)
			return true;
		else
			return false;
	}
	
	bool isCat()
	{
		bool cat = true;
		for(int i = 0; i < 3; i++)
		{
			for(int k = 0; k<3; k++)
			{
				if(gameBoard[i][k] == ' ')
					cat = false;
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
	
	char getMarker()
	{
		return this->marker;
	}
	
	bool getIsHuman()
	{
		return this->isHuman;
	}
	
	string getPlayerMove()
	{
		if(this->isHuman)
			return getHumanMove();
		else
			return generateComputerMove();
	}
	
	string getHumanMove()
	{
		string move = "";
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
	
}
