#pragma once
#include "Player_X.hpp"
#ifndef Player_X_hpp
#define Player_X_hpp

class Base : public Player_X{
	char tab[8][8];
public:
	Base();
	void showDesk();
	void setStartParameters(Player_X* px, Player_Y* py);
	void getFromX(Player_X* px, int x1, int y1);
	void getFromY(Player_Y* py, int x1, int y1);
	bool checkIfComplete();
	int countX();
	int countY();
	~Base() { };
};

#endif