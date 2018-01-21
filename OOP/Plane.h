#pragma once
#include <iostream>
#include <string>
using namespace std;


class Plane
{
	string num;
	string model;
	string year;

public:
	Plane() {};

	Plane(string a,string b, string c)
	{
		num = a;
		model = b;
		year = c;
	}

	void SetNum(string n) { num = n; }
	void SetModel(string n) { model = n; }
	void SetYear(string n) { year = n; }

	string GetNum() { return num; }
	string GetModel() { return model; }
	string GetYear() { return year; }

	~Plane() {};
};

