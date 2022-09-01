#pragma once 

class Player_Y_abstr {
public:
	virtual int setX() = 0;
	virtual int setY() = 0;
	virtual void setX1(int xp) = 0;
	virtual void setY1(int yp) = 0;
	virtual int get_X() = 0;
	virtual int get_Y() = 0;
};