#pragma once
#include "Player_Y.hpp"
#ifndef Player_Y_hpp
#define Player_Y_hpp

class Base : public Player_Y{
	char tab[8][8];
public:
	Base();
	void infoGame();
	void showDesk();
	void setStartParameters(Player_Y* px, Player_Y* py);
	bool getFrom(Player_Y* px, int x1, int y1, char moj, char przeciw, int turn);
	bool checkIfComplete(Player_Y* px, Player_Y* py);
	int countX();
	int countY();
	~Base() { };
};

#endif