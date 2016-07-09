#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int i[10];
	char a[10][50];
	char b[10][50];
	ifstream fin1;
	ofstream fout1;
	fin1.open("IO.txt");
	if (!fin1)
	{
		cout << "열기실패";
		return 0;
	}
	fout1.open("inpictures.txt", ios::out | ios::app);
	if (!fout1)
	{
		cout << "열기실패";
		return 0;
	}
	char tmp[10];
	for (int n = 0; n < 10; n++)
	{
		int num = 0;
		fin1 >> i[n];
		fin1.getline(a[n], 50, ';');
		while (1)
		{
			if (a[n][num] != ' ')
				break;
			num++;
		}
		strcpy(a[n], a[n] + num);
		fin1.getline(b[n], 50);
		num = 0;
		while (1)
		{
			if (b[n][num] != ' ')
				break;
			num++;
		}
		strcpy(b[n], b[n] + num);
		cout << "year : "<<i[n] << endl << "title : " << a[n] << endl<< "director : " << b[n] << endl;
		fout1 << i[n];
		fout1 << '_';
		fout1 << a[n];
		fout1 << ';';
		fout1 << b[n] << endl;
	}
}

