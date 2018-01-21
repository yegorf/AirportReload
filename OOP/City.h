#pragma once
#include "Country.h"

class City
{
	string name;
	Country con;

public:

	City(){}

	void SetName(string n) { name = n; }
	string GetName() { return name; }

	void SetConName(string n) { con.SetName(n); }
	string GetConName() { return con.GetName(); }

	~City(){}
};
