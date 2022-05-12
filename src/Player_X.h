#pragma once
#include "BaseClass.h"

class Player_X : public Base {
	int x;
	int y;
	Player_X* head;
public:
	Player_X();
	~Player_X() {};
	void setX(int x_p) { x = x_p; };
	void setY(int y_p) { y = y_p; };
	int get_X() { return x; };
	int get_Y() { return y; };
	Player_X* nast;
};