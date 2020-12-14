#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>

using namespace std;

void operation(const char* fname, const char* gname, const int N);
void print(const char* gname);

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[101], gname[101];
	cout << "Введіть назву фізичного файлу компонентами якого є дійсні числа: "; cin >> fname; cout << endl;
	cout << "Введіть назву фізичного файлу компонентами, якого не можуть бути значеннями функції 'sinx': "; cin >> gname; cout << endl;

	ofstream file(fname, ios::binary);

	int N;
	cout << "Введіть кількість дійсних чисел: "; cin >> N; cout << endl;

	double x;
	for (int i = 0; i < N; i++)
	{
		x = (200.0 - rand() % 400 * 1.0) * 0.01;
		cout << x << endl;
		file.write((char*)&x, sizeof(double));
	}

	file.close();

	operation(fname, gname, N);
	print(gname);

	return 0;
}

void operation(const char* fname, const char* gname, const int N)
{
	ofstream file_s(gname, ios::binary);
	ifstream file_l(fname, ios::binary);

	int l = 0;
	double y;
	for (int g = 0; g < N; g++)
	{
		file_l.read((char*)&y, sizeof(double));
		if (!(y <= 1 && y >= -1))
			file_s.write((char*)&y, sizeof(double));
	}

	file_s.close();
	file_l.close();
}

void print(const char* gname)
{
	ifstream file_l(gname, ios::binary);

	cout << endl;
	cout << "Компоненти даного файла '" << gname << "' які не можуть бути значеннями функції 'sinx': " << endl << endl;
	double x;
	double l = 4;
	do
	{
		file_l.read((char*)&x, sizeof(double));
		if (x != l)
			cout << x << endl;
		l = x;
	} while (!file_l.eof());
	file_l.close();
}