#pragma once
#include "Mylist.h"

template <class T>
class stack// стак основаный на списке
{
	list<T> l;
public:
	stack(){}
	void push(T& p){l.push_back(p);}//добавить в конец списка
	void pop(){l.pop_back();}//достать с конца списка
	bool empty(){return l.empty();}// пустой ли список?
	int size(){return l.size();}//размер списка
	T& top(){return l.back();}//доступ к последнему елементу
};