#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "Airport.h"
#include "Directory.h"
#include "Timetable.h"
#include "Checker.h"

int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Checker C;
	Timetable *table;
	Directory *dir;
	char cc;
	int num;
	int A;
	int n;
	string date, datee;
	string a;
	string t = ".txt";
	string tt = "timetables\\";
	string ttt = "registrations\\";
	bool check = false;


	do {
		system("cls");
		cout << "1) Расписание" << endl;
		cout << "2) Регистрация" << endl;
		cout << "3) Компании и самолеты" << endl;
		cout << "4) Информация" << endl;
		cout << "5) Выход" << endl;

		cc = _getch();
		switch (cc)
		{
		case '1':
			do {
			system("cls");

			do {
				cout << "Введите дату: ";
				cin >> date;
				check = C.CheckDate(date);
			} while (check == false);

			datee = tt + date + t;
			table = new Timetable(datee);
			check = table->Init();

			do {
				if (check == true)
				{
					system("cls");
					table->PrintTimetable();
					cout << "1)Добавить рейс" << endl;
					cout << "2)Удалить рейс" << endl;
					cout << "3)Вернуться" << endl;
					cout << "4)Выход" << endl;

					cc = _getch();
					switch (cc)
					{
					case '1':
						a = table->AddVoyage();
						date = ttt + date + "-" + a + ".txt";
						cout << date << endl;
						table->AddFilePas(date);
						break;
					case '2':
						cout<<"Введите номер удаляемой записи: "<<endl;
						cin >> num;
						table->DeleteVoy(num);
						break;
					case '3':
						break;
					}
				table->SaveVoy();
				}
				if (cc == '4') break;
			} while (cc != '3');

			delete table;

		} while (cc != '4');

			system("pause");
			break;


		case '2':
			system("cls");
			cout << "Введите дату рейса: ";
			do {
				cin >> date;
				check = C.CheckDate(date);
			}while(check==false);
			datee = tt + date + t;
			table = new Timetable(datee);
			table->Init();
			table->PrintTimetable();
			do {
				cout << "Введите номер рейса:" << endl;
				cin >> a;
				check = C.CheckNum(a);
			} while (check == false);
			datee = ttt + date + "-" + a + ".txt";  
			cout << endl << datee << endl;
			num = table->FindVoy(a);
			table->FilePas(num, datee);

			do
			{
				system("cls");
				cout << endl << "Пассажиры данного рейса:" << endl;
				table->PrintVoyPas(num);

				cout << "1)Добавить пассажира" << endl;
				cout << "2)Удалить пассажира" << endl;
				cout << "3)Вернуться" << endl;
				cout << "3)Выйти" << endl;
				cc = _getch();
				switch (cc)
				{
				case '1':
					table->AddPas(num);
					break;
				case '2':
					cout << "Введите номер удаляемой записи: " << endl;
					cin >> n;
					table->DeletePas(num,n);
					break;
				case '3':
					break;
				}
				table->SavePas(num, datee);
				if (cc == '4') break;
			} while (cc != '3');

			system("pause");
			break;


		case '3':
			system("cls");
			
			do {
			dir = new Directory;
			dir->GetFileComp();
			dir->SetFileCom();
			dir->PrintNames();

			cout << endl << "Введите номер нужной компании" << endl;
			cin >> num;

			do {
			system("cls");
			dir->GetFilePlanes(num);
			cout << "1)Добавить самолет" << endl;
			cout << "2)Удалить самолет" << endl;
			cout << "3)Вернуться" << endl;
			cout << "4)Выход" << endl;

			cc = _getch();
			switch (cc)
			{
			case '1':
			dir->AddPlane(num);
			break;
			case '2':
			dir->DelPlane(num);
			break;
			case '3':
			break;
			}

			dir->SavePlane(num);
			if (cc == '4') break;
			} while (cc != '3');
			delete dir;
			} while (cc != '4');

			system("pause");
			break;
		case '4':
			cout << "INFO" << endl;
			system("pause");
			break;
		case '5':
			exit(0);
			break;
		}
	} while (true);


	system("pause");
	return 0;
}

