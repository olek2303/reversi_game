#define _CRT_SECURE_NO_WARNINGS
#include "File.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

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

void File::addToFile(int pkt, int winOrLose) {
	char kom[30] = { '\0' };
	if (winOrLose == 1) {
		strcpy(kom, "WYGRANA");
	} 
	if (winOrLose == 0) {
		strcpy(kom, "PRZEGRANA");
	} 
	if (winOrLose == 2) {
		strcpy(kom, "REMIS");
	}
	
	fstream in;
	time_t t;
	tm* curr;
	char date[100];
	time(&t);
	curr = localtime(&t);
	strftime(date, 50, "%B %d, %Y | %T", curr);

	in.open(nazwa, ios::app);
	if (!(in.is_open())) {
		cout << "Nie udalo sie otworzyc takiego pliku.";
		exit(0);
	}
	in << kom << ", ilosc uzyskanych punktow: " << pkt << ",  " << date << endl;
	in.close();
}

void File::readFile(char n[20]) {
	fstream in;
	char nazwa[30] = { '\0' };
	strcpy(nazwa, n);
	strcat(nazwa, ".txt");
	in.open(nazwa, ios::in);
	if (!(in.is_open())) {
		cout << "Nie udalo sie otworzyc pliku. ";
		exit(0);
	}
	string line;
	getline(in, line);
	while (!in.eof()) {
		cout << line << endl;
		getline(in, line);
	}
	in.close();
}