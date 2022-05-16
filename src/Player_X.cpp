#define _CRT_SECURE_NO_WARNINGS
#include "Player_X.hpp"
#include <iostream>

using namespace std;

Player_X::Player_X() {
	x = 4;
	y = 4;
}

int Player_X::setX() {
	int x_p;
	cout << "Podaj wartosc x na ktorej pozycji ustawic gracza X: ";
	while (scanf("%d", &x_p) != 1 || x_p < 0 || x_p > 7 || getchar() != '\n') {
		cout << "Bledne dane. Popraw:";
		while (getchar() != '\n')
			;
	}
	x = x_p;
	return x_p;
}
int Player_X::setY() {
	int y_p;
	cout << "Podaj wartosc y na ktorej pozycji ustawic gracza X: ";
	while (scanf("%d", &y_p) != 1 || y_p < 0 || y_p > 7 || getchar() != '\n') {
		cout << "Bledne dane. Popraw:";
		while (getchar() != '\n')
			;
	}
	y = y_p;
	return y_p;
}