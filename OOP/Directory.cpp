#include "Directory.h"
#include <fstream>
#include <iomanip>

Directory::Directory()
{
	file = "company.txt";
	colCom = FileCol();
	company = new Company[colCom];
}

void Directory::SavePlane(int i)
{
	i--;
	company[i].SavePlane();
}

void Directory::SetFileCom()
{

	for (int i = 0; i < colCom; i++)
	{
		company[i].SetFileCom();
	}
}

void Directory::GetFilePlanes(int i)
{
	i--;
	company[i].GetFilePlanes();
	company[i].PrintPlanes();
}

int Directory::FileCol()
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
	return j;
}

void Directory::GetFileComp()
{
	string n;
	ifstream fn(file);
	for (int i = 0; i < colCom; i++)
	{
		fn >> n;
		company[i].SetName(n);
	}
	fn.close();
}

void Directory::PrintNames()
{
	cout << "Список всех компаний" << endl << endl;
	for (int i = 0; i < colCom; i++)
	{
		cout << i + 1 << ") " << company[i].GetName() << endl;
	}
}

void Directory::AddPlane(int i)
{
	i--;
	company[i].AddPlane();
}

void Directory::DelPlane(int i)
{
	i--;
	company[i].DeletePlane();
}

Directory::~Directory()
{
	delete[]company;
}