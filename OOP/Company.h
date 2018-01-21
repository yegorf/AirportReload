#pragma once
#include "Plane.h"
using std::cout;

class Company
{
	string name;
	Plane *plane;
	string file;
	int col;

public:
	Company();
	void SetFileCom();
	void GetFilePlanes();
	void SetName(string n) { name = n; cout << name << endl; }
	string GetName() { return name; }
	int FileCol();
	void PrintPlanes();
	void AddPlane();
	void DeletePlane();
	void SavePlane();

	~Company();
};

