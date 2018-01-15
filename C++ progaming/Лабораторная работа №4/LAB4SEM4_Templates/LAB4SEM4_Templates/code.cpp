#include <iostream>
#include <fstream>
#include <locale>
#include <conio.h>
#include <Windows.h>

#define _flag_ 1

#ifdef _flag_
#include "Mylist.h"
#include "Mystack.h"
#include "Myalgorithm.h"
#include "Mystring.h"
#endif

#ifndef _flag_
#include <algorithm>
#include <stack>
#include <string>
#include <list>
using namespace std;

#endif

template<class T>
class Queue 
{
	stack <T> S1, S2;
public:
	Queue(){}
	bool empty() { return S1.empty() && S2.empty(); }
	int size() { return S1.size()+S2.size(); }
	T& front(){S1toS2(); return S2.top(); }
	T& back(){S2toS1(); return S1.top(); }
	void push(T& x) { S1.push(x); }
	void pop() { S1toS2(); S2.pop(); }
private:
	void S1toS2() 
	{
		if (S2.empty())
			while (!S1.empty()) {S2.push(S1.top()); S1.pop();}
	}
	void S2toS1() 
	{
		if (S1.empty())
			while (!S2.empty()) {S1.push(S2.top()); S2.pop();}
	}
};

class print// �������� ������ � ����� 
{
	std::ostream &o;
public:
	print(std::ostream &ok):o(ok){}// ����������� ���������� �����
	template<class t3> std::ostream& operator()(t3& s){o << s << std::endl; return o;}// ������������ ������ ���������� �����
};

