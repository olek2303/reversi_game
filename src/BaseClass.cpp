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

void Base::getFromX(Player_X* px, int x1, int y1) {
	px->setX_Y(x1, y1);
	while (tab[x1][y1] != ' . ') {
		py->setX_Y(x1, y1);
	}
}

void Base::getFromY(Player_Y* py, int x1, int y1) {
	py->setX_Y(x1,y1);
	while (tab[x1][y1] != ' . ') {
		py->setX_Y(x1, y1);
	}
}

void Base::fillDesk(Base* b, Player_X* px, Player_Y* py) {
	int x1, y1, x2, y2;
	b->getFromX(px, x1, y1);
	b->getFromY(py, x2, y2);
	tab[x1][y1] = ' X ';
	tab[x2][y2] = ' Y ';
}

bool Base::checkIfComplete() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == ' . ')
				return 0;
		}
	}
	return 1;
}

int Base::countX(){
	int counter = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == ' X ')
				counter++;
		}
	}
	return counter;
}

int Base::countY() {
	int counter = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == ' Y ')
				counter++;
		}
	}
	return counter;
}
