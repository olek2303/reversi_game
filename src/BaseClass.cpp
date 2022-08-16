#define _CRT_SECURE_NO_WARNINGS
#include "BaseClass.hpp"
#include <iostream>

using namespace std;

Base::Base() { //konstruktor wypelnia plansze kropkami
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tab[i][j] = '.';
		}
	}
}

void Base::infoGame() { //informacje o grze, zasady
	cout << "Zasady gry: " << endl;
	cout << "Gra rozgrywa siê na planszy 8x8." << endl;
	cout << "Pionki w pozycji startowej ustawione sa po srodku planszy w pozycji XY oraz linijke nizej YX." << endl;
	cout << "Ukladane sa pionki X lub Y na przemian przez graczy do zapelnienia calej planszy, lub braku pionkow ktoregos z graczy." << endl;
	cout << "Dozwolony ruch jest wtedy, gdy gracz mo¿e przejac pionka przeciwnego gracza." << endl;
	cout << "Pionki mozna przejmowac w pionie, poziomie, oraz ukosnie." << endl;
	cout << endl;
}

void Base::showDesk() { //wyswietlanie aktualnego stanu gry
	printf("%c", ' ');
	for (int i = 0; i < 8; i++) {
		printf("%3d", i);
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << i ;
		for (int j = 0; j < 8; j++) {
			printf("%3c", tab[i][j]);
		}
		cout << endl;
	}
}

void Base::setStartParameters(Player_X* px, Player_Y* py) { //ustawienie poczatkowych parametrow do rozpoczecia gry
	tab[3][3] = 'X';
	tab[4][4] = 'X';
	tab[3][4] = 'Y';
	tab[4][3] = 'Y';

}

