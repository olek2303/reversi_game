#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "Player_Y.hpp"
#include "Player_Y-1p.hpp"
#include "Player_Y_abstr.hpp"
#include "BaseClass.hpp"
#include "File.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	int start = 1;
	int counter = 2;
	int x = 0;
	int y = 0;
	bool playerX = 0;
	bool playerY = 0;

	Player_Y* px = new Player_Y();
	Player_Y* py = new Player_Y();
	Base* b = new Base();
	Player_Y_1p py1;
	File* f1 = new File();
	File* f2 = new File();
	char n1[20] = { '\0' };

	cout << "--------- REVERSI GAME C++ ---------" << endl << endl;
	b->infoGame();
	cout << "WYBIERZ JEDNA Z 3 OPCJI: " << endl;
	cout << "1. gra dla dwoch osob" << endl;
	cout << "2. gra dla jednej osoby" << endl;
	cout << "3. wyjscie" << endl;

	while (scanf("%d", &start) != 1 || start < 1 || start > 3 || getchar() != '\n') {
		cout << "Bledne wprowadzone dane wyboru rozgrywki. Popraw...";
		while (getchar() != '\n')
			;
	}

	int wybor = 0;

	switch (start) {
	case 1:
		cout << "Nick gracza pierwszego: ";
		cin >> n1;
		f1->setNazwa(n1);
		cout << "Nick gracza drugiego: ";
		cin >> n1;
		f2->setNazwa(n1);
		wybor = 1;
		break;
	case 2:
		cout << "Nick gracza: ";
		cin >> n1;
		f1->setNazwa(n1);
		py = &py1;
		wybor = 2;
		break;
	case 3:
	default: 
		cout << "Koncze gre." << endl;
		return 0;
	}
	system("cls");
	b->setStartParameters(px, py);
	b->showDesk();

	bool endGame = 0;
	while (endGame != 1) {
		if (counter % 2 == 0) {
			while (playerX != 1) {
				playerX = b->getFrom(px, x, y, 'X', 'Y', 0, wybor);
			}
		}
		counter++;
		playerX = 0;
		//system("cls");
		b->showDesk();
		endGame = b->checkIfComplete(px,py);
		if (endGame == 1)
			break;
		int c = 0;
		if (counter % 2 != 0) {
			while (playerY != 1) {
				playerY = b->getFrom(py, x, y, 'Y', 'X', 1, wybor);
				c++;
				if (c == 150) {
					py->setX1(-1);
					py->setY1(-1);
					cout << "Nie ma mozliwosci ruchu" << endl;
					break;
				}
			}
		}
		c = 0;
		playerY = 0;
		//system("cls");
		b->showDesk();
		endGame = b->checkIfComplete(px,py);
		if (endGame == 1)
			break;

		counter++;
	}
	int counter_X = b->countX();
	int counter_Y = b->countY();
	int winOrLoseX = 0, winOrLoseY = 0;
	if (counter_X > counter_Y) {
		cout << "Wygral gracz X!!!   Ilosc punktow: " << counter_X << endl;
		winOrLoseX = 1;
		winOrLoseY = 0;
	}
	else if (counter_X < counter_Y) {
		cout << "Wygral gracz Y!!!   Ilosc punktow: " << counter_Y << endl;
		winOrLoseX = 0;
		winOrLoseY = 1;
	}
	else {
		cout << "Remis :O" << endl;
		winOrLoseX = winOrLoseY = 2;
	}
	f1->addToFile(counter_X, winOrLoseX);
	f2->addToFile(counter_Y, winOrLoseY);

	int wyb = 1;
	while (wyb != 0) {
		cout << "Czy chcesz wyswietlic statystyki jakiegos gracza? (1 - tak, 0 - nie)" << endl;
		while (scanf("%d", &wyb) != 1 || getchar() != '\n' || wyb < 0 || wyb > 1) {
			while (getchar() != '\n')
				;
		}
		if (wyb == 1) {
			char nazwa[30] = { '\0' };
			cout << "Podaj nick gracza ktorego statystyki chcesz odczytac: " << endl;
			while (scanf("%s", nazwa) != 1 || getchar() != '\n') {
				while (getchar() != '\n')
					;
			}
			File* stat = new File();
			stat->readFile(nazwa);
		}
	}
	

	cout << "Koniec gry." << endl;

	return 0;
} 