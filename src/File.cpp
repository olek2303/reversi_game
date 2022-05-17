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
	strcpy(nazwa, ".txt");
}

char* File::getNazwa() {
	return nazwa;
}

void File::openFile() {
	fstream in;
	
}