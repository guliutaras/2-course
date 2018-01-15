#include <iostream>
#include <stdlib.h>
#include "Funktion.h"
using namespace std;

int main(int argc,char* argv[])
{
	int choose;
	setlocale(LC_ALL, "Russian");
	cout<<"��� ������������ ������������ ������ �1 3 ��������"<<endl;
	cout<<"�������� ��������� ������"<<endl;
	cout<<"1-������ � �����������"<<endl;
	cout<<"2-������ � ����������� ���������"<<endl;
	cout<<"3-������ � ������"<<endl;
	cin>>choose;
	switch (choose)
	{
	case 1:{
		cout<<"�������� ������� ���������� ���� �� � �� �"<<endl;
		if(argc>2){
			bool flag;
			cout<<"���� ���������� ����������� ��������� ��������� ������"<<endl;
			cout<<"������ �������� - �"<<endl;
			cout<<"������ - �"<<endl;
			cout<<"������ ��������������� �������? 1/0 '��/���"<<endl;
			cin>>flag;
			if(flag){cout<<"C���� ����� �� � �� �= "<<suman(atoi(argv[1]),atoi(argv[2]))<<endl;break;}
		}
			int a,b;
			cout<<"������� ����� �"<<endl;
			cin>>a;
			cout<<"������� ����� �"<<endl;
			cin>>b;
			cout<<"C���� ����� �� � �� �= "<<suman(a,b)<<endl;
		break;}
	case 2:{
		cout<<"�������� ������� ������ � ������������� �������"<<endl;
		if(argc>3)
		{
			bool flag;
			cout<<"���� ���������� ����������� ��������� ��������� ������"<<endl;
			cout<<"������ �������� - ������� �����"<<endl;
			cout<<"������ - ������ �������"<<endl;
			cout<<"��������� - �������� �������"<<endl;
			cout<<"������ ��������������� �������? 1/0 '��/���"<<endl;
			cin>>flag;
			if(flag)
			{
				int n=atoi(argv[2]);
				if(n<=0) {cout<<"������� �� �������� � ������ �������"<<endl; return 1;}
				int*A=new int [n];
				for (int i=0;i<n;i++)
					A[i]=atoi(argv[i+3]);
				if(search(A,n,atoi(argv[1])))
				{cout<<"������� ���� � �������"<<endl;}
				else{cout<<"������� � ������� ���"<<endl;}
				delete []A;
				break;
			}
		}
		
			int n,key;
			cout<<"������� ������ �������"<<endl;
			cin>>n;
			if(n<=0) {cout<<"������� �� �������� � ������ �������"<<endl; return 1;}
			cout<<"������� ������� �����"<<endl;
			cin>>key;
			int*A=new int [n];
			for(int i=0;i<n;i++)
			{
				cout<<"������� "<<i+1<<" ������� �������"<<endl;
				cin>>A[i];
			}
			if(search(A,n,key))
			{cout<<"������� ���� � �������"<<endl;}
			else{cout<<"������� � ������� ���"<<endl;}
			delete []A;
		
		break;}
	case 3:{
		cout<<"�������� ������� ���������� ������ �����"<<endl;
		if(argc!=1)
		{
			bool flag;
			cout<<"���� ���������� ����������� ��������� ��������� ������"<<endl;
			cout<<"������ ����� ��� ��������"<<endl;
			cout<<"������ ��������������� �������? 1/0 '��/���"<<endl;
			cin>>flag;
			if(flag){cout<<"������ ����� ���������� "<<lenght(argv[1])<<" ��������"<<endl;break;}
		}
		
			char word[40];
			cout<<"������� �����"<<endl;
			cin>>word;
			cout<<"������ ����� ���������� "<<lenght(word)<<" ��������"<<endl;
		
		break;}
	default: cout<<"�� ����� ������������ ������"<<endl;
	}
	system("pause");
	return 0;
}