bool Base::getFromX(Player_X* px, int x1, int y1) {
	bool check = 0;
	bool checkAll = 0;
	x1 = px->setX();
	y1 = px->setY();
	//1. sprawdz czy podane wspolrzedne sa w przedziale [0,7]
	//2. sprawdz czy pole o podanych wspolrzednych jest puste
	if (tab[x1][y1] != '.')
		check = 0;
	else {
		//3. sprawdz pion
		//sprawdzam pion w dó³
		for (int i = x1 + 1; i < 8; i++) {
			if (tab[i][y1] == 'X') {
				for (int j = x1 + 1; j < i; j++) {
					if (tab[j][y1] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[j][y1] == 'Y') {
						tab[x1][y1] = 'X';
						tab[j][y1] = 'X';
						check = 1;
					}
				}
				if (check == 1)
					break;
			}
		}

		//sprawdzam pion w górê
		for (int i = x1 - 1; i > -1; i--) {
			if (tab[i][y1] == 'X') {
				for (int j = x1 - 1; j > i; j--) {
					if (tab[j][y1] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[j][y1] == 'Y') {
						tab[x1][y1] = 'X';
						tab[j][y1] = 'X';
						check = 1;
					}
				}
				if (check == 1)
					break;
			}
		}

		//4. sprawdz poziom

		//sprawdzam poziom w prawo
		for (int i = y1 + 1; i < 8; i++) {
			if (tab[x1][i] == 'X') {
				for (int j = y1 + 1; j < i; j++) {
					if (tab[x1][j] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[x1][j] == 'Y') {
						tab[x1][y1] = 'X';
						tab[x1][j] = 'X';
						check = 1;
					}
				}
				if (check == 1)
					break;
			}
		}

		//sprawdzam poziom w lewo
		for (int i = y1 - 1; i > -1; i--) {
			if (tab[x1][i] == 'X') {
				for (int j = y1 - 1; j > i; j--) {
					if (tab[x1][j] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[x1][j] == 'Y') {
						tab[x1][y1] = 'X';
						tab[x1][j] = 'X';
						check = 1;
					}
				}
				if (check == 1)
					break;
			}
		}
	}
	//idê w stronê prawy dolny
	for (int i = 1; i + y1 < 8 && i + x1 < 8; i++) {
		if (tab[x1 + i][y1 + i] == 'X') {
			for (int j = 1; j < y1 + i && j < x1 + i; j++) {
				if (tab[x1 + j][y1 + j] == '.') {//sytuacja ze jest puste miedzy polami
					check = 0;
					break;
				}
				if (tab[x1 + j][y1 + j] == 'Y') {
					tab[x1 + j][y1 + j] = 'X';
					tab[x1][y1] = 'X';
					check = 1;
				}
				if (check == 1)
					break;
			}
		}
	}

	//idê w stronê prawy górny
	for (int i = 1; i + y1 < 8 && x1 - i >= 0; i++) {
		if (tab[x1 - i][y1 + i] == 'X') {
			for (int j = 1; j < y1 + i && 7 - j > x1 - i; j++) {
				if (tab[x1 - j][y1 + j] == '.') {//sytuacja ze jest puste miedzy polami
					check = 0;
					break;
				}
				if (tab[x1 - j][y1 + j] == 'Y') {
					tab[x1 - j][y1 + j] = 'X';
					tab[x1][y1] = 'X';
					check = 1;
				}
				if (check == 1)
					break;
			}
		}
	}

	//idê w stronê lewy dolny
	for (int i = 1; y1 - i >= 0 && i + x1 < 8; i++) {
		if (tab[x1 + i][y1 - i] == 'X') {
			for (int j = 1; 7 - j > y1 - i && j < x1 + i; j++) {
				if (tab[x1 + j][y1 - j] == '.') {//sytuacja ze jest puste miedzy polami
					check = 0;
					break;
				}
				if (tab[x1 + j][y1 - j] == 'Y') {
					tab[x1 + j][y1 - j] = 'X';
					tab[x1][y1] = 'X';
					check = 1;
				}
				if (check == 1)
					break;
			}
		}
	}

	//idê w stronê lewy górny
	for (int i = 1; y1 - i >= 0 && x1 - i >= 0; i++) {
		if (tab[x1 - i][y1 - i] == 'X') {
			for (int j = 1; 7 - j > y1 - i && 7 - j > x1 - i; j++) {
				if (tab[x1 - j][y1 - j] == '.') {//sytuacja ze jest puste miedzy polami
					check = 0;
					break;
				}
				if (tab[x1 - j][y1 - j] == 'Y') {
					tab[x1 - j][y1 - j] = 'X';
					tab[x1][y1] = 'X';
					check = 1;
				}
				if (check == 1)
					break;
			}
		}
	}

	if (check == 0)
		cout << "RUCH NIEMOZLIWY!!!!" << endl;
	return checkAll;
}

