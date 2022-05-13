#pragma once

class Player_Y {
	int x;
	int y;
public:
	Player_Y();
	void setX_Y(int x_p, int y_p);
	int get_X() { return x; };
	int get_Y() { return y; };
	~Player_Y() { };
};