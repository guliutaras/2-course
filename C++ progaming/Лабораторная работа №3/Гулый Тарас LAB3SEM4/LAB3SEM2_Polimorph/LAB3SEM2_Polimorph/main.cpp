#include "graphics_in_console.h"

void ListOptions(ShapeList L);

int main() 
{
	ShapeList Main_List;
	system("CHCP 1251>NUL");
	cout<<"��� ������������ ������������ ������ �3 �������� 2"<<endl;
	ListOptions(Main_List);
	return 0;
}

void ListOptions(ShapeList L)
{
	while(true)
	{
	cout<<"���� ������ �� ������� �����"<<endl;
	cout<<"1-�������� ������"<<endl;
	cout<<"2-������� ������"<<endl;
	cout<<"3-������ � ���������� �������"<<endl;
	cout<<"4-������� ������������ � ����"<<endl;
	cout<<"5-��������� ������������ �� ����"<<endl;
	cout<<"6-�������� ������ �������"<<endl;
	cout<<"0-����� �� ��������"<<endl;
		switch(getch())
		{
		case'1':
			{
				L.ShapeMode();
				system("cls");
				continue;
			}
		case'2':
			{
				if (L.Empty()) {cout<<"��� ��� �� ����� ������!"<<endl; system("pause"); system("cls"); continue;}
				else L.Deleteing(L.Choosing());
				system("cls");
				continue;
			}
		case'3':
			{
				if (L.Empty()) {cout<<"��� ��� �� ����� ������!"<<endl; system("pause"); system("cls"); continue;}
				else 
				{

					ShapeElem *ss=(L.Choosing());
					Shape* s=ss->shape->copy();
					ShapeOption(ss->shape);
					cout<<"�� ������ ������� �������������� ����� ������?"<<endl;
					cout<<"1-��, 2-���"<<endl;
					if(getch()=='1')
					{
						Shape* temp= ss->shape;
						ss->shape=s;
						delete temp;
					}
				}
				system("cls");
				continue;
			}
		case'4':
			{
				if (L.Empty()) {cout<<"��� ��� �� ����� ������!"<<endl; system("pause"); system("cls"); continue;}
				L.cashout();
				system("cls");
				continue;
			}
		case'5':
			{
				system("cls");
				char name[256];
				ifstream fin;
				cout<<"������� ��� �����"<<endl;
				cin>>name;
				fin.open(name);
				cashin(fin,L);
				system("cls");
				continue;
			}
		case'6':
			{
				if (L.Empty()) {cout<<"��� ��� �� ����� ������!"<<endl; system("pause"); system("cls"); continue;}
				AgregMode(L);
				system("cls");
				continue;
			}
		case'0':{return;}
		default:{system("cls"); continue;}
		}
	}

}


