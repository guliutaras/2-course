#include "Root_Methods.h"

int main()
{
	system("CHCP 1251>NUL");
	cout<<"����� ���������� � ������������ ������ �1"<<endl;
	cout<<"�������� ���������:x^3+x-4=0"<<endl;
	while(true)
	{
		cout<<"�������� ����� ��������� �������:"<<endl;
		cout<<"1-����� ������� �������"<<endl;
		cout<<"2-����� ������� ��������"<<endl;
		cout<<"3-����� �����������(�������)"<<endl;
		cout<<"4-����� ����"<<endl;
		cout<<"5-����� �����������(�������) ��� ����������� ���������"<<endl;
		cout<<"0-����� �� ���������"<<endl;
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