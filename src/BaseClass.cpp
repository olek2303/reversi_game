#define _CRT_SECURE_NO_WARNINGS
#include "BaseClass.hpp"
#include <iostream>

using namespace std;

Base::Base() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tab[i][j] = '.';
		}
	}
}

void Base::infoGame() {
	cout << "GAME RULES: " << endl;
	cout << "1. We have 8x8 board, where we can see two X and two Y in the middle of the board." << endl;
	cout << "2. " << endl;
	cout << "3. " << endl;
	cout << "4. " << endl;
}

void Base::showDesk() {
	cout << "DDDD" << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%3c", tab[i][j]);
		}
		cout << endl;
	}
}

void Base::setStartParameters(Player_X* px, Player_Y* py) {
	int x = px->get_X();
	int y = px->get_Y();
	tab[x][y] = 'X';
	x = py->get_X();
	y = py->get_X();
	tab[x][y] = 'Y';
}

void Base::getFromX(Player_X* px, int x1, int y1) {
	bool check = 0;
	while (check == 0) {
		x1 = px->setX();
		y1 = px->setY();
		if (tab[x1 - 1][y1 - 1] == 'X' && tab[x1][y1] == '.' && x1 - 1 >= 0 && y1 - 1 >= 0) {
			tab[x1][y1] = 'X';
			cout << "Mozesz postawic tu swoj Y" << endl;
			for (int i = x1 - 1; i >= 0; i--) {
				for (int j = y1 - 1; j >= 0; j--) {
					if (tab[i][j] == 'Y') {
						int c1 = i;
						int c2 = j;
						while (tab[c1][c2] == 'Y' || (c1 >= 0 && c2 >= 0)) {
							if (tab[c1][c2] == 'X') {
								//przejmij dotychczasowe pola 
								while (c1 != x1) {
									tab[c1][c2] = 'X';
									c1++;
									c2++;
								}
								break;
							}
							c1--;
							c2--;
						}
					}
				}
			}
			check = 1;
		}
		else if (tab[x1][y1 - 1] == 'X' && tab[x1][y1] == '.' && y1 - 1 >= 0) {
			tab[x1][y1] = 'X';
			for (int j = y1 - 1; j >= 0; j--) {
				if (tab[x1][j] == 'Y') {
					int c = j;
					while (tab[x1][c] == 'Y' || c >= 0) {
						if (tab[x1][c] == 'X') {
							while (c != x1) {
								tab[x1][c] = 'X';
								c++;
							}
							break;
						}
						c--;
					}
				}
			}
			check = 1;
		}
		else if (tab[x1 - 1][y1] == 'X' && tab[x1][y1] == '.' && x1 - 1 >= 0) {
			tab[x1][y1] = 'X';
			for (int i = y1 - 1; i >= 0; i--) {
				if (tab[i][y1] == 'X') {
					int c = i;
					while (tab[c][y1] == 'Y' || c >= 0) {
						if (tab[c][y1] == 'X') {
							while (c != x1) {
								tab[c][y1] = 'X';
								c++;
							}
							break;
						}
						c--;
					}
				}
			}
			check = 1;
		}
		else if (tab[x1 + 1][y1 + 1] == 'X' && tab[x1][y1] == '.' && x1 + 1 < 8 && y1 + 1 < 8) {
			tab[x1][y1] = 'X';
			cout << "Mozesz postawic tu swoj Y" << endl;
			for (int i = x1 + 1; i < 8; i++) {
				for (int j = y1 + 1; j < 8; j++) {
					if (tab[i][j] == 'Y') {
						int c1 = i;
						int c2 = j;
						while (tab[c1][c2] == 'Y' || (c1 >= 0 && c2 >= 0)) {
							if (tab[c1][c2] == 'X') {
								//przejmij dotychczasowe pola 
								while (c1 != x1) {
									tab[c1][c2] = 'Y';
									c1--;
									c2--;
								}
								break;
							}
							c1++;
							c2++;
						}
					}
				}
			}
			check = 1;
		}
		else if (tab[x1][y1 + 1] == 'X' && tab[x1][y1] == '.' && y1 + 1 < 8) {
			tab[x1][y1] = 'X';
			for (int j = y1 + 1; j < 8; j++) {
				if (tab[x1][j] == 'Y') {
					int c = j;
					while (tab[x1][c] == 'Y' || c >= 0) {
						if (tab[x1][c] == 'X') {
							while (c != x1) {
								tab[x1][c] = 'X';
								c--;
							}
							break;
						}
						c++;
					}
				}
			}
			check = 1;
		}
		else if (tab[x1 + 1][y1] == 'X' && tab[x1][y1] == '.' && x1 + 1 < 8) {
		tab[x1][y1] = 'X';
			for (int i = x1 + 1; i < 8; i++) {
				if (tab[i][y1] == 'Y') {
					int c = i;
					while (tab[c][y1] == 'Y' || c >= 0) {
						if (tab[c][y1] == 'X') {
							while (c != x1) {
								tab[c][y1] = 'X';
								c--;
							}
							break;
						}
						c++;
					}
				}
			}
			check = 1;
		}
		else if (tab[x1 + 1][y1 - 1] == 'X' && tab[x1][y1] == '.' && x1 + 1 < 8 && y1 - 1 >= 0) {
			tab[x1][y1] = 'X';
			cout << "Mozesz postawic tu swoj Y" << endl;
			for (int i = x1 + 1; i < 8; i++) {
				for (int j = y1 - 1; j >= 0; j--) {
					if (tab[i][j] == 'Y') {
						int c1 = i;
						int c2 = j;
						while (tab[c1][c2] == 'Y' || (c1 >= 0 && c2 >= 0)) {
							if (tab[c1][c2] == 'X') {
								//przejmij dotychczasowe pola 
								while (c1 != x1) {
									tab[c1][c2] = 'X';
									c1--;
									c2++;
								}
								break;
							}
							c1++;
							c2--;
						}
					}
				}
			}
			check = 1;
		}
		else if (tab[x1 - 1][y1 + 1] == 'X' && tab[x1][y1] == '.' && y1 + 1 < 8 && x1 - 1 >= 0) {
			tab[x1][y1] = 'X';
			cout << "Mozesz postawic tu swoj Y" << endl;
			for (int i = x1 - 1; i >= 0; i--) {
				for (int j = y1 + 1; j < 8; j++) {
					if (tab[i][j] == 'Y') {
						int c1 = i;
						int c2 = j;
						while (tab[c1][c2] == 'Y' || (c1 >= 0 && c2 >= 0)) {
							if (tab[c1][c2] == 'X') {
								//przejmij dotychczasowe pola 
								while (c1 != x1) {
									tab[c1][c2] = 'X';
									c1++;
									c2--;
								}
								break;
							}
							c1--;
							c2++;
						}
					}
				}
			}
			check = 1;
		}
		else {
		cout << "NIE MOZESZ W TAKI SPOSOB WYKONAC SWOJEGO RUCHU, SPROBUJ PONOWNIE" << endl;
			check = 0;
		}
	}
}

