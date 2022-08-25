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
	cout << "Gra rozgrywa sie na planszy 8x8." << endl;
	cout << "Pionki w pozycji startowej ustawione sa po srodku planszy w pozycji XY oraz linijke nizej YX." << endl;
	cout << "Ukladane sa pionki X lub Y na przemian przez graczy do zapelnienia calej planszy, lub braku pionkow ktoregos z graczy." << endl;
	cout << "Dozwolony ruch jest wtedy, gdy gracz mo¿e przejac pionka przeciwnego gracza." << endl;
	cout << "Pionki mozna przejmowac w pionie, poziomie, oraz ukosnie." << endl;
	cout << endl;
}

void Base::showDesk() { //wyswietlanie aktualnego stanu gry
	printf("%c", ' ');
	for (int i = 0; i < 8; i++) {
		printf("%3d", i); //wyswietlanie na szerokosci 3 miejsc
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << i ;
		for (int j = 0; j < 8; j++) {
			printf("%3c", tab[i][j]); //wyswietlanie na szerokosci 3 miejsc
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
	bool checkAll = 0; //ta zmienna sprawdza czy chociaz raz zostalo przjete pole przeciwnika, jezeli tak to zalicza sie ruch
	x1 = px->setX();
	y1 = px->setY();
	//1. sprawdz czy podane wspolrzedne sa w przedziale [0,7]
	//2. sprawdz czy pole o podanych wspolrzednych jest puste
	if (tab[x1][y1] != '.')
		check = checkAll = 0;
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
						check = checkAll = 1;
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
						check = checkAll = 1;
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
						check = checkAll = 1;
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
						check = checkAll = 1;
					}
				}
				if (check == 1)
					break;
			}
		}

		//5.sprawdzam skosy
		bool possible = 0;
		//idê w stronê prawy dolny
		if (tab[x1 + 1][y1 + 1] == 'Y') {
			for (int i = 1; i <= y1 + 1 && i <= x1 + 1; i++) {
				if (tab[x1 + i][y1 + i] == 'X') {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 1; i <= y1 + 1 && i <= x1 + 1; i++) {
					if (tab[x1 + 1 + i][y1 + 1 + i] == '.') {
						check = 0;
						break;
					}
					if (tab[x1 + i][y1 + i] == 'Y') {
						tab[x1 + i][y1 + i] = 'X';
						tab[x1][y1] = 'X';
						check = checkAll = 1;
					}
				}
			}
		}
		possible = 0;
		//idê w stronê prawy górny
		if (tab[x1 - 1][y1 + 1] == 'Y') {
			for (int i = 1; i <= y1 + 1 && 7 - i >= x1 - 1; i++) {
				if (tab[x1 - i][y1 + i] == 'X') {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 1; i <= y1 + 1 && 7 - i >= x1 - 1; i++) {
					if (tab[x1 - 1 - i][y1 + 1 + i] == '.') {
						check = 0;
						break;
					}
					if (tab[x1 - i][y1 + i] == 'Y') {
						tab[x1 - i][y1 + i] = 'X';
						tab[x1][y1] = 'X';
						check = checkAll = 1;
					}
				}
			}
		}
		possible = 0;
		//idê w stronê lewy dolny
		if (tab[x1 + 1][y1 - 1] == 'Y') {
			for (int i = 1; 7 - i >= y1 - i && i <= x1 + i; i++) {
				if (tab[x1 + i][y1 - i] == 'X') {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 1; 7 - i >= y1 - i && i <= x1 + i; i++) {
					if (tab[x1 + 1 + i][y1 - 1 - i] == '.') {
						check = 0;
						break;
					}
					if (tab[x1 + i][y1 - i] == 'Y') {
						tab[x1 + i][y1 - i] = 'X';
						tab[x1][y1] = 'X';
						check = checkAll = 1;
					}
				}
			}
		}
		possible = 0;
		//idê w stronê lewy górny
		if (tab[x1 - 1][y1 - 1] == 'Y') {
			for (int i = 1; 7 - i >= y1 - 1 && 7 - i >= x1 - 1; i++) {
				if (tab[x1 - i][y1 - i] == 'X') {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 1; 7 - i >= y1 - 1 && 7 - i >= x1 - 1; i++) {
					if (tab[x1 - 1 - i][y1 - 1 - i] == '.') {
						check = 0;
						break;
					}
					if (tab[x1 - i][y1 - i] == 'Y') {
						tab[x1 - i][y1 - i] = 'X';
						tab[x1][y1] = 'X';
						check = checkAll = 1;
					}
				}
			}
		}
	}
	
	if (checkAll == 0) {
		cout << "RUCH NIEMOZLIWY!!!!" << endl;
	}
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
		check = checkAll = 0;
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
						check = checkAll = 1;
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
						check = checkAll = 1;
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
						check = checkAll = 1;
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
						check = checkAll = 1;
					}
				}
				if (check == 1)
					break;
			}
		}

		//5.sprawdzam skosy
		bool possible = 0;
		//idê w stronê prawy dolny
		if (tab[x2 + 1][y2 + 1] == 'X') {
			for (int i = 1; i <= y2 + 1 && i <= x2 + 1; i++) {
				if (tab[x2 + i][y2 + i] == 'Y') {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 1; i <= y2 + 1 && i <= x2 + 1; i++) {
					if (tab[x2 + 1 + i][y2 + 1 + i] == '.') {
						check = 0;
						break;
					}
					if (tab[x2 + i][y2 + i] == 'X') {
						tab[x2 + i][y2 + i] = 'Y';
						tab[x2][y2] = 'Y';
						check = checkAll = 1;
					}
				}
			}
		}
		
		possible = 0;
		//idê w stronê prawy górny
		if (tab[x2 - 1][y2 + 1] == 'X') {
			for (int i = 1; i <= y2 + 1 && 7 - i >= x2 - 1; i++) {
				if (tab[x2 - i][y2 + i] == 'Y') {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 1; i <= y2 + 1 && 7 - i >= x2 - 1; i++) {
					if (tab[x2 - 1 - i][y2 + 1 + i] == '.') {
						check = 0;
						break;
					}
					if (tab[x2 - i][y2 + i] == 'X') {
						tab[x2 - i][y2 + i] = 'Y';
						tab[x2][y2] = 'Y';
						check = checkAll = 1;
					}
				}
			}
		}
		possible = 0;
		//idê w stronê lewy dolny
		if (tab[x2 + 1][y2 - 1] == 'X') {
			for (int i = 1; 7 - i >= y2 - 1 && i <= x2 + 1; i++) {
				if (tab[x2 + i][y2 - i] == 'Y') {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 1; 7 - i >= y2 - 1 && i <= x2 + 1; i++) {
					if (tab[x2 + 1 + i][y2 - 1 - i] == '.') {
						check = 0;
						break;
					}
					if (tab[x2 + i][y2 - i] == 'X') {
						tab[x2 + i][y2 - i] = 'Y';
						tab[x2][y2] = 'Y';
						check = checkAll = 1;
					}
				}
			}
		}
		possible = 0;
		//idê w stronê lewy górny
		if (tab[x2 - 1][y2 - 1] == 'X') {
			for (int i = 1; 7 - i >= y2 - 1 && 7 - i >= x2 - 1; i++) {
				if (tab[x2 - i][y2 - i] == 'Y') {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 1; 7 - i >= y2 - 1 && 7 - i >= x2 - 1; i++) {
					if (tab[x2 - 1 - i][y2 - 1 - i] == '.') {
						check = 0;
						break;
					}
					if (tab[x2 - i][y2 - i] == 'X') {
						tab[x2 - i][y2 - i] = 'Y';
						tab[x2][y2] = 'Y';
						check = checkAll = 1;
					}
				}
			}
		}
	}

	if (checkAll == 0) {
		cout << "RUCH NIEMOZLIWY!!!!" << endl;
	}
	return checkAll;
}

bool Base::checkIfComplete() {
	bool x = 0;
	bool y = 0;
	bool f = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == 'X') {
				x = 1;
			}
			if (tab[i][j] == 'Y') {
				y = 1;
			}
		} 
	}

	if (x == 1 && y == 1) { //gra sie nie konczy
		return 0;
	}

	if (x == 0 && y == 1) { //wygral Y
		return 1;
	}

	if (x == 1 && y == 0) { //wygral X
		return 1;
	}

	for (int i = 0; i < 8; i++) { //czy plansza jest zapelniona
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == '.')
				f = 0;
		}
	}

	cout << "Koniec gry" << endl;
 
	return f;
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
