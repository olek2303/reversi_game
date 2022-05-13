#define _CRT_SECURE_NO_WARNINGS
#include "BaseClass.h"
#include <iostream>

using namespace std;

Base::Base() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tab[i][j] = " . ";
		}
	}
}

void Base::showDesk() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << tab[i][j];
		}
		cout << endl;
	}
}

void Base::fillDesk(Player_X* px, Player_Y* py) {
	int x1 = px->get_X();
	int y1 = px->get_Y();
	int x2 = py->get_X();
	int y2 = py->get_Y();
	if (tab[x1][y1] == ' . ') {
		tab[x1][y1] = ' X ';
	}
	else {
		while (tab[x1][y1] != " . ") {
			px->setX_Y(x1, y1);
		}
		tab[x1][y1] = ' X ';
	}
	if (tab[x2][y2] == ' . ') {
		tab[x2][y2] = ' Y ';
	}
	else {
		while (tab[x2][y2] != " . ") {
			py->setX_Y(x2, y2);
		}
		tab[x2][y2] = ' Y ';
	}
}
