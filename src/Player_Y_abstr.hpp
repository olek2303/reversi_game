#pragma once 

class Player_Y_abstr {
public:
	virtual int setX() = 0;
	virtual int setY() = 0;
	virtual int get_X() = 0;
	virtual int get_Y() = 0;
};