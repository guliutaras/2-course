#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;

#pragma once
class Tree
{

public:
	Tree();//конструктор
	Tree(const Tree &A);
	void operator [](int lvl);
	friend ostream& operator<<(ostream&, const Tree d);//вывести елемент дерево
	friend istream& operator>>(istream& cin, Tree& d);//ввести елемет дерева
	void visual(Tree* node);//вывести все дерево;
	Tree* set(Tree* nodefath); //задать сына елементу дерева через указатель
	Tree &operator ()(int lvl, int elem);// доступ к елементу дерева
	void operator=(Tree &Tree2);// объединения поддерева/дерево
	void remove(Tree* node);// удалить елемент или ветку
	void filein(char name[256]);
	void fileout(char name[256]);
	~Tree();//деструктор
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

