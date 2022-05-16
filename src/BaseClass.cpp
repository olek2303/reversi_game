#define _CRT_SECURE_NO_WARNINGS
#include "BaseClass.hpp"
#include <iostream>

using namespace std;

Base::Base() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tab[i][j] = '.';
		}
	}
}

void Base::showDesk() {
	cout << "DDDD" << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%.3c", tab[i][j]);
		}
		cout << endl;
	}
}

void Base::getFromX(Player_X* px, int x1, int y1) {
	x1 = px->setX();
	y1 = px->setY();
	while (tab[x1][y1] != '.') {
		x1 = px->setX();
		y1 = px->setY();
	}
	tab[x1][y1] = 'X';
}

void Base::getFromY(Player_Y* py, int x1, int y1) {
	x1 = py->setX();
	y1 = py->setY();
	while (tab[x1][y1] != '.') {
		x1 = py->setX();
		y1 = py->setY();
	}
	tab[x1][y1] = 'Y';
}

bool Base::checkIfComplete() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == '.')
				return 0;
		}
	}
	return 1;
}

int Base::countX(){
	int counter = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == 'X')
				counter++;
		}
	}
	return counter;
}

int Base::countY() {
	int counter = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == 'Y')
				counter++;
		}
	}
	return counter;
}
