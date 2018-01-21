#pragma once
#include "City.h"

class Airport
{
	string name;
	City city;

public:
	Airport() {};

	Airport(string a, string b, string c)
	{
		name = a;
		city.SetName(b);
		city.SetConName(c);
	}

	void SetName(string n) { name = n; }
	void SetCityName(string n) { city.SetName(n); }
	void SetConName(string n) { city.SetConName(n); }

	string GetName() { return name; }
	string GetCityName() { return city.GetName(); }
	string GetConName() { return city.GetConName(); }

	~Airport() {};
};

