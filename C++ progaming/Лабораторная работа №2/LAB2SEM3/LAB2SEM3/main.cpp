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
	cout<<"����� ���������� � ������������ ������ �2"<<endl;
	cout<<"������ �������� ��������� ��������� ������������ ������"<<endl;
	while(true)
	{
		cout<<"������� ����"<<endl;
		cout<<"1-�������� ��� �������"<<endl;
		cout<<"2-������ ������������"<<endl;
		cout<<"0-����� �� ���������"<<endl;
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
				cout<<"���� �������� ��� �������"<<endl;
				cout<<"1-�������� ������"<<endl;
				cout<<"2-������������ ������"<<endl;
				cout<<"3-���� ������ � ������"<<endl;
				cout<<"4-���������� ���������� ��������"<<endl;
				cout<<"5-�������� �����/������/��������"<<endl;
				cout<<"6-����������� ���� ��������"<<endl;
				cout<<"7-����� ������ � ����"<<endl;
				cout<<"8-���� ������ �� �����"<<endl;
				cout<<"0-����� �� ����� ����"<<endl;
				switch(getch())
				{
				case '1':{system("cls");
					cout<<"�������� ������"<<endl;
					switch(getch())
					{
					case '1':{system("cls"); cout<<"�������� ������ 1"<<endl; cin>>*(d1.set(&d1));  break;}
					case '2':{system("cls"); cout<<"�������� ������ 2"<<endl; cin>>*(d2.set(&d2));  break;}
					}
					getch(); 
					continue;}
				case '2':{system("cls");
					cout<<"��������� ������"<<endl;
					switch(getch())
					{
					case '1':{
						system("cls");
						cout<<"�������� ������ 1"<<endl; 
						if(&d1(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl; break;}
						d1.visual(&d1);  
						break;}
					case '2':{
						system("cls");
						cout<<"�������� ������ 2"<<endl; 
						if(&d2(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl; break;}
						d2.visual(&d2); 
						break;}
					}
					getch();
					continue;}
				case '3':{system("cls");
					cout<<"�������� ������"<<endl;
					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"�������� ������ 1"<<endl; 
							if(&d1(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i,j;
							cout<<"������� ������� � ����� �������� �� ���"<<endl;
							cin>>i>>j;
							if(&d1(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
							cin>>*(d1.set(&d1(i,j)));
							break;
						}
					case '2':
						{
							system("cls");
							cout<<"�������� ������ 2"<<endl; 
							if(&d2(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i,j;
							cout<<"������� ������� � ����� �������� �� ���"<<endl;
							cin>>i>>j;
							if(&d2(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
							cin>>*(d2.set(&d2(i,j)));
							break;
						}
					}
					getch();
					continue;}
				case '4':{
					system("cls");
					cout<<"�������� ������"<<endl;
					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"�������� ������ 1"<<endl; 
							if(&d1(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i;
							cout<<"������� ������� "<<endl;
							cin>>i;
							d1[i];
							break;
						}
					case '2':
						{
							system("cls");
							cout<<"�������� ������ 2"<<endl; 
							if(&d2(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i;
							cout<<"������� ������� "<<endl;
							cin>>i;
							d2[i];
							break;
						}
					}
					getch(); 
					continue;}
				case '5':{system("cls");
					cout<<"�������� ������"<<endl;

					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"�������� ������ 1"<<endl; 
							if(&d1(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i,j;
							cout<<"������� ������� � ����� �������� �� ���"<<endl;
							cin>>i>>j;
							if(&d1(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
							d1.remove(&d1(i,j));
						}
					case '2':
						{
							system("cls");
							cout<<"�������� ������ 2"<<endl; 
							if(&d2(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i,j;
							cout<<"������� ������� � ����� �������� �� ���"<<endl;
							cin>>i>>j;
							if(&d2(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
							d2.remove(&d1(i,j));
						}
					}
					getch();
					continue;}
				case '6':
					{
						cout<<"�������� ������"<<endl;
						switch(getch())
						{
						case '1':
							{
								system("cls");
								cout<<"�������� ������ 1"<<endl; 

								if(&d1(0,0)==NULL){cout<<"�� �� ������� ������-��������!!"<<endl;getch();break;}
								int i,j;
								cout<<"������� ������� � ����� �������� �� ���"<<endl;
								cin>>i>>j;
								if(&d1(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
								d2=d1(i,j);
								d2.visual(&d2);
							}
						case '2':
							{
								system("cls");
								cout<<"�������� ������ 2"<<endl; 
								if(&d1(0,0)==NULL){cout<<"�� �� ������� ������-��������!"<<endl;getch();break;}
								int i,j;
								cout<<"������� ������� � ����� �������� �� ���"<<endl;
								cin>>i>>j;
								if(&d1(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
								d1=d2(i,j);
								d2.visual(&d2);
							}
						}
						getch(); 
						continue;}
				case '7':
					{
						system("cls");
						cout<<"�������� ������"<<endl;

						switch(getch())
						{
						case '1':
							{
								system("cls");
								char name[256];
								cout<<"�������� ������ 1"<<endl; 
								cout<<"������� ��� �����"<<endl; 
								cin>>name;
								d1.filein(name);
								break;
							}
						case '2':
							{
								system("cls");
								char name[256];
								cout<<"�������� ������ 2"<<endl; 
								cout<<"������� ��� �����"<<endl; 
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
					cout<<"�������� ������"<<endl;

					switch(getch())
					{
					case '1':
						{
							system("cls");
							char name[256];
							cout<<"�������� ������ 1"<<endl; 
							cout<<"������� ��� �����"<<endl; 
							cin>>name;
							d1.fileout(name);
							break;
						}
					case '2':
						{
							system("cls");
							char name[256];
							cout<<"�������� ������ 2"<<endl; 
							cout<<"������� ��� �����"<<endl; 
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
				cout<<"���� ������ ����������߻"<<endl;
				cout<<"1-�������� ���������������� ������"<<endl;
				cout<<"2-������������ ���������������� ������"<<endl;
				cout<<"3-���� ������������� � ������"<<endl;
				cout<<"4-����������� ���������� ������������� �� ����������� ������"<<endl;
				cout<<"5-����� ���������������� ������"<<endl;
				cout<<"6-���� �� �����"<<endl;
				cout<<"7-����� � ����"<<endl;
				cout<<"0-����� �� ����� ����"<<endl;
				switch(getch())
				{
				case '1':{system("cls");
					cout<<"�������� ������"<<endl;
					switch(getch())
					{
					case '1':{system("cls"); cout<<"�������� ������ 1"<<endl;cout<<"������� �������� �����"<<endl; cin>>*(fd1.set(&fd1));  break;}
					case '2':{system("cls"); cout<<"�������� ������ 2"<<endl;cout<<"������� �������� �����"<<endl; cin>>*(fd2.set(&fd2));  break;}
					}
					getch(); 
					continue;}
				case '2':{system("cls");
					cout<<"��������� ������"<<endl;
					switch(getch())
					{
					case '1':{
						system("cls");
						cout<<"�������� ������ 1"<<endl; 
						if(&fd1(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl; break;}
						fd1.visual(&fd1);  
						break;}
					case '2':{
						system("cls");
						cout<<"�������� ������ 2"<<endl; 
						if(&fd2(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl; break;}
						fd2.visual(&fd2); 
						break;}
					}
					getch();
					continue;}
				case '3':{system("cls");
					cout<<"�������� ������"<<endl;
					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"�������� ������ 1"<<endl; 
							if(&fd1(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i,j;
							cout<<"������� ������� � ����� �������� �� ���"<<endl;
							cin>>i>>j;
							if(&fd1(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
							cout<<"������� ����� �������� ������"<<endl;
							cin>>*(fd1.set(&fd1(i,j)));
							break;
						}
					case '2':
						{
							system("cls");
							cout<<"�������� ������ 2"<<endl; 
							if(&fd2(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i,j;
							cout<<"������� ������� � ����� �������� �� ���"<<endl;
							cin>>i>>j;
							if(&fd2(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
							cout<<"������� ����� �������� ������"<<endl;
							cin>>*(fd2.set(&fd2(i,j)));
							break;
						}
					}
					getch();
					continue;}
				case '4':{
					system("cls");
					cout<<"�������� ������"<<endl;
					switch(getch())
					{
					case '1':
						{
							system("cls");
							cout<<"�������� ������ 2"<<endl; 
							if(&fd1(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i;
							cout<<"������� ������� "<<endl;
							cin>>i;
							fd1.myhasband(i);
							break;
						}
					case '2':
						{
							system("cls");
							cout<<"�������� ������ 2"<<endl; 
							if(&fd2(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
							int i;
							cout<<"������� ������� "<<endl;
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
			cout<<"�������� ������"<<endl;
			switch(getch())
			{
			case '1':
				{
					system("cls");
					cout<<"�������� ������ 1"<<endl; 
					if(&fd1(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
					int i,j;
					cout<<"������� ������� � ����� �������� �� ���"<<endl;
					cin>>i>>j;
					if(&fd1(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
					fd1.remove(&fd1(i,j));
				}
			case '2':
				{
					system("cls");
					cout<<"�������� ������ 2"<<endl; 
					if(&fd2(0,0)==NULL){cout<<"�� �� ������� ������!"<<endl;getch();break;}
					int i,j;
					cout<<"������� ������� � ����� �������� �� ���"<<endl;
					cin>>i>>j;
					if(&fd2(i,j)==NULL){cout<<"������� �� ������"<<endl;getch();break;}
					fd2.remove(&fd2(i,j));
				}
			}
			getch();
			continue;
				 }
		case '6':
			{
				system("cls");
				cout<<"�������� ������"<<endl;

				switch(getch())
				{
				case '1':
					{
						system("cls");
						char name[256];
						cout<<"�������� ������ 1"<<endl; 
						cout<<"������� ��� �����"<<endl; 
						cin>>name;
						fd1.filein(name);
						break;
					}
				case '2':
					{
						system("cls");
						char name[256];
						cout<<"�������� ������ 2"<<endl; 
						cout<<"������� ��� �����"<<endl; 
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
			cout<<"�������� ������"<<endl;

			switch(getch())
			{
			case '1':
				{
					system("cls");
					char name[256];
					cout<<"�������� ������ 1"<<endl; 
					cout<<"������� ��� �����"<<endl; 
					cin>>name;
					fd1.fileout(name);
					break;
				}
			case '2':
				{
					system("cls");
					char name[256];
					cout<<"�������� ������ 2"<<endl; 
					cout<<"������� ��� �����"<<endl; 
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