#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <string>

using namespace std;

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
