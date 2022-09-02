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
	cout << "Dozwolony ruch jest wtedy, gdy gracz moze przejac pionka przeciwnego gracza." << endl;
	cout << "Pionki mozna przejmowac w pionie, poziomie, oraz ukosnie." << endl << endl;
	cout << "UWAGA: Jezeli nie widzisz mozliwosci ruszenia sie mozna probowac do momentu az sie uda\nlub oddac swoj ruch wpisujac w ktoras ze wspolrzednych -1" << endl;
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

void Base::setStartParameters(Player_Y* px, Player_Y* py) { //ustawienie poczatkowych parametrow do rozpoczecia gry
	tab[3][3] = 'X';
	tab[4][4] = 'X';
	tab[3][4] = 'Y';
	tab[4][3] = 'Y';

}

bool Base::getFrom(Player_Y* px, int x1, int y1, char moj, char przeciw, int turn) {
	bool check = 0;
	bool checkAll = 0; //ta zmienna sprawdza czy chociaz raz zostalo przjete pole przeciwnika, jezeli tak to zalicza sie ruch
	if (turn == 0) {
		cout << "Podaj wartosc x na ktorej pozycji ustawic gracza X: " << endl;
		x1 = px->setX();
		cout << "Podaj wartosc y na ktorej pozycji ustawic gracza X: " << endl;
		y1 = px->setY();
	}
	if (turn == 1) {
		cout << "Podaj wartosc x na ktorej pozycji ustawic gracza Y: " << endl;
		x1 = px->setX();
		cout << "Podaj wartosc y na ktorej pozycji ustawic gracza Y: " << endl;
		y1 = px->setY();
	}
	//1. sprawdz czy podane wspolrzedne sa w przedziale [0,7]
	//2. sprawdz czy pole o podanych wspolrzednych jest puste
	if (x1 == -1 || y1 == -1) {
		cout << "Gracz X nie widzi ruchu. Traci swoja kolejke." << endl;
		return 1;
	}
	if (tab[x1][y1] != '.')
		check = checkAll = 0;
	else {
		bool possible = 0;
		//3. sprawdz pion
		//sprawdzam pion w dó³
		if (tab[x1 + 1][y1] == przeciw) {
			for (int i = 0; i <= x1 + 1; i++) {
				if (tab[x1 + 1 + i][y1] == moj) {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 0; i <= x1 + 1; i++) {
					if (tab[x1 + 1 + i][y1] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[x1 + i][y1] == przeciw) {
						tab[x1][y1] = moj;
						tab[x1 + i][y1] = moj;
						check = checkAll = 1;
					}
				}
			}
		}

		possible = 0;
		//sprawdzam pion w górê
		if (tab[x1 - 1][y1] == przeciw) {
			for (int i = 0; 7 - i >= x1 - 1; i++) {
				if (tab[x1 - 1 -i][y1] == moj) {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 0; 7 - i >= x1 - 1; i++) {
					if (tab[x1 - 1 -i][y1] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[x1 - i][y1] == przeciw) {
						tab[x1][y1] = moj;
						tab[x1 - i][y1] = moj;
						check = checkAll = 1;
					}
				}
			}
		}
		
		possible = 0;
		//4. sprawdz poziom
		//sprawdzam poziom w prawo
		if (tab[x1][y1 + 1] == przeciw) {
			for (int i = 0; i <= y1 + 1; i++) {
				if (tab[x1][y1 + 1 + i] == moj) {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 0; i <= y1 + 1; i++) {
					if (tab[x1][y1 + 1 + i] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[x1][y1 + i] == przeciw) {
						tab[x1][y1] = moj;
						tab[x1][y1 + i] = moj;
						check = checkAll = 1;
					}
				}
			}
		}
		
		possible = 0;
		//sprawdzam poziom w lewo
		if (tab[x1][y1 - 1] == przeciw) {
			for (int i = 0; 7 - i >= y1 - 1; i++) {
				if (tab[x1][y1 - 1 - i] == moj) {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 0; 7 - i >= y1 - 1; i++) {
					if (tab[x1][y1 - 1 - i] == '.') {//sytuacja ze jest puste miedzy polami
						check = 0;
						break;
					}
					if (tab[x1][y1 - i] == przeciw) {
						tab[x1][y1] = moj;
						tab[x1][y1 - i] = moj;
						check = checkAll = 1;
					}
				}
			}
		}
		

		//5.sprawdzam skosy
		possible = 0;
		//idê w stronê prawy dolny
		if (tab[x1 + 1][y1 + 1] == przeciw) {
			for (int i = 0; i <= y1 + 1 && i <= x1 + 1; i++) {
				if (tab[x1 + 1 + i][y1 + 1 + i] == moj) {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 0; i <= y1 + 1 && i <= x1 + 1; i++) {
					if (tab[x1 + 1 + i][y1 + 1 + i] == '.') {
						check = 0;
						break;
					}
					if (tab[x1 + i][y1 + i] == przeciw) {
						tab[x1 + i][y1 + i] = moj;
						tab[x1][y1] = moj;
						check = checkAll = 1;
					}
				}
			}
		}
		possible = 0;
		//idê w stronê prawy górny
		if (tab[x1 - 1][y1 + 1] == przeciw) {
			for (int i = 0; i <= y1 + 1 && 7 - i >= x1 - 1; i++) {
				if (tab[x1 - 1 - i][y1 + 1 + i] == moj) {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 0; i <= y1 + 1 && 7 - i >= x1 - 1; i++) {
					if (tab[x1 - 1 - i][y1 + 1 + i] == '.') {
						check = 0;
						break;
					}
					if (tab[x1 - i][y1 + i] == przeciw) {
						tab[x1 - i][y1 + i] = moj;
						tab[x1][y1] = moj;
						check = checkAll = 1;
					}
				}
			}
		}
		possible = 0;
		//idê w stronê lewy dolny
		if (tab[x1 + 1][y1 - 1] == przeciw) {
			for (int i = 0; 7 - i >= y1 - i && i <= x1 + 1; i++) {
				if (tab[x1 + 1 + i][y1 - 1 - i] == moj) {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 0; 7 - i >= y1 - 1 && i <= x1 + 1; i++) {
					if (tab[x1 + 1 + i][y1 - 1 - i] == '.') {
						check = 0;
						break;
					}
					if (tab[x1 + i][y1 - i] == przeciw) {
						tab[x1 + i][y1 - i] = moj;
						tab[x1][y1] = moj;
						check = checkAll = 1;
					}
				}
			}
		}
		possible = 0;
		//idê w stronê lewy górny
		if (tab[x1 - 1][y1 - 1] == przeciw) {
			for (int i = 0; 7 - i >= y1 - 1 && 7 - i >= x1 - 1; i++) {
				if (tab[x1 - 1 - i][y1 - 1 - i] == moj) {
					possible = 1;
					break;
				}
			}
			if (possible == 1) {
				for (int i = 0; 7 - i >= y1 - 1 && 7 - i >= x1 - 1; i++) {
					if (tab[x1 - 1 - i][y1 - 1 - i] == '.') {
						check = 0;
						break;
					}
					if (tab[x1 - i][y1 - i] == przeciw) {
						tab[x1 - i][y1 - i] = moj;
						tab[x1][y1] = moj;
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

bool Base::checkIfComplete(Player_Y* px, Player_Y* py) {
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

	for (int i = 0; i < 8; i++) { //czy plansza jest zapelniona
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == '.') {
				f = 0;
			}
		}
	}

	if (x == 1 && y == 1) { //gra sie nie konczy
		f = 0;
	}

	if (x == 0 && y == 1) { //wygral Y
		f = 1;
	}

	if (x == 1 && y == 0) { //wygral X
		f = 1;
	}

	if ((px->get_X() == -1 || px->get_Y() == -1) && (py->get_X() == -1 || py->get_Y() == -1)) {
		f = 1;
	}

	if(f == 1) 
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
