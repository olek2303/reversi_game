#pragma once 

class File {
	char nazwa[20];
public:
	File();
	void setNazwa(char n[20]);
	char* getNazwa();
	void addToFile(int pkt, int winOrLose);
	void readFile(char n[20]);
	~File() { };
};