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

class print// пердикат вывода в поток 
{
	std::ostream &o;
public:
	print(std::ostream &ok):o(ok){}// конструктор определяет поток
	template<class t3> std::ostream& operator()(t3& s){o << s << std::endl; return o;}// перегруженый скобки производят вывод
};

template <class t1>
void QtoL(Queue<t1> &Q, list<t1> &L)// функция перевода очереди в список
{
	while (!Q.empty())
	{L.push_back(Q.front());
	Q.pop();}

}
template <class t2>
void LtoQ(Queue<t2> &Q, list<t2> &L)// функция перевода списка в очередь
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
		std::cout<<"Главное меню очереди"<<std::endl;
		std::cout<<"1-push (добаивть елемент в очередь)"<<std::endl;
		std::cout<<"2-pop(удалить елемент из очереди)"<<std::endl;
		std::cout<<"3-front (доступ к первому елементу)"<<std::endl;
		std::cout<<"4-back(доступ к последнему елементу)"<<std::endl;
		std::cout<<"5-size(размер очереди)"<<std::endl;
		std::cout<<"6-sort (отсортировать очередь с помощью списком)"<<std::endl;
		std::cout<<"7-find (найти в очереди первое вхождение елемента c помощью списка)"<<std::endl;
		std::cout<<"8-min_element(найти минимальный елемент очереди с помощью списка)"<<std::endl;
		std::cout<<"9-print (вывести очередь с помощью списка и функции for_each)"<<std::endl;
		std::cout<<"0-выйти из главного меню очереди"<<std::endl;
		std::cout<<"---------------------------------------------------------------"<<std::endl;
		std::cout<<std::endl;
		switch(getch())
		{
		case '1':{S q;std::cout<<"Введите елемент который будет внесен в очередь"<<std::endl; std::cin>>q; Q.push(q); system("pause"); system("cls"); continue;}
		case '2':{if(Q.empty()){std::cout<<"Очередь пуста"<<std::endl; system("pause"); system("cls"); continue;}std::cout<<"Был удален елемент очереди :"<<Q.front()<<std::endl;Q.pop(); system("pause"); system("cls"); continue;}
		case '3':{if(Q.empty()){std::cout<<"Очередь пуста"<<std::endl; system("pause"); system("cls"); continue;}std::cout<<"Первый елемент на очереди :"<<Q.front()<<std::endl; system("pause"); system("cls"); continue;}
		case '4':{if(Q.empty()){std::cout<<"Очередь пуста"<<std::endl; system("pause"); system("cls"); continue;}std::cout<<"Последний елемент на очереди :"<<Q.back()<<std::endl; system("pause"); system("cls"); continue;}
		case '5':{std::cout<<"В очереди "<<Q.size()<<" елементов"<<std::endl; system("pause"); system("cls"); continue;}
		case '6':{if(Q.empty()){std::cout<<"Очередь пуста"<<std::endl; system("pause"); system("cls"); continue;}list<S> L; QtoL(Q,L); L.sort(); LtoQ(Q,L); std::cout<<"Очередь была отсортирована"<<std::endl; system("pause"); system("cls"); continue;}
		case '7':{if(Q.empty()){std::cout<<"Очередь пуста"<<std::endl; system("pause"); system("cls"); continue;}list<S> L; list<S>::iterator f; S val; QtoL(Q,L);  
			std::cout<<"Введите елемент который хотите найти"<<std::endl; 
			std::cin>>val;
			f=find(L.begin(),L.end(),val);
			if(L.end()==f) std::cout<<"Елемент "<<val<<" не найден"<<std::endl;
			else std::cout<<"Елемент "<<val<<" найден"<<std::endl;
			LtoQ(Q,L);
			system("pause"); system("cls"); continue;}
		case '8':{if(Q.empty()){std::cout<<"Очередь пуста"<<std::endl;  system("pause"); system("cls"); continue;}list<S> L; list<S>::iterator f; QtoL(Q,L);
			f=min_element(L.begin(),L.end());
			std::cout<<"Наименьший елемент очереди "<<*f<<std::endl;
			LtoQ(Q,L);
			system("pause"); system("cls"); continue;}
		case '9':{if(Q.empty()){std::cout<<"Очередь пуста"<<std::endl;  system("pause"); system("cls"); continue;}list<S> L; list<S>::iterator f; QtoL(Q,L);
			std::cout<<"Куда вы хотите вывести содержимое очереди ?"<<std::endl;
			std::cout<<"1-Вывод в консоль"<<std::endl;
			std::cout<<"2-Вывод в файл"<<std::endl;
			switch(getch())
			{
			case '1':{for_each(L.begin(),L.end(), print(std::cout)); LtoQ(Q,L); system("pause"); system("cls"); continue;}
			case '2':{
				std::ofstream fout;
				char buff[26];
				std::cout<<"Введите имя файла в который будете выводить"<<std::endl; 
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
	std::cout<<"Добро пожаловть в Лабораторную работу №4"<<std::endl;
	std::cout<<"Задание: Опеределить очередь через два (и не больше) стэка"<<std::endl;
	bool i=_flag_;
	if(i) std::cout<<"Программа скомпилирована без SLT"<<std::endl;
	else std::cout<<"Программа скомпилирована c SLT"<<std::endl;
	while(1)
	{
		std::cin.clear();
		_flushall();
		std::cout<<"С какой очередью вы хотите работать?"<<std::endl;
		std::cout<<"1- С очередью int"<<std::endl;
		std::cout<<"2- С очередью float"<<std::endl;
		std::cout<<"3- С очередью string (слова без пробелов)"<<std::endl;
		std::cout<<"0- Выйти из программы"<<std::endl;
		switch(getch())
		{
		case '1':{menu(qi); system("cls"); continue;}
		case '2':{menu(qf); system("cls"); continue;}
		case '3':{menu(qs); system("cls"); continue;}
		case '0':{return 0;}
		}
	}
}