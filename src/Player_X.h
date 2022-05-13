#pragma once
#include "Player_Y.h"

class Player_X : public Player_Y {
	int x;
	int y;
public:
	Player_X();
	void setX_Y(int x_p, int y_p);
	int get_X() { return x; };
	int get_Y() { return y; };
	~Player_X() { };
};