#pragma once
#include "Mylist.h"

template <class T>
class stack// ���� ��������� �� ������
{
	list<T> l;
public:
	stack(){}
	void push(T& p){l.push_back(p);}//�������� � ����� ������
	void pop(){l.pop_back();}//������� � ����� ������
	bool empty(){return l.empty();}// ������ �� ������?
	int size(){return l.size();}//������ ������
	T& top(){return l.back();}//������ � ���������� ��������
};