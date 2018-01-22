#include <fstream>
#include "Company.h"
#include <iomanip>
#include "Checker.h"

void Company::SetFileCom()
{
	file = "companies\\" + name + ".txt";
	col = FileCol();
	plane = new Plane[col];
}


void Company::GetFilePlanes()
{
	string a;
	string b;
	string c;
	fstream fn(file);
	for (int i = 0; i < col; i++)
	{
		fn >> a;
		fn >> b;
		fn >> c;
		plane[i].SetNum(a);
		plane[i].SetModel(b);
		plane[i].SetYear(c);
	}
	fn.close();
}

Company::Company()
{
}


Company::~Company()
{
	delete[]plane;
}

int Company::FileCol()
{
	ifstream f(file);
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

void Company::PrintPlanes()
{
	cout << setw(5) << "Номер" << setw(10) << "Модель" << setw(10) << "Выпуск" << endl;
	for (int i = 0; i < col; i++)
	{
		cout << i + 1 << ")" << setw(5) << plane[i].GetNum() << setw(10) << plane[i].GetModel() << setw(15) << plane[i].GetYear() << endl;
	}
}

void Company::AddPlane()
{
	bool check;
	Checker C;
	string n, y, m;
	cout << "Введите данные" << endl;
	do {
		cout << "Номер: ";
		cin >> n;
		check = C.CheckNum(n);
	} while (check == false);
	cout << "Модель: ";
	cin >> m;
	do {
		cout << "Дата выпуска: ";
		cin >> y;
		check = C.CheckDate(y);
	} while (check == false);

	Plane dop(n, m, y);
	Plane *mas = new Plane[col + 1];
	for (int i = 0; i < col; i++)
	{
		mas[i] = plane[i];
	}
	delete[]plane;
	col++;
	plane = new Plane[col];
	for (int i = 0; i <col; i++)
	{
		plane[i] = mas[i];
	}
	plane[col - 1] = dop;
}

void Company::DeletePlane()
{
	int n;
	cout << "Введите номер удаляемой записи" << endl;
	cin >> n;
	for (int i = n - 1; i < col - 1; i++)
	{
		plane[i] = plane[i + 1];
	}
	col--;
}

void Company::SavePlane()
{
	ofstream f(file);
	for (int i = 0; i < col; i++)
	{
		f << plane[i].GetNum() << " " << plane[i].GetModel() << " " << plane[i].GetYear() << endl;
	}
	f.close();
}