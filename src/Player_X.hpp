#pragma once
#include "Player_Y.hpp"
#ifndef Player_Y_hpp
#define Player_Y_hpp

class Player_X : public Player_Y {
	int x;
	int y;
public:
	Player_X();
	int setX();
	int setY();
	int get_X() { return x; };
	int get_Y() { return y; };
	~Player_X() { };
};

#endif