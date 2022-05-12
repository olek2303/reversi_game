#pragma once
#include "Player_X.h"

class Player_Y : public Player_X {
	int x;
	int y;
	Player_Y* head; 
public:
	Player_Y();
	~Player_Y() { };
	void setX(int x_p) { x = x_p; };
	void setY(int y_p) { y = y_p; };
	int get_X() { return x; };
	int get_Y() { return y; };
	void showDesk();
	Player_Y* nast;
};