#pragma once

template <class T>
class list
{
	struct node // структура узла списка
	{
		T info; // поле с данными
		node* next; // указатель на предыдущий узел
		node* prev; // указатель на следующий узел
		node(T& in){info=in;next=NULL;prev=NULL;}
		node(){next=NULL; prev=NULL;}
	};
	node* head; //указатель на голову списка
	public:
	class iterator// итератор
	{
		public:
		node *ptr;// поле итератора(указатель на структуру "узел")
		iterator():ptr(NULL){}//конструктор по умолчанию
		iterator(node *pl):ptr(pl){}// конструктор с параметрами (переводит указатель на узел в объект класса итератор
		T& operator*(){return ptr->info;}//операция разименования итератора (возвращает данные по итератору)
		void operator++(){ptr = ptr->next;}//инкримента итератора (переходит на следующий елемент в списке)
		iterator operator+(int x) {iterator tmp(ptr); for (int i=0; i<x; i++) tmp++; return tmp;}
		bool operator!=(iterator i){return ptr != i.ptr;}// операция "не равно" (сравнивает поле данных двух итераторов)
		bool operator==(iterator i){return ptr == i.ptr;}
	};
	iterator begin(){return iterator(head);}// вернуть итератор первого елемента елемент списка
	iterator end(){return iterator(NULL);}// вернуть итератор конечного елемента списка (тот который находиться за последний узлом)
	list():head(NULL){}// конструктор по умолчанию
	void push_back(T &n)// функция "добавить в конец"
	{
		node *elem = new node(n);//создаем новый узел с данными
		if(!head){head=elem;}// если головы еще нет, ставим указательголовы на новый елемент
		else// в противном случае
		{	node* temp=head;// временным указателем указывем на голову
			for(temp; temp->next!=NULL; temp=temp->next);//двигаемся пока не находим предпоследний узел
			temp->next=elem;//указатель на следующий елемент пердпоследнего узла ставим на новый созданный
			elem->prev=temp;//указатель нового на предыдущий ставим на предпоследний узел
		}
	}
	T& front() {return head->info;}//доступ к первому елементу
	T& back() { node* temp=head; while(temp->next!=NULL) temp=temp->next; return temp->info;}//доступ к последнему елементу
	void swap(T &a, T &b)// поменять местами два елемента
	{
		T temp;
		temp = a;
		a = b;
		b = temp;
	}
	void sort() //сортировать список
	{
		for (iterator i(begin());i!=end();i++)
			for (iterator j(i + 1);j!=end();j++)
				if (*i>*j) swap(*i,*j);
	}
	bool empty(){ return (!head)? 1 : 0;}// список пуст?
	int size()//размер списка
	{
		if(!head) return 0;
		node *temp=head;
		int c=0;
		while(temp!=NULL){temp=temp->next; c++;}
		return c;
	}
	void pop_back()//убрать елемент с конца
	{
		if(head==NULL) return;
		if(head->next==NULL) {node* temp=head; head=NULL; delete temp; return;}
		node* temp=head;
		while(temp->next!=NULL) temp=temp->next;
		temp->prev->next=NULL;
		delete temp;
	}
};