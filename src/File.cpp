#define _CRT_SECURE_NO_WARNINGS
#include "File.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

File::File() {
	strcpy(nazwa, "guest.txt");
}

void File::setNazwa(char n[20]) {
	strcpy(nazwa, n);
	strcat(nazwa, ".txt");
}

char* File::getNazwa() {
	return nazwa;
}

void File::addToFile(int pkt) {
	fstream in;
	in.open(nazwa, ios::app);
	if (!(in.is_open())) {
		cout << "Nie udalo sie otworzyc takiego pliku.";
		exit(0);
	}
	in << "ilosc uzyskanych punktow: " << pkt << endl;
	in.close();
}