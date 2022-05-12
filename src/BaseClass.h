#pragma once
#include "Player_X.h"	

class Base : public Player_X{
	char tab[8][8];
public:
	Base();
	void showDesk();
	void fillDesk(Player_X* px, Player_Y* py);
	~Base() { delete[] tab; };
};