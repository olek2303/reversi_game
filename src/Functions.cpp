#define _CRT_SECURE_NO_WARNINGS
#include "Functions.hpp"
#include <iostream>

using namespace std;

int ktore_pole_x() {
	int x;
	cout << "Podaj wspolrzedne pola X: ";
	while (scanf("%d", &x) != 1 || x < 0 || x > 7 || getchar() != '\n') {
		cout << "Zostaly wprowadzone bledne dane. Sprobuj ponownie..." << endl;
		while (getchar() != '\n')
			;
	}
	return x;
}

int ktore_pole_y() {
	int y;
	cout << "Podaj wspolrzedne pola Y: ";
	while (scanf("%d", &y) != 1 || y < 0 || y > 7 || getchar() != '\n') {
		cout << "Zostaly wprowadzone bledne dane. Sprobuj ponownie..." << endl;
		while (getchar() != '\n')
			;
	}
	return y;
}