bool Base::getFromY(Player_Y* py, int x2, int y2) {
	bool check = 0;
	bool checkAll = 0;
	x2 = py->setX();
	y2 = py->setY();
	//1. sprawdz czy podane wspolrzedne sa w przedziale [0,7]
	//2. sprawdz czy pole o podanych wspolrzednych jest puste
	if (tab[x2][y2] != '.')
		check = 0;
	else {
		//3. sprawdz pion
		//sprawdzam pion w dó³
		for (int i = x2 + 1; i < 8; i++) {
			if (tab[i][y2] == 'Y') {
				for (int j = x2 + 1; j < i; j++) {
					if (tab[j][y2] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[j][y2] == 'X') {
						tab[x2][y2] = 'Y';
						tab[j][y2] = 'Y';
						check = 1;
					}
				}
				if (check == 1)
					break;
			}
		}

		//sprawdzam pion w górê
		for (int i = x2 - 1; i > -1; i--) {
			if (tab[i][y2] == 'Y') {
				for (int j = x2 - 1; j > i; j--) {
					if (tab[j][y2] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[j][y2] == 'X') {
						tab[x2][y2] = 'Y';
						tab[j][y2] = 'Y';
						check = 1;
					}
				}
				if (check == 1)
					break;
			}
		}

		//4. sprawdz poziom

		//sprawdzam poziom w prawo
		for (int i = y2 + 1; i < 8; i++) {
			if (tab[x2][i] == 'Y') {
				for (int j = y2 + 1; j < i; j++) {
					if (tab[x2][j] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[x2][j] == 'X') {
						tab[x2][y2] = 'Y';
						tab[x2][j] = 'Y';
						check = 1;
					}
				}
				if (check == 1)
					break;
			}
		}

		//sprawdzam poziom w lewo
		for (int i = y2 - 1; i > -1; i--) {
			if (tab[x2][i] == 'Y') {
				for (int j = y2 - 1; j > i; j--) {
					if (tab[x2][j] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[x2][j] == 'X') {
						tab[x2][y2] = 'Y';
						tab[x2][j] = 'Y';
						check = 1;
					}
				}
				if (check == 1)
					break;
			}
		}
	}

	//idê w stronê prawy dolny
	for (int i = 1; i + y2 < 8 && i + x2 < 8; i++) {
		if (tab[x2 + i][y2 + i] == 'Y') {
			for (int j = 1; j < y2 + i && j < x2 + i; j++) {
				if (tab[x2 + j][y2 + j] == '.') {//sytuacja ze jest puste miedzy polami
					check = 0;
					break;
				}
				if (tab[x2 + j][y2 + j] == 'X') {
					tab[x2 + j][y2 + j] = 'Y';
					tab[x2][y2] = 'Y';
					check = 1;
				}
				if (check == 1)
					break;
			}
		}
	}

	//idê w stronê prawy górny
	for (int i = 1; i + y2 < 8 && x2 - i >= 0; i++) {
		if (tab[x2 - i][y2 + i] == 'Y') {
			for (int j = 1; j < y2 + i && 7 - j > x2 - i; j++) {
				if (tab[x2 - j][y2 + j] == '.') {//sytuacja ze jest puste miedzy polami
					check = 0;
					break;
				}
				if (tab[x2 - j][y2 + j] == 'X') {
					tab[x2 - j][y2 + j] = 'Y';
					tab[x2][y2] = 'Y';
					check = 1;
				}
				if (check == 1)
					break;
			}
		}
	}

	//idê w stronê lewy dolny
	for (int i = 1; y2 - i >= 0 && i + x2 < 8; i++) {
		if (tab[x2 + i][y2 - i] == 'Y') {
			for (int j = 1; 7 - j > y2 - i && j < x2 + i; j++) {
				if (tab[x2 + j][y2 - j] == '.') {//sytuacja ze jest puste miedzy polami
					check = 0;
					break;
				}
				if (tab[x2 + j][y2 - j] == 'X') {
					tab[x2 + j][y2 - j] = 'Y';
					tab[x2][y2] = 'Y';
					check = 1;
				}
				if (check == 1)
					break;
			}
		}
	}

	//idê w stronê lewy górny
	for (int i = 1; y2 - i >= 0 && x2 - i >= 0; i++) {
		if (tab[x2 - i][y2 - i] == 'Y') {
			for (int j = 1; 7 - j > y2 - i && 7 - j > x2 - i; j++) {
				if (tab[x2 - j][y2 - j] == '.') {//sytuacja ze jest puste miedzy polami
					check = 0;
					break;
				}
				if (tab[x2 - j][y2 - j] == 'X') {
					tab[x2 - j][y2 - j] = 'Y';
					tab[x2][y2] = 'Y';
					check = 1;
				}
				if (check == 1)
					break;
			}
		}
	}


	if (check == 0)
		cout << "RUCH NIEMOZLIWY!!!!" << endl;

	return checkAll;
}

bool Base::checkIfComplete() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == '.')
				return 0;
		}
	}
	bool f = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == 'X') {
				f = 1;
			}
			if (f == 1 && tab[i][j] == 'Y') {
				return 0;
			}
			else { return 1; }
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
