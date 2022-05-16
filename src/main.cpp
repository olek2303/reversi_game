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
#include "BaseClass.hpp"

using namespace std;

int main(int argc, char* argv[]) {

	cout << "--------- REVERSI GAME C++ ---------" << endl << endl;

	int counter = 0;
	int x = 0;
	int y = 0;

	cout << "SADASDASD";
	Player_X* px = new Player_X();
	Player_Y* py = new Player_Y();
	Base* b = new Base();
	b->showDesk();


	system("cls");
	while (b->checkIfComplete() != 1) {
		if (counter % 2 == 0) {
			b->getFromX(px, x, y);
		}
		else {
			b->getFromY(py, x, y);
		}
		b->showDesk();
		counter++;
	}

	return 0;
} 