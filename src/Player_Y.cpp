#define _CRT_SECURE_NO_WARNINGS
#include "Player_Y.h"
#include <iostream>

using namespace std;

Player_Y::Player_Y() {
	head->x = x = 3;
	head->y = y = 3;
	nast = head->nast;
}

void Player_Y::showDesk() {
	Player_X px;
	Player_Y py;
	int x1, y1, x2, y2;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (px.nast != NULL)
				x1 = px.nast->get_X();
			if (px.nast != NULL)
				y1 = px.nast->get_Y();
			if (py.nast != NULL)
				x2 = px.nast->get_X();
			if (py.nast != NULL)
				y2 = px.nast->get_Y();
			if ((i == x1 && j == y1)) {
				cout << " X ";
			}
			else if ((i == x2 && j == y2)) {
				cout << " Y ";
			}
			else
				cout << " . ";
		}
		cout << endl;
	}
}