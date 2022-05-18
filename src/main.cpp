#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "Functions.hpp"
#include "Player_X.hpp"
#include "Player_Y.hpp"
#include "Player_Y-1p.hpp"
#include "Player_Y-2p.hpp"
#include "Player_Y_abstr.hpp"
#include "BaseClass.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	int start = 1;
	int counter = 0;
	int x = 0;
	int y = 0;

	Player_X* px = new Player_X();
	Player_Y* py = new Player_Y();
	Base* b = new Base();
	Player_Y_2p py2;
	Player_Y_1p py1;

	cout << "--------- REVERSI GAME C++ ---------" << endl << endl;


	cout << "1. gra dla dwoch osob" << endl;
	cout << "2. gra dla jednej osoby" << endl;
	cout << "3. wyjscie" << endl;

	while (scanf("%d", &start) != 1 || start < 1 || start > 3 || getchar() != '\n') {
		cout << "Bledne wprowadzone dane wyboru rozgrywki. Popraw...";
		while (getchar() != '\n')
			;
	}

	switch (start) {
	case 1:
		py = &py2;
		break;
	case 2:
		py = &py1;
		break;
	case 3:
	default: 
		cout << "Koncze gre." << endl;
		return 0;
	}
	
	b->setStartParameters(px, py);
	px->setX1(3);
	px->setY1(3);
	py->setX1(4);
	py->setY1(3);
	b->setStartParameters(px, py);
	b->showDesk();

	while (b->checkIfComplete() != 1) {
		
		if (counter % 2 == 0) {
			b->getFromX(px, x, y);
		}
		else {
			b->getFromY(py, x, y);
		}
		b->showDesk();
		//system("cls");

		counter++;
	}
	int counter_X = b->countX();
	int counter_Y = b->countY();
	if (counter_X > counter_Y) {
		cout << "Wygral gracz X!!!   Ilosc punktow: " << counter_X << endl;
	}
	else if (counter_X < counter_Y) {
		cout << "Wygral gracz Y!!!   Ilosc punktow: " << counter_Y << endl;
	}
	else {
		cout << "Remis :O" << endl;
	}
	cout << "Koniec gry." << endl;
	

	return 0;
} 