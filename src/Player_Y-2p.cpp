#define _CRT_SECURE_NO_WARNINGS
#include "Player_Y-2p.hpp"
#include <iostream>

using namespace std;

Player_Y_2p::Player_Y_2p() {
	x = 3;
	y = 3;
}

int Player_Y_2p::setX() {
	int x_p;
	cout << "Podaj wartosc x na ktorej pozycji ustawic gracza Y: ";
	while (scanf("%d", &x_p) != 1 || x_p < 0 || x_p > 7 || getchar() != '\n') {
		cout << "Bledne dane. Popraw:";
		while (getchar() != '\n')
			;
	}
	x = x_p;
	return x_p;
}
int Player_Y_2p::setY() {
	int y_p;
	cout << "Podaj wartosc y na ktorej pozycji ustawic gracza Y: ";
	while (scanf("%d", &y_p) != 1 || y_p < 0 || y_p > 7 || getchar() != '\n') {
		cout << "Bledne dane. Popraw:";
		while (getchar() != '\n')
			;
	}
	y = y_p;
	return y_p;
}