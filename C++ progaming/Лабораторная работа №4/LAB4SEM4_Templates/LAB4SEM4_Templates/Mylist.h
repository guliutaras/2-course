#pragma once

template <class T>
class list
{
	struct node // ��������� ���� ������
	{
		T info; // ���� � �������
		node* next; // ��������� �� ���������� ����
		node* prev; // ��������� �� ��������� ����
		node(T& in){info=in;next=NULL;prev=NULL;}
		node(){next=NULL; prev=NULL;}
	};
	node* head; //��������� �� ������ ������
	public:
	class iterator// ��������
	{
		public:
		node *ptr;// ���� ���������(��������� �� ��������� "����")
		iterator():ptr(NULL){}//����������� �� ���������
		iterator(node *pl):ptr(pl){}// ����������� � ����������� (��������� ��������� �� ���� � ������ ������ ��������
		T& operator*(){return ptr->info;}//�������� ������������� ��������� (���������� ������ �� ���������)
		void operator++(){ptr = ptr->next;}//���������� ��������� (��������� �� ��������� ������� � ������)
		iterator operator+(int x) {iterator tmp(ptr); for (int i=0; i<x; i++) tmp++; return tmp;}
		bool operator!=(iterator i){return ptr != i.ptr;}// �������� "�� �����" (���������� ���� ������ ���� ����������)
		bool operator==(iterator i){return ptr == i.ptr;}
	};
	iterator begin(){return iterator(head);}// ������� �������� ������� �������� ������� ������
	iterator end(){return iterator(NULL);}// ������� �������� ��������� �������� ������ (��� ������� ���������� �� ��������� �����)
	list():head(NULL){}// ����������� �� ���������
	void push_back(T &n)// ������� "�������� � �����"
	{
		node *elem = new node(n);//������� ����� ���� � �������
		if(!head){head=elem;}// ���� ������ ��� ���, ������ ��������������� �� ����� �������
		else// � ��������� ������
		{	node* temp=head;// ��������� ���������� �������� �� ������
			for(temp; temp->next!=NULL; temp=temp->next);//��������� ���� �� ������� ������������� ����
			temp->next=elem;//��������� �� ��������� ������� �������������� ���� ������ �� ����� ���������
			elem->prev=temp;//��������� ������ �� ���������� ������ �� ������������� ����
		}
	}
	T& front() {return head->info;}//������ � ������� ��������
	T& back() { node* temp=head; while(temp->next!=NULL) temp=temp->next; return temp->info;}//������ � ���������� ��������
	void swap(T &a, T &b)// �������� ������� ��� ��������
	{
		T temp;
		temp = a;
		a = b;
		b = temp;
	}
	void sort() //����������� ������
	{
		for (iterator i(begin());i!=end();i++)
			for (iterator j(i + 1);j!=end();j++)
				if (*i>*j) swap(*i,*j);
	}
	bool empty(){ return (!head)? 1 : 0;}// ������ ����?
	int size()//������ ������
	{
		if(!head) return 0;
		node *temp=head;
		int c=0;
		while(temp!=NULL){temp=temp->next; c++;}
		return c;
	}
	void pop_back()//������ ������� � �����
	{
		if(head==NULL) return;
		if(head->next==NULL) {node* temp=head; head=NULL; delete temp; return;}
		node* temp=head;
		while(temp->next!=NULL) temp=temp->next;
		temp->prev->next=NULL;
		delete temp;
	}
};