void Base::getFromY(Player_Y* py, int x2, int y2) {

	bool check = 0;
	while (check == 0) {
		x2 = py->setX();
		y2 = py->setY();
		if (tab[x2 - 1][y2 - 1] == 'Y' && tab[x2][y2] == '.' && x2 - 1 >= 0 && y2 - 1 >= 0) {
			tab[x2][y2] = 'Y';
			cout << "Mozesz postawic tu swoj Y" << endl;
			for (int i = x2 - 1; i >= 0; i--) {
				for (int j = y2 - 1; j >= 0; j--) {
					if (tab[i][j] == 'X') {
						int c1 = i;
						int c2 = j;
						while (tab[c1][c2] == 'X' || (c1 >= 0 && c2 >= 0)) {
							if (tab[c1][c2] == 'Y') {
								//przejmij dotychczasowe pola 
								while (c1 != x2) {
									tab[c1][c2] = 'Y';
									c1++;
									c2++;
								}
								break;
							}
							c1--;
							c2--;
						}
					}
				}
			}
			check = 1;
		}
		else if (tab[x2][y2 - 1] == 'Y' && tab[x2][y2] == '.' && y2 - 1 >= 0) {
			tab[x2][y2] = 'Y';
			for (int j = y2 - 1; j >= 0; j--) {
				if (tab[x2][j] == 'X') {
					int c = j;
					while (tab[x2][c] == 'X' || c >= 0) {
						if (tab[x2][c] == 'Y') {
							while (c != x2) {
								tab[x2][c] = 'Y';
								c++;
							}
							break;
						}
						c--;
					}
				}
			}
			check = 1;
		}
		else if (tab[x2 - 1][y2] == 'Y' && tab[x2][y2] == '.' && x2 - 1 >= 0) {
			tab[x2][y2] = 'Y';
			for (int i = y2 - 1; i >= 0; i--) {
				if (tab[i][y2] == 'X') {
					int c = i;
					while (tab[c][y2] == 'X' || c >= 0) {
						if (tab[c][y2] == 'Y') {
							while (c != x2) {
								tab[c][y2] = 'Y';
								c++;
							}
							break;
						}
						c--;
					}
				}
			}
			check = 1;
		}
		else if (tab[x2 + 1][y2 + 1] == 'Y' && tab[x2][y2] == '.' && x2 + 1 < 8 && y2 + 1 < 8) {
			tab[x2][y2] = 'Y';
			cout << "Mozesz postawic tu swoj Y" << endl;
			for (int i = x2 + 1; i < 8; i++) {
				for (int j = y2 + 1; j < 8; j++) {
					if (tab[i][j] == 'X') {
						int c1 = i;
						int c2 = j;
						while (tab[c1][c2] == 'X' || (c1 >= 0 && c2 >= 0)) {
							if (tab[c1][c2] == 'Y') {
								//przejmij dotychczasowe pola 
								while (c1 != x2) {
									tab[c1][c2] = 'Y';
									c1--;
									c2--;
								}
								break;
							}
							c1++;
							c2++;
						}
					}
				}
			}
			check = 1;
		}
		else if (tab[x2][y2 + 1] == 'Y' && tab[x2][y2] == '.' && y2 + 1 < 8) {
			tab[x2][y2] = 'Y';
			for (int j = y2 + 1; j < 8; j++) {
				if (tab[x2][j] == 'X') {
					int c = j;
					while (tab[x2][c] == 'X' || c >= 0) {
						if (tab[x2][c] == 'Y') {
							while (c != x2) {
								tab[x2][c] = 'Y';
								c--;
							}
							break;
						}
						c++;
					}
				}
			}
			check = 1;
		}
		else if (tab[x2 + 1][y2] == 'Y' && tab[x2][y2] == '.' && x2 + 1 < 8) {
			tab[x2][y2] = 'Y';
			for (int i = x2 + 1; i < 8; i++) {
				if (tab[i][y2] == 'X') {
					int c = i;
					while (tab[c][y2] == 'X' || c >= 0) {
						if (tab[c][y2] == 'Y') {
							while (c != x2) {
								tab[c][y2] = 'Y';
								c--;
							}
							break;
						}
						c++;
					}
				}
			}
			check = 1;
		}
		else if (tab[x2 + 1][y2 - 1] == 'Y' && tab[x2][y2] == '.' && x2 + 1 < 8 && y2 - 1 >= 0) {
			tab[x2][y2] = 'Y';
			cout << "Mozesz postawic tu swoj Y" << endl;
			for (int i = x2 + 1; i < 8; i++) {
				for (int j = y2 - 1; j >= 0; j--) {
					if (tab[i][j] == 'X') {
						int c1 = i;
						int c2 = j;
						while (tab[c1][c2] == 'X' || (c1 >= 0 && c2 >= 0)) {
							if (tab[c1][c2] == 'Y') {
								//przejmij dotychczasowe pola 
								while (c1 != x2) {
									tab[c1][c2] = 'Y';
									c1--;
									c2++;
								}
								break;
							}
							c1++;
							c2--;
						}
					}
				}
			}
			check = 1;
		}
		else if (tab[x2 - 1][y2 + 1] == 'Y' && tab[x2][y2] == '.' && y2 + 1 < 8 && x2 - 1 >= 0) {
			tab[x2][y2] = 'Y';
			cout << "Mozesz postawic tu swoj Y" << endl;
			for (int i = x2 - 1; i >= 0; i--) {
				for (int j = y2 + 1; j < 8; j++) {
					if (tab[i][j] == 'X') {
						int c1 = i;
						int c2 = j;
						while (tab[c1][c2] == 'X' || (c1 >= 0 && c2 >= 0)) {
							if (tab[c1][c2] == 'Y') {
								//przejmij dotychczasowe pola 
								while (c1 != x2) {
									tab[c1][c2] = 'Y';
									c1++;
									c2--;
								}
								break;
							}
							c1--;
							c2++;
						}
					}
				}
			}
			check = 1;
		}
		else {
			cout << "NIE MOZESZ W TAKI SPOSOB WYKONAC SWOJEGO RUCHU, SPROBUJ PONOWNIE" << endl;
			check = 0;
		}
	}
}

bool Base::checkIfComplete() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] == '.')
				return 0;
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
