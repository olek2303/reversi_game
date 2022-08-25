#define _CRT_SECURE_NO_WARNINGS
#include "Player_Y-1p.hpp"
#include <iostream>

using namespace std;

Player_Y_1p::Player_Y_1p() {
	x = 3;
	y = 3;
}

int Player_Y_1p::setX() {
	int x_p = rand() % 8;
	x = x_p;
	return x_p;
}
int Player_Y_1p::setY() {
	int y_p = rand() % 8;
	y = y_p;
	return y_p;
}