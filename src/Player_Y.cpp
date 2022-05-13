#define _CRT_SECURE_NO_WARNINGS
#include "Player_Y.h"
#include <iostream>

using namespace std;

Player_Y::Player_Y() {
	x = 3;
	y = 3;
}

void Player_Y::setX_Y(int x_p, int y_p) {
	while (scanf("%d", &x_p) != 1 || x_p < 0 || x_p > 7 || getchar() != '\n') {
		cout << "Bledne dane. Popraw:";
		while (getchar() != '\n')
			;
	}
	while (scanf("%d", &y_p) != 1 || y_p < 0 || y_p > 7 || getchar() != '\n') {
		cout << "Bledne dane. Popraw:";
		while (getchar() != '\n')
			;
	}
	x = x_p;
	y = y_p;
}