template <class t1>
void QtoL(Queue<t1> &Q, list<t1> &L)// ������� �������� ������� � ������
{
	while (!Q.empty())
	{L.push_back(Q.front());
	Q.pop();}

}
template <class t2>
void LtoQ(Queue<t2> &Q, list<t2> &L)// ������� �������� ������ � �������
{
	list<t2>::iterator b = L.begin();
	list<t2>::iterator e = L.end();
	for (; b!=e; b++) {Q.push(*b);}
}
template <typename S>
void menu(Queue<S> &Q)
{
	while(true)
	{
		system("cls");
		std::cin.clear();
		_flushall();
		std::cout<<"������� ���� �������"<<std::endl;
		std::cout<<"1-push (�������� ������� � �������)"<<std::endl;
		std::cout<<"2-pop(������� ������� �� �������)"<<std::endl;
		std::cout<<"3-front (������ � ������� ��������)"<<std::endl;
		std::cout<<"4-back(������ � ���������� ��������)"<<std::endl;
		std::cout<<"5-size(������ �������)"<<std::endl;
		std::cout<<"6-sort (������������� ������� � ������� �������)"<<std::endl;
		std::cout<<"7-find (����� � ������� ������ ��������� �������� c ������� ������)"<<std::endl;
		std::cout<<"8-min_element(����� ����������� ������� ������� � ������� ������)"<<std::endl;
		std::cout<<"9-print (������� ������� � ������� ������ � ������� for_each)"<<std::endl;
		std::cout<<"0-����� �� �������� ���� �������"<<std::endl;
		std::cout<<"---------------------------------------------------------------"<<std::endl;
		std::cout<<std::endl;
		switch(getch())
		{
		case '1':{S q;std::cout<<"������� ������� ������� ����� ������ � �������"<<std::endl; std::cin>>q; Q.push(q); system("pause"); system("cls"); continue;}
		case '2':{if(Q.empty()){std::cout<<"������� �����"<<std::endl; system("pause"); system("cls"); continue;}std::cout<<"��� ������ ������� ������� :"<<Q.front()<<std::endl;Q.pop(); system("pause"); system("cls"); continue;}
		case '3':{if(Q.empty()){std::cout<<"������� �����"<<std::endl; system("pause"); system("cls"); continue;}std::cout<<"������ ������� �� ������� :"<<Q.front()<<std::endl; system("pause"); system("cls"); continue;}
		case '4':{if(Q.empty()){std::cout<<"������� �����"<<std::endl; system("pause"); system("cls"); continue;}std::cout<<"��������� ������� �� ������� :"<<Q.back()<<std::endl; system("pause"); system("cls"); continue;}
		case '5':{std::cout<<"� ������� "<<Q.size()<<" ���������"<<std::endl; system("pause"); system("cls"); continue;}
		case '6':{if(Q.empty()){std::cout<<"������� �����"<<std::endl; system("pause"); system("cls"); continue;}list<S> L; QtoL(Q,L); L.sort(); LtoQ(Q,L); std::cout<<"������� ���� �������������"<<std::endl; system("pause"); system("cls"); continue;}
		case '7':{if(Q.empty()){std::cout<<"������� �����"<<std::endl; system("pause"); system("cls"); continue;}list<S> L; list<S>::iterator f; S val; QtoL(Q,L);  
			std::cout<<"������� ������� ������� ������ �����"<<std::endl; 
			std::cin>>val;
			f=find(L.begin(),L.end(),val);
			if(L.end()==f) std::cout<<"������� "<<val<<" �� ������"<<std::endl;
			else std::cout<<"������� "<<val<<" ������"<<std::endl;
			LtoQ(Q,L);
			system("pause"); system("cls"); continue;}
		case '8':{if(Q.empty()){std::cout<<"������� �����"<<std::endl;  system("pause"); system("cls"); continue;}list<S> L; list<S>::iterator f; QtoL(Q,L);
			f=min_element(L.begin(),L.end());
			std::cout<<"���������� ������� ������� "<<*f<<std::endl;
			LtoQ(Q,L);
			system("pause"); system("cls"); continue;}
		case '9':{if(Q.empty()){std::cout<<"������� �����"<<std::endl;  system("pause"); system("cls"); continue;}list<S> L; list<S>::iterator f; QtoL(Q,L);
			std::cout<<"���� �� ������ ������� ���������� ������� ?"<<std::endl;
			std::cout<<"1-����� � �������"<<std::endl;
			std::cout<<"2-����� � ����"<<std::endl;
			switch(getch())
			{
			case '1':{for_each(L.begin(),L.end(), print(std::cout)); LtoQ(Q,L); system("pause"); system("cls"); continue;}
			case '2':{
				std::ofstream fout;
				char buff[26];
				std::cout<<"������� ��� ����� � ������� ������ ��������"<<std::endl; 
				std::cin>>buff;
				fout.open(buff);
				for_each(L.begin(),L.end(),print(fout)); 
				LtoQ(Q,L); system("pause"); system("cls"); continue;}
			}
			LtoQ(Q,L);
			system("pause"); system("cls"); continue;}
		case '0':{return;}
		}
	}
}

int main()
{
	Queue <int> qi;
	Queue <float> qf;
	Queue <string> qs;
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout<<"����� ��������� � ������������ ������ �4"<<std::endl;
	std::cout<<"�������: ����������� ������� ����� ��� (� �� ������) �����"<<std::endl;
	bool i=_flag_;
	if(i) std::cout<<"��������� �������������� ��� SLT"<<std::endl;
	else std::cout<<"��������� �������������� c SLT"<<std::endl;
	while(1)
	{
		std::cin.clear();
		_flushall();
		std::cout<<"� ����� �������� �� ������ ��������?"<<std::endl;
		std::cout<<"1- � �������� int"<<std::endl;
		std::cout<<"2- � �������� float"<<std::endl;
		std::cout<<"3- � �������� string (����� ��� ��������)"<<std::endl;
		std::cout<<"0- ����� �� ���������"<<std::endl;
		switch(getch())
		{
		case '1':{menu(qi); system("cls"); continue;}
		case '2':{menu(qf); system("cls"); continue;}
		case '3':{menu(qs); system("cls"); continue;}
		case '0':{return 0;}
		}
	}
}