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
		else
		{
			return false;
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
