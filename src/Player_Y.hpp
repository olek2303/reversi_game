#pragma once
#include "Player_Y_abstr.hpp"
#ifndef Player_Y_abstr_hpp
#define Player_Y_abstr_hpp

class Player_Y : public Player_Y_abstr{
	int x;
	int y;
public:
	Player_Y();
	int setX();
	int setY();
	int get_X() { return x; };
	int get_Y() { return y; };
	~Player_Y() { };
};

#endif