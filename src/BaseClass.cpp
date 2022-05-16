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
			printf("%3c", tab[i][j]);
		}
		cout << endl;
	}
}

void Base::setStartParameters(Player_X* px, Player_Y* py) {
	int x = px->get_X();
	int y = px->get_Y();
	tab[x][y] = 'X';
	x = py->get_X();
	y = py->get_X();
	tab[x][y] = 'Y';
}

void Base::getFromX(Player_X* px, int x1, int y1) {
	x1 = px->setX();
	y1 = px->setY();
	while ((tab[x1 - 1][y1 - 1] != 'X' || tab[x1][y1 - 1] != 'X' || tab[x1 - 1][y1] != 'X' || tab[x1 + 1][y1 + 1] != 'X' || tab[x1][y1 + 1] != 'X' || tab[x1 + 1][y1] != 'X' || tab[x1 + 1][y1 - 1] != 'X' || tab[x1 - 1][y1 + 1] != 'X') && tab[x1][y1] != '.') {
		cout << "Nie mozesz w tym miejscu postawic swojego X..." << endl;
		x1 = px->setX();
		y1 = px->setY();
	}
	
	tab[x1][y1] = 'X';
}

void Base::getFromY(Player_Y* py, int x2, int y2) {
	x2 = py->setX();
	y2 = py->setY();
	while ((tab[x2 - 1][y2 - 1] != 'Y' || tab[x2][y2 - 1] != 'Y' || tab[x2 - 1][y2] != 'Y' || tab[x2 + 1][y2 + 1] != 'Y' || tab[x2][y2 + 1] != 'Y' || tab[x2 + 1][y2] != 'Y' || tab[x2 + 1][y2 - 1] != 'Y' || tab[x2 - 1][y2 + 1] != 'Y') && tab[x2][y2] != '.') {
		cout << "Nie mozesz w tym miejscu postawic swojego Y..." << endl;
		x2 = py->setX();
		y2 = py->setY();
	}
	tab[x2][y2] = 'Y';
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
