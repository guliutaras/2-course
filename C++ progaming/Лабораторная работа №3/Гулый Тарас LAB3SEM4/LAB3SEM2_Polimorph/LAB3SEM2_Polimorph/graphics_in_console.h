#pragma once

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include "graphics.h"
#include <dos.h>
#include <fstream>
#include <math.h>


using namespace std;

const double M_PI=3.16259265358979323846;
const char LARROW = 'K';
const char RARROW = 'M';
const char UARROW = 'H';
const char DARROW = 'P';
const int  BGCOLOR = 0;
const int  COLOR   = 2;
const int  STEP = 10;
//������� �����
class Shape 
{

protected:
	int x,y;
public:
	int color;
	Grfx::Graphics console_graphics;
	Shape(int a, int b, int c): x(a), y(b), color(c) {}
	virtual ofstream& ofile(ofstream &fout){return fout;};
	virtual ifstream& ifile(ifstream &fin){return fin;};
	virtual Shape* copy()= 0;
	virtual void draw(int c) = 0;
	virtual void show() { draw(color); }
	virtual void colorch(int color1) {color=color1;}
	virtual void deform()=0;
	virtual void hide() { draw(BGCOLOR); }
	virtual void move(int dx, int dy) { hide(); x+=dx; y+=dy; show(); }
	virtual void move_trace(int dx, int dy) { x+=dx; y+=dy; show(); }
};
//������ ���������� �����
class Nstar : public Shape
{
	int r,n;
public:
	Nstar(int a, int b, int ra,int na, int c) : Shape(a,b,c), r(ra), n(na){ show(); }
	void draw(int c);
	void deform();
	Shape* copy();
	ofstream& ofile(ofstream &fout);
	ifstream& ifile(ifstream &fin);
};
class Segment : public Shape
{
	int dx,dy;
public:
	Segment(int a, int b, int da, int db, int c) : Shape(a,b,c), dx(da), dy(db) { show(); }
	void draw(int c);
	void deform();
	Shape* copy();
	ofstream& ofile(ofstream &fout);
	ifstream& ifile(ifstream &fin);
};
class Circle : public Shape
{
	int r;
public:
	Circle(int a, int b, int ra, int c) : Shape(a,b,c), r(ra){ show(); }
	void draw(int c);
	void deform();
	Shape* copy();
	ofstream& ofile(ofstream &fout);
	ifstream& ifile(ifstream &fin);
};
class Rectangl : public Shape
{
	int dx,dy;
public:
	Rectangl(int a, int b, int da, int db, int c) : Shape(a,b,c), dx(da), dy(db) { show(); }
	void draw(int c);
	void deform();
	Shape* copy();
	ofstream& ofile(ofstream &fout);
	ifstream& ifile(ifstream &fin);
};
class Triangle : public Shape
{
	int dx1,dy1,dx2,dy2;
public:
	Triangle(int a, int b, int da1, int db1,int da2, int db2, int c) : Shape(a,b,c), dx1(da1), dy1(db1), dx2(da2), dy2(db2){ show(); }
	void draw(int c);
	void deform();
	Shape* copy();
	ofstream& ofile(ofstream &fout);
	ifstream& ifile(ifstream &fin);
};
//����������� ������ ����� � �������� ������
struct ShapeElem
{	
	char name;
	Shape * shape;
	ShapeElem* next;
	ShapeElem(Shape* s, char type) {shape=s;name=type;next=NULL;}
};
class ShapeList
{
public:
	ShapeElem* head;
	ShapeList():head(NULL){}
	ShapeElem* Choosing()
	{
		ShapeElem* temp=head;
		while(1)
		{
			std::system("cls");
			Sleep(100);
			std::cout<<"����������� 'tab'- ��� �������� �� ��������� ������ � 'space'- ��� ������"<<endl;
			ShapeElem* s=temp;
			s->shape->draw(s->shape->color);
			int c=getch();
			switch(c)
			{
			case 9:
				{
					s->shape->hide();
					temp=temp->next;
					if(temp==NULL) temp=head;
					continue;
				}
			case 32:
				{
					return s;
				}
			}
		}
		return NULL;
	}
	void Deleteing(ShapeElem *S)
	{
		system("cls");
		ShapeElem* temp=head;
		while(temp!=S)
			temp=temp->next;
		if(temp==head)
		{
			if(head->next!=NULL){head=head->next;}
			else{head=NULL;}
		}
		else
		{
			ShapeElem* temp2=head;
			while(temp2->next!=temp)
				temp2=temp2->next;
			temp2->next=temp->next;
		}
		delete temp;
		cout<<"������ �������"<<endl;
		getch();
	}
	void ShapeMode() //��� ���������� ����� ������ ���� ����� ������ �� �������������
	{
		Shape *s=NULL;
		char type;
		int c;
		system("cls");
		cout<<"����� ������ �� ������ ��������? "<<endl;
		cout<<"c- ����"<<endl;
		cout<<"r- �������������"<<endl;
		cout<<"s- �������"<<endl;
		cout<<"n- n-�������� ������"<<endl;
		cout<<"t- �����������"<<endl;
		switch(getch())
		{
		case'c':
			{
				int x,y,r;
				cout<<"������� ��������� �����, ������ � ���� "<<endl;
				cin>>x>>y>>r>>c;
				s=new Circle(x, y, r, c);
				type='c';
				break;
			}
		case'r':
			{
				int x,y,dx,dy;
				cout<<"������� ��������� �����,�� �������� � ���� "<<endl;
				cin>>x>>y>>dx>>dy>>c;
				s=new Rectangl(x, y, dx, dy, c);
				type='r';
				break;
			}
		case'n':
			{
				int x,y,r,n;
				cout<<"������� ��������� �����, ������ �������� �����, ���������� ������ ������"<<endl;
				cin>>x>>y>>r>>n>>c;
				s=new Nstar(x, y, r, n, c);
				type='n';
				break;
			}
		case's':
			{
				int x,y,dx,dy;
				cout<<"������� ��������� �����,�� �������� � ���� "<<endl;
				cin>>x>>y>>dx>>dy>>c;
				s=new Segment(x, y, dx, dy, c);
				type='s';
				break;
			}
		case't':
			{
				int x,y,dx1,dy1,dx2,dy2;
				cout<<"������� ��������� �����, 2 �������� ������������ ��� � ���� "<<endl;
				cin>>x>>y>>dx1>>dy1>>dx2>>dy2>>c;
				s=new Triangle(x,y,dx1,dy1,dx2,dy2,c);
				type='t';
				break;
			}
		default:{cout<<"����� ������ ���"<<endl; return;}
		}

		if(head==NULL) {head=new ShapeElem(s,type);system("cls");Sleep(100);cout<<"���� ����� ������:"<<endl; Shape* s=head->shape; s->draw(s->color);getch();}
		else
		{
			ShapeElem* temp=head;
			ShapeElem* newest=new ShapeElem(s,type);
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newest;
			system("cls");
			Sleep(100);
			cout<<"���� ����� ������:"<<endl;
			Shape* s=newest->shape;
			s->draw(s->color);
			getch();
		}

	}
	void cashout()
	{
		system("cls");
		char name[256];
		ofstream fout;
		cout<<"������� ��� �����"<<endl;
		cin>>name;
		fout.open(name);
		ShapeElem* temp=head;
		while(temp!=NULL)
		{
			temp->shape->ofile(fout);
			temp=temp->next;
		}
		fout.close();
		cout<<"������ � ���� ������ �������"<<endl;
		getch();
	}
	bool Empty(){if(!head) return 1; else return 0;}
	void push_back(ShapeElem* &S)
	{
		if(!head) {head=S;}
		else
		{
			ShapeElem* temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=S;
		}
	}
};
//����� "�������"
class Agregat : public Shape 
{
	ShapeList Headake;
public:
	   Agregat(int a, int b, ShapeList List, int c) : Shape(a,b,c){Headake.head=List.head;}
	   void draw (int c);
	   void show ();
	   void hide();
	   void deform();
	   void colorch(int color1);
	   void move(int dx, int dy) ;
	   void move_trace(int dx, int dy);
	   void move_each();
	   Shape* copy();
	   void redraw();
	   ofstream& ofile(ofstream &fout);
	   ifstream& ifile(ifstream &fin);
};
//��������������� �������
void AgregMode(ShapeList LM);
void cashin(ifstream &fin, ShapeList &L);
void moving_trace(Shape* s);
void moving_trac(Shape *s);
void moving(Shape* s);
void ShapeOption(Shape* s);