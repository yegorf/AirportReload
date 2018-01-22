#include "Checker.h"



bool Checker::CheckDate(string date)
{
	string array[3];
	size_t position = 0;
	int index = 0;
	bool isLeap = false;
	bool isValidDate = true;
	int day, month, year;

	while ((position = date.find('.')) != string::npos) {
		string token = date.substr(0, position);
		array[index] = token;
		date.erase(0, position + 1);
		index += 1;
	}
	array[index] = date;

	day = atoi(array[0].c_str());
	month = atoi(array[1].c_str());
	year = atoi(array[2].c_str());

	if (year % 4 == 0) {
		isLeap = true;
	}
	if (day < 1 || day > 31) {
		isValidDate = false;
	}
	if (month < 1 || month > 12) {
		isValidDate = false;
	}
	if (month == 2 && day > 29 && isLeap == true) {
		isValidDate = false;
	}
	if (month == 2 && day > 28 && isLeap == false) {
		isValidDate = false;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			isValidDate = false;
		}
	}

	if (isValidDate) {
		return true;
	}
	else {
		return false;
	}
}

bool Checker::CheckTime(string date)
{
	string array[2];
	size_t position = 0;
	int index = 0;
	bool isLeap = false;
	bool Valid = true;
	int min, hour;

	while ((position = date.find(':')) != string::npos) {
		string token = date.substr(0, position);
		array[index] = token;
		date.erase(0, position + 1);
		index += 1;
	}
	array[index] = date;

	hour = atoi(array[0].c_str());
	min = atoi(array[1].c_str());

	if (hour > 24)
	{
		Valid = false;
	}

	if (min > 60)
	{
		Valid = false;
	}

	if (Valid) {
		return true;
	}
	else {
		return false;
	}
}

bool Checker::CheckNum(string num)
{
	if (num.length() > 3 || num.length() < 3)
	{
		return false;
	}
	else return true;
}