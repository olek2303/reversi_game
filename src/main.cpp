#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Functions.h"
#include "Player_X.h"
#include "Player_Y.h"
#include "BaseClass.h"

using namespace std;

int main() {

	cout << "--------- REVERSI GAME C++ ---------" << endl << endl;
	int x = ktore_pole_x();
	int y = ktore_pole_y();
	
	Player_X px;
	Player_Y py;

	px.setX(x);
	px.setY(y);

	py.nast->showDesk();


	return 0;
} 