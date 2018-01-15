#include "Root_Methods.h"

int main()
{
	system("CHCP 1251>NUL");
	cout<<"Добро пожаловать в лабораторную работу №1"<<endl;
	cout<<"Исходное уравнение:x^3+x-4=0"<<endl;
	while(true)
	{
		cout<<"Выберите метод числового анализа:"<<endl;
		cout<<"1-Метод деления пополам"<<endl;
		cout<<"2-Метод простой итерации"<<endl;
		cout<<"3-Метод касательных(Ньютона)"<<endl;
		cout<<"4-Метод хорд"<<endl;
		cout<<"5-Метод касательных(Ньютона) для нелинейного уравнения"<<endl;
		cout<<"0-Выход из программы"<<endl;
		switch(getch())
		{
		case'1':{Half_metod();  getch(); system("cls"); continue;}
		case'2':{Simple_metod(); getch(); system("cls"); continue;}
		case'3':{Newton_metod(); getch(); system("cls"); continue;}
		case'4':{Chord_metod(); getch(); system("cls"); continue;}
		case'5':{Newton_metod_nolin(); getch(); system("cls"); continue;}
		case'0':{return 0;}
		}
	}
}