#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Tree.h"
#include "FamilyTree.h"
using namespace std;

int main()
{
	Tree d1,d2;
	FamilyTree fd1, fd2;
	system("CHCP 1251>NUL");
	cout<<"Добро пожалывать в лабораторную работу №2"<<endl;
	cout<<"Данная програма реализует структуру ПРОИЗВОЛЬНОЕ ДЕРЕВО"<<endl;
	while(true)
	{
		cout<<"ГЛАВНОЕ МЕНЮ"<<endl;
		cout<<"1-Операции над деревом"<<endl;
		cout<<"2-Задача «Генеология»"<<endl;
		cout<<"0-Выход из программы"<<endl;
		cin.clear();
		_flushall();
		switch(getch())
		{
		case'1':{
			while(true)
			{

				system("cls");
				cin.clear();
				_flushall();
				cout<<"МЕНЮ ОПЕРАЦИЙ НАД ДЕРЕВОМ"<<endl;
				cout<<"1-Создание дерева"<<endl;
				cout<<"2-Визуализация дерева"<<endl;
				cout<<"3-Ввод данных в дерево"<<endl;
				cout<<"4-Перегрузка квадратных скобочек"<<endl;
				cout<<"5-Удаления ветки/дерева/елемента"<<endl;
				cout<<"6-Объеденение двух деревьев"<<endl;
				cout<<"7-Вывод дерева в файл"<<endl;
				cout<<"8-Ввод дерево из файла"<<endl;
				cout<<"0-Выход из этого меню"<<endl;
				switch(getch())
				{
				case '1':{system("cls");
					cout<<"Выберете дерево"<<endl;
					switch(getch())
					{
					case '1':{system("cls"); cout<<"Выберано дерево 1"<<endl; cin>>*(d1.set(&d1));  break;}
					case '2':{system("cls"); cout<<"Выберано дерево 2"<<endl; cin>>*(d2.set(&d2));  break;}
					}
					getch(); 
					continue;}
				case '2':{system("cls");
					cout<<"Ввыберете дерево"<<endl;
					switch(getch())
					{
					case '1':{
						system("cls");
						cout<<"Выберано дерево 1"<<endl; 
						if(&d1(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl; break;}
						d1.visual(&d1);  
						break;}
					case '2':{
						system("cls");
						cout<<"Выберано дерево 2"<<endl; 
						if(&d2(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl; break;}
						d2.visual(&d2); 
						break;}
					}
					getch();
					continue;}
				case '3':{system("cls");
					cout<<"Выберете дерево"<<endl;
					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"Выберано дерево 1"<<endl; 
							if(&d1(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i,j;
							cout<<"Введите уровень и номер елемента на нем"<<endl;
							cin>>i>>j;
							if(&d1(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
							cin>>*(d1.set(&d1(i,j)));
							break;
						}
					case '2':
						{
							system("cls");
							cout<<"Выберано дерево 2"<<endl; 
							if(&d2(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i,j;
							cout<<"Введите уровень и номер елемента на нем"<<endl;
							cin>>i>>j;
							if(&d2(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
							cin>>*(d2.set(&d2(i,j)));
							break;
						}
					}
					getch();
					continue;}
				case '4':{
					system("cls");
					cout<<"Выберете дерево"<<endl;
					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"Выберано дерево 1"<<endl; 
							if(&d1(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i;
							cout<<"Введите уровень "<<endl;
							cin>>i;
							d1[i];
							break;
						}
					case '2':
						{
							system("cls");
							cout<<"Выберано дерево 2"<<endl; 
							if(&d2(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i;
							cout<<"Введите уровень "<<endl;
							cin>>i;
							d2[i];
							break;
						}
					}
					getch(); 
					continue;}
				case '5':{system("cls");
					cout<<"Выберете дерево"<<endl;

					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"Выберано дерево 1"<<endl; 
							if(&d1(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i,j;
							cout<<"Введите уровень и номер елемента на нем"<<endl;
							cin>>i>>j;
							if(&d1(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
							d1.remove(&d1(i,j));
						}
					case '2':
						{
							system("cls");
							cout<<"Выберано дерево 2"<<endl; 
							if(&d2(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i,j;
							cout<<"Введите уровень и номер елемента на нем"<<endl;
							cin>>i>>j;
							if(&d2(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
							d2.remove(&d1(i,j));
						}
					}
					getch();
					continue;}
				case '6':
					{
						cout<<"Выберете дерево"<<endl;
						switch(getch())
						{
						case '1':
							{
								system("cls");
								cout<<"Выберано дерево 1"<<endl; 

								if(&d1(0,0)==NULL){cout<<"Вы не создали дерево-источник!!"<<endl;getch();break;}
								int i,j;
								cout<<"Введите уровень и номер елемента на нем"<<endl;
								cin>>i>>j;
								if(&d1(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
								d2=d1(i,j);
								d2.visual(&d2);
							}
						case '2':
							{
								system("cls");
								cout<<"Выберано дерево 2"<<endl; 
								if(&d1(0,0)==NULL){cout<<"Вы не создали дерево-источник!"<<endl;getch();break;}
								int i,j;
								cout<<"Введите уровень и номер елемента на нем"<<endl;
								cin>>i>>j;
								if(&d1(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
								d1=d2(i,j);
								d2.visual(&d2);
							}
						}
						getch(); 
						continue;}
				case '7':
					{
						system("cls");
						cout<<"Выберете дерево"<<endl;

						switch(getch())
						{
						case '1':
							{
								system("cls");
								char name[256];
								cout<<"Выберано дерево 1"<<endl; 
								cout<<"Введите имя файла"<<endl; 
								cin>>name;
								d1.filein(name);
								break;
							}
						case '2':
							{
								system("cls");
								char name[256];
								cout<<"Выберано дерево 2"<<endl; 
								cout<<"Введите имя файла"<<endl; 
								cin>>name;
								d2.filein(name);
								break;
							}
						}
						getch(); 
						continue;
					}
				case '8':{
					system("cls");
					cout<<"Выберете дерево"<<endl;

					switch(getch())
					{
					case '1':
						{
							system("cls");
							char name[256];
							cout<<"Выберано дерево 1"<<endl; 
							cout<<"Введите имя файла"<<endl; 
							cin>>name;
							d1.fileout(name);
							break;
						}
					case '2':
						{
							system("cls");
							char name[256];
							cout<<"Выберано дерево 2"<<endl; 
							cout<<"Введите имя файла"<<endl; 
							cin>>name;
							d2.fileout(name);
							break;
						}
					}
					getch(); 
					continue;
						 }
				case '0':{break;}
				default:{ continue;}
				}
				break;
			}
			break;
				}
		case'2':{
			while(true)
			{

				system("cls");
				cin.clear();
				_flushall();
				cout<<"МЕНЮ ЗАДАЧИ «ГЕНЕОЛОГИЯ»"<<endl;
				cout<<"1-Создание генеологического дерева"<<endl;
				cout<<"2-Визуализация генеологического дерева"<<endl;
				cout<<"3-Ввод родственников в дерево"<<endl;
				cout<<"4-Определение количества родственников на опредленном уровне"<<endl;
				cout<<"5-Вывод генеологического дерева"<<endl;
				cout<<"6-Ввод из файла"<<endl;
				cout<<"7-Вывод в файл"<<endl;
				cout<<"0-Выход из этого меню"<<endl;
				switch(getch())
				{
				case '1':{system("cls");
					cout<<"Выберете дерево"<<endl;
					switch(getch())
					{
					case '1':{system("cls"); cout<<"Выберано дерево 1"<<endl;cout<<"Введите главного члена"<<endl; cin>>*(fd1.set(&fd1));  break;}
					case '2':{system("cls"); cout<<"Выберано дерево 2"<<endl;cout<<"Введите главного члена"<<endl; cin>>*(fd2.set(&fd2));  break;}
					}
					getch(); 
					continue;}
				case '2':{system("cls");
					cout<<"Ввыберете дерево"<<endl;
					switch(getch())
					{
					case '1':{
						system("cls");
						cout<<"Выберано дерево 1"<<endl; 
						if(&fd1(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl; break;}
						fd1.visual(&fd1);  
						break;}
					case '2':{
						system("cls");
						cout<<"Выберано дерево 2"<<endl; 
						if(&fd2(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl; break;}
						fd2.visual(&fd2); 
						break;}
					}
					getch();
					continue;}
				case '3':{system("cls");
					cout<<"Выберете дерево"<<endl;
					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"Выберано дерево 1"<<endl; 
							if(&fd1(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i,j;
							cout<<"Введите уровень и номер елемента на нем"<<endl;
							cin>>i>>j;
							if(&fd1(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
							cout<<"Введите члена родового дерева"<<endl;
							cin>>*(fd1.set(&fd1(i,j)));
							break;
						}
					case '2':
						{
							system("cls");
							cout<<"Выберано дерево 2"<<endl; 
							if(&fd2(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i,j;
							cout<<"Введите уровень и номер елемента на нем"<<endl;
							cin>>i>>j;
							if(&fd2(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
							cout<<"Введите члена родового дерева"<<endl;
							cin>>*(fd2.set(&fd2(i,j)));
							break;
						}
					}
					getch();
					continue;}
				case '4':{
					system("cls");
					cout<<"Выберете дерево"<<endl;
					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"Выберано дерево 2"<<endl; 
							if(&fd1(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i;
							cout<<"Введите уровень "<<endl;
							cin>>i;
							fd1.myhasband(i);
							break;
						}
					case '2':
						{
							system("cls");
							cout<<"Выберано дерево 2"<<endl; 
							if(&fd2(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
							int i;
							cout<<"Введите уровень "<<endl;
							cin>>i;
							fd2.myhasband(i);
							break;
						}
					}
					getch();
					continue;
				}
		case '5':
			{
			system("cls");
			cout<<"Выберете дерево"<<endl;
			switch(getch())
			{
			case '1':
				{
					system("cls");
					cout<<"Выберано дерево 1"<<endl; 
					if(&fd1(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
					int i,j;
					cout<<"Введите уровень и номер елемента на нем"<<endl;
					cin>>i>>j;
					if(&fd1(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
					fd1.remove(&fd1(i,j));
				}
			case '2':
				{
					system("cls");
					cout<<"Выберано дерево 2"<<endl; 
					if(&fd2(0,0)==NULL){cout<<"Вы не создали дерево!"<<endl;getch();break;}
					int i,j;
					cout<<"Введите уровень и номер елемента на нем"<<endl;
					cin>>i>>j;
					if(&fd2(i,j)==NULL){cout<<"Елемент не найден"<<endl;getch();break;}
					fd2.remove(&fd2(i,j));
				}
			}
			getch();
			continue;
				 }
		case '6':
			{
				system("cls");
				cout<<"Выберете дерево"<<endl;

				switch(getch())
				{
				case '1':
					{
						system("cls");
						char name[256];
						cout<<"Выберано дерево 1"<<endl; 
						cout<<"Введите имя файла"<<endl; 
						cin>>name;
						fd1.filein(name);
						break;
					}
				case '2':
					{
						system("cls");
						char name[256];
						cout<<"Выберано дерево 2"<<endl; 
						cout<<"Введите имя файла"<<endl; 
						cin>>name;
						fd2.filein(name);
						break;
					}
				}
				getch(); 
				continue;
			}
		case '7':{
			system("cls");
			cout<<"Выберете дерево"<<endl;

			switch(getch())
			{
			case '1':
				{
					system("cls");
					char name[256];
					cout<<"Выберано дерево 1"<<endl; 
					cout<<"Введите имя файла"<<endl; 
					cin>>name;
					fd1.fileout(name);
					break;
				}
			case '2':
				{
					system("cls");
					char name[256];
					cout<<"Выберано дерево 2"<<endl; 
					cout<<"Введите имя файла"<<endl; 
					cin>>name;
					fd2.fileout(name);
					break;
				}
			}
			getch(); 
			continue;
				 }
		case '0':{break;}
		default:{ continue;}
			}
			break;
				}
				break;
		}
		case'0':{return 0;}
	}
	system("cls");
}
return 0;
}