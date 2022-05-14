#pragma once
#include "Player_X.h"	

class Base : public Player_X{
	char tab[8][8];
public:
	Base();
	void showDesk();
	void getFromX(Player_X* px, int x1, int y1);
	void getFromY(Player_Y* py, int x1, int y1);
	void fillDesk(Base* b, Player_X* px, Player_Y* py);
	bool checkIfComplete();
	int countX();
	int countY();
	~Base() { };
};