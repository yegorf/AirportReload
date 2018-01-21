#pragma once
#include "Passenger.h"
#include "Airport.h"

class Voyage
{
	string time;
	string num;
	Passenger *pas;
	Airport place;
	int pasCol;

public:
	Voyage();
	~Voyage();

	void SetTime(string t) { time = t; }
	void SetNum(string n) { num = n; }
	void SetPlace(string a, string b, string c);
	string GetTime() { return time; }
	string GetNum() { return num; }

	void PrintVoyage();
	void SaveVoy(string file);
	int FileCol(string file);
	void FilePas(string file);
	void PrintPas();
	void AddPas();
	void DeletePas(int i);
	void SavePas(string file);

};

