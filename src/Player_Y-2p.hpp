#pragma once
#include "Player_Y.hpp"

class Player_Y_2p : public Player_Y {
	int x;
	int y;
public:
	Player_Y_2p();
	int setX();
	int setY();
	int get_X() { return x; };
	int get_Y() { return y; };
	~Player_Y_2p() { };
};
