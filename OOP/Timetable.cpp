#include "Timetable.h"
#include <fstream>
#include "conio.h"

Timetable::Timetable()
{
}


Timetable::~Timetable()
{
}


void Timetable::PrintTimetable()
{
	for (int i = 0; i < voyCol; i++)
	{
		cout << "���� #" << i + 1 << " ";
		voy[i].PrintVoyage();
	}
}

bool Timetable::Init()
{
	bool check = true;

	fstream f(file);
	ofstream ofs;
	if (!f)
	{
		cout << "������ ���������� ��� ���. �������?" << endl << "1)��" << endl << "2)���" << endl;
	}
	char c = _getch();
	switch (c)
	{
	case '1':
		ofs.open(file);
		ofs.close();
		check = true;
		break;
	case '2':
		check = false;
		break;
	}
	if (check == true)
	{
		voyCol = File();
		voy = new Voyage[voyCol];
		FileTimetable(file);
	}
	return check;
}

int Timetable::File()
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

void Timetable::FileTimetable(string f)
{
	string b, l;
	string a, c, d;
	ifstream fn(f);
	for (int i = 0; i < voyCol; i++)
	{
		fn >> a;
		fn >> b;
		fn >> c;
		fn >> d;
		fn >> l;
		voy[i].SetTime(a);
		voy[i].SetPlace(c, d, l);
		voy[i].SetNum(b);
	}
	fn.close();
}

string Timetable::AddVoyage()
{
	Voyage dop;
	string time, city, country, air;
	string num;
	cout << "������� �����";cin>>time;
	cout << "������� ����� �����: ";cin >> num;
	cout << "������� ��� ���������: ";cin >> air;
	cout << "������� �����: ";cin >> city;
	cout << "������� ������: "; cin >> country;
	
	dop.SetTime(time);
	dop.SetPlace(city, country, air);
	dop.SetNum(num);

	Voyage *mas = new Voyage[voyCol + 1];
	for (int i = 0; i < voyCol; i++)
	{
		mas[i] = voy[i];
	}
	delete[]voy;
	voyCol++;
	voy = new Voyage[voyCol];
	for (int i = 0; i < voyCol; i++)
	{
		voy[i] = mas[i];
	}
	voy[voyCol - 1] = dop;
	return dop.GetNum();
}

void Timetable::AddFilePas(string file)
{
	ofstream ofs(file);
	ofs.close();
}

void Timetable::DeleteVoy(int n)
{
	for (int i = n - 1; i < voyCol - 1; i++)
	{
		voy[i] = voy[i + 1];
	}
	voyCol--;
}

void Timetable::SaveVoy()
{
	ofstream f(file);
	f.write("", 0);
	for (int i = 0; i < voyCol; i++)
	{
		voy[i].SaveVoy(file);
	}
	f.close();
}

void Timetable::FilePas(int i, string File)
{
	voy[i].FilePas(File);
}

void Timetable::PrintVoyPas(int i)
{
	voy[i].PrintPas();
}

int Timetable::FindVoy(string n)
{
	for (int i = 0; i < voyCol; i++)
	{
		if (voy[i].GetNum() == n) return i;
	}
}

void Timetable::AddPas(int n)
{
	voy[n].AddPas();
}

void Timetable::DeletePas(int num,int n)
{
	voy[num].DeletePas(n);
}

void Timetable::SavePas(int n,string file)
{
	voy[n].SavePas(file);
}