#pragma once

class Player_Y {
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