#pragma once
#include <iostream>
using namespace std;

class Passenger
{
	string name;
	string s_name;
	string birth;

public:
	Passenger() {};
	Passenger(string n, string sn, string b) 
	{
		name = n; s_name = sn; birth = b;
	}
	void SetName(string n) { name = n; }
	void SetSName(string n) { s_name = n; }
	void SetBirth(string b) { birth = b; }

	string GetName() { return name; }
	string GetSName() { return s_name; }
	string GetBirth() { return birth; }

	~Passenger() {};
};

