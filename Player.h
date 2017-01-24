#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Player {
	bool isHuman;
	char marker;
	
public:
		
	Player() {
		this->marker = 'X';
		this->isHuman = true;
	}
	
	Player(bool inIsHuman) {
		this->isHuman = inIsHuman;
		if(inIsHuman)
			this->marker = 'X';
		else
			this->marker = 'O';
	}
	
	Player(bool inIsHuman, char inMarker) {
		this->isHuman  = inIsHuman;
		if(inMarker == 'X')
			this->marker = 'X';
		else
			this->marker = 'O';
	}
	
	char getMarker() const {
		return this->marker;
	}
	
	bool getIsHuman() const {
		return this->isHuman;
	}
	
	string getPlayerMove() {
		if(this->isHuman == true)
			return getHumanMove();
		else
			return generateComputerMove();
	}
	
	string getHumanMove() const {
		string move;
		cout<<"Input a move"<<endl;
		cin>>move;
		return move;
	}
	
	string generateComputerMove() {
		string move;
		srand(time(NULL));
		int x, y;
		x = rand()%3;
		y = rand()%3;
		char moves[3] = {'A', 'B', 'C'};
		char moves2[3] = {'1', '2', '3'};
		char move1 = moves[y];
		char move2 = moves2[x];
		string move3 = "";
		move += move1;
		move += move2;
		return move;
	}
};
