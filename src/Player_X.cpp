#define _CRT_SECURE_NO_WARNINGS
#include "Player_X.h"
#include <iostream>

using namespace std;

Player_X::Player_X() {
	head->x = x = 4;
	head->y = y = 4;
	nast = head->nast;
}