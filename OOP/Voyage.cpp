#include "Voyage.h"
#include <fstream>
#include <iomanip>
#include "Checker.h"

Voyage::Voyage()
{
	pasCol = 0;
}


Voyage::~Voyage()
{
}

void Voyage::PrintVoyage()
{
	cout << time << " " << num << " " <<place.GetName()<<" "<<place.GetCityName()<< " " <<place.GetConName()<< endl;
}

void Voyage::SetPlace(string a, string b, string c) 
{
	place.SetName(a);
	place.SetCityName(b);
	place.SetConName(c);
}

void Voyage::SaveVoy(string file)
{
	ofstream f(file, ios::app);
	f << time << " " << num << " " << place.GetName() << " " << place.GetCityName() << " " << place.GetConName() << endl;
	f.close();
}

int Voyage::FileCol(string file)
{
	ifstream f;
	f.open(file);

	char *str = new char[1024];
	int j = 0;
	while (!f.eof())
	{
		f.getline(str, 1024, '\n');
		j++;
	}

	f.close();
	delete str;
	return j-1;
}

void Voyage::FilePas(string file)
{
	pasCol = FileCol(file);
	pas = new Passenger[pasCol];
	string a, b, c;
	ifstream fn(file);
	if (!fn)
	{
		cout << "ERROR" << endl;
	}

	else {
		cout << endl << pasCol << endl;
		for (int i = 0; i < pasCol; i++)
		{
			fn >> a;
			fn >> b;
			fn >> c;
			pas[i].SetName(a);
			pas[i].SetSName(b);
			pas[i].SetBirth(c);
		}
	}
	fn.close();
}

void Voyage::PrintPas()
{
	cout << "Имя" << setw(15) << "Фамилия" << setw(15) << "Дата рождения" << endl;
	for (int i = 0; i < pasCol; i++)
	{
		cout << pas[i].GetName() << setw(10) << pas[i].GetSName() << setw(15) << pas[i].GetBirth() << endl;
	}
}

void Voyage::AddPas()
{
	Checker c;
	bool check=false;
	string n, y, m;
	cout << "Имя: ";
	cin >> n;
	cout << "Фамилия: ";
	cin >> m;
	do {
		cout << "Дата рождения: ";
		cin >> y;
		check = c.CheckDate(y);
	} while (check == false);

	Passenger dop(n, m, y);
	Passenger *mas = new Passenger[pasCol + 1];
	for (int i = 0; i < pasCol; i++)
	{
		mas[i] = pas[i];
	}
	delete[]pas;
	pasCol++;
	pas = new Passenger[pasCol];
	for (int i = 0; i <pasCol; i++)
	{
		pas[i] = mas[i];
	}
	pas[pasCol - 1] = dop;
}

void Voyage::DeletePas(int n)
{
	for (int i = n - 1; i < pasCol - 1; i++)
	{
		pas[i] = pas[i + 1];
	}
	pasCol--;
}

void Voyage::SavePas(string file)
{
	ofstream f(file);

	for (int i = 0; i < pasCol; i++)
	{
		f << pas[i].GetName() << " " << pas[i].GetSName() << " " << pas[i].GetBirth() << endl;
	}
		f.close();
}

