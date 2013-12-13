#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "fstream"
#include <conio.h>
#include <windows.h>
using namespace std;
const int n=7;
enum consolecolor
{
Black	=	0,
Red		=	12,
Yellow	=	14,
LightGray = 7,
Cyan	=	3,
Brown	=	6,
Blue	=	1,
Magenta	=	5,
White	=	15
};
 
void SetColor(consolecolor text, consolecolor background)
{
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void print (char *a, int k)
{
	cout<<endl;
	for (int i=0;i<k;i++)
			cout<<setw(4)<<a[i];
	cout<<endl<<endl;
}
bool ReadMas(char *mas,int k)
{
	ifstream f("mas.txt");
	int i=0;
	if (f)
		while (!f.eof())
		{
			f>>mas[i++];
			if (i==k) break;
		}
	return f;
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus"); 
	HWND handle_w = GetConsoleWindow();
	HDC hDC = GetDC (handle_w);
	char *mas;
	bool A_Z,a_z;
	int n_A=0, n_a=0;
	mas=new char[n];
	if (ReadMas(mas,n))
	{
		print (mas,n);
		for (int i=0;i<n;i++)
		{
			A_Z=(mas[i]>='A') && (mas[i]<='Z');
			a_z=(mas[i]>='a') && (mas[i]<='z');
			if (A_Z||a_z) 
			{
				SetColor(Red, Black);
				cout<<setw(4)<<mas[i];
				if (A_Z)
					n_A++;
				if (a_z)
					n_a++;
			}
			else
			{
				SetColor(LightGray, Black);
				cout<<setw(4)<<mas[i];
			}
		}
		SetColor(LightGray, Black);
		cout<<endl<<"Заглавных букв: "<<n_A
			<<endl<<"Строчных букв: "<<n_a;
	}
	else cout<<"error";
	getch();
	return 0;
}

