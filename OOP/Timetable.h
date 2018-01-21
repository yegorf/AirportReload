#pragma once
#include "Voyage.h"

class Timetable
{
	Voyage *voy;
	int voyCol;
	string file;

public:
	Timetable();
	Timetable(string f) { file = f; }
	~Timetable();

	int GetVoyCol() { return voyCol; }

	int File();
	void FileTimetable(string f);
	bool Init();
	void PrintTimetable();
	string AddVoyage();
	void AddFilePas(string file);
	void DeleteVoy(int n);
	void SaveVoy();
	void PrintVoyPas(int i);
	void FilePas(int i, string File);
	int FindVoy(string num);
	void AddPas(int n);
	void DeletePas(int num,int n);
	void SavePas(int n, string file);
};

