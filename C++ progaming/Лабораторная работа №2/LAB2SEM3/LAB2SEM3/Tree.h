#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;

#pragma once
class Tree
{

public:
	Tree();//�����������
	Tree(const Tree &A);
	void operator [](int lvl);
	friend ostream& operator<<(ostream&, const Tree d);//������� ������� ������
	friend istream& operator>>(istream& cin, Tree& d);//������ ������ ������
	void visual(Tree* node);//������� ��� ������;
	Tree* set(Tree* nodefath); //������ ���� �������� ������ ����� ���������
	Tree &operator ()(int lvl, int elem);// ������ � �������� ������
	void operator=(Tree &Tree2);// ����������� ���������/������
	void remove(Tree* node);// ������� ������� ��� �����
	void filein(char name[256]);
	void fileout(char name[256]);
	~Tree();//����������
protected:
	char info[80];
	int lvl;
	Tree* son;
	Tree* brother;
	Tree* root;
	Tree* fath;
	void visualfile(ofstream& fout,Tree* node);
	void copyleftover(Tree* copynode,Tree* wherenode);
	void gettorightlvl (Tree* &temp, Tree* temp2,int curlvl,int &curelem,bool &found);
	void destroy(Tree *node);
};

