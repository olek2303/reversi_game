#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include "Functions.h"
#include "Player_X.h"
#include "Player_Y.h"
#include "BaseClass.h"

using namespace std;

int main(int argc, char* argv[]) {

	cout << "--------- REVERSI GAME C++ ---------" << endl << endl;
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 4 && j == 4) 
				cout << " X ";
			else if (i == 3 && j == 3)
				cout << " O ";
			else 
				cout << " . ";
		}
		cout << endl;
	}

	return 0;
} 