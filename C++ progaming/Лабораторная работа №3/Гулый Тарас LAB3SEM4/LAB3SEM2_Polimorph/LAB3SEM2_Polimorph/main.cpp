#include "graphics_in_console.h"

void ListOptions(ShapeList L);

int main() 
{
	ShapeList Main_List;
	system("CHCP 1251>NUL");
	cout<<"Вас приветствует лабораторная работа №3 семестра 2"<<endl;
	ListOptions(Main_List);
	return 0;
}

void ListOptions(ShapeList L)
{
	while(true)
	{
	cout<<"Меню работы со списокм фигур"<<endl;
	cout<<"1-Добавить фигуру"<<endl;
	cout<<"2-Удалить фигуру"<<endl;
	cout<<"3-Работа с конкретной фигурой"<<endl;
	cout<<"4-Вывести конфигурации в файл"<<endl;
	cout<<"5-Загрузить конфигурацию из файл"<<endl;
	cout<<"6-Добавить фигуру агрегат"<<endl;
	cout<<"0-Выйти из програмы"<<endl;
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
				if (L.Empty()) {cout<<"Еще нет ни одной фигуры!"<<endl; system("pause"); system("cls"); continue;}
				else L.Deleteing(L.Choosing());
				system("cls");
				continue;
			}
		case'3':
			{
				if (L.Empty()) {cout<<"Еще нет ни одной фигуры!"<<endl; system("pause"); system("cls"); continue;}
				else 
				{

					ShapeElem *ss=(L.Choosing());
					Shape* s=ss->shape->copy();
					ShapeOption(ss->shape);
					cout<<"Вы хотите вернуть первоночальный образ фигуры?"<<endl;
					cout<<"1-да, 2-нет"<<endl;
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
				if (L.Empty()) {cout<<"Еще нет ни одной фигуры!"<<endl; system("pause"); system("cls"); continue;}
				L.cashout();
				system("cls");
				continue;
			}
		case'5':
			{
				system("cls");
				char name[256];
				ifstream fin;
				cout<<"Введите имя файла"<<endl;
				cin>>name;
				fin.open(name);
				cashin(fin,L);
				system("cls");
				continue;
			}
		case'6':
			{
				if (L.Empty()) {cout<<"Еще нет ни одной фигуры!"<<endl; system("pause"); system("cls"); continue;}
				AgregMode(L);
				system("cls");
				continue;
			}
		case'0':{return;}
		default:{system("cls"); continue;}
		}
	}

}


