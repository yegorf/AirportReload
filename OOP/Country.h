#pragma once
#include <iostream>
#include <string>
using namespace std;


class Country
{
	string name;

public:
	Country() {};

	void SetName(string n) { name = n; }
	string GetName() { return name; }

	~Country() {};
};
