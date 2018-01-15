#include <iostream>
#include <stdlib.h>
#include "Funktion.h"
using namespace std;

int main(int argc,char* argv[])
{
	int choose;
	setlocale(LC_ALL, "Russian");
	cout<<"Вас приветствует лабораторная работа №1 3 семестра"<<endl;
	cout<<"Выберете структуру данных"<<endl;
	cout<<"1-работа с переменными"<<endl;
	cout<<"2-работа с одномерными массивами"<<endl;
	cout<<"3-работа с словом"<<endl;
	cin>>choose;
	switch (choose)
	{
	case 1:{
		cout<<"ДОСТУПНА ФУНКЦИЯ НАХОЖДЕНИЯ СУМЫ ОТ А ДО В"<<endl;
		if(argc>2){
			bool flag;
			cout<<"Были обнаружены необходимые параметры командной строки"<<endl;
			cout<<"Первый параметр - а"<<endl;
			cout<<"Второй - в"<<endl;
			cout<<"Хотите воспользываться данными? 1/0 'Да/Нет"<<endl;
			cin>>flag;
			if(flag){cout<<"Cумма чисел от А до В= "<<suman(atoi(argv[1]),atoi(argv[2]))<<endl;break;}
		}
			int a,b;
			cout<<"Введите число а"<<endl;
			cin>>a;
			cout<<"Введите число в"<<endl;
			cin>>b;
			cout<<"Cумма чисел от А до В= "<<suman(a,b)<<endl;
		break;}
	case 2:{
		cout<<"ДОСТУПНА ФУНКЦИЯ ПОИСКА В ДИНАМИЧЕССКОМ МАССИВЕ"<<endl;
		if(argc>3)
		{
			bool flag;
			cout<<"Были обнаружены необходимые параметры командной строки"<<endl;
			cout<<"Первый параметр - искомое число"<<endl;
			cout<<"Второй - размер массива"<<endl;
			cout<<"Остальные - елементы массива"<<endl;
			cout<<"Хотите воспользываться данными? 1/0 'Да/Нет"<<endl;
			cin>>flag;
			if(flag)
			{
				int n=atoi(argv[2]);
				if(n<=0) {cout<<"Функция не работает с такими данными"<<endl; return 1;}
				int*A=new int [n];
				for (int i=0;i<n;i++)
					A[i]=atoi(argv[i+3]);
				if(search(A,n,atoi(argv[1])))
				{cout<<"Елемент есть в массиве"<<endl;}
				else{cout<<"Елемент в массиве нет"<<endl;}
				delete []A;
				break;
			}
		}
		
			int n,key;
			cout<<"Введите размер массива"<<endl;
			cin>>n;
			if(n<=0) {cout<<"Функция не работает с такими данными"<<endl; return 1;}
			cout<<"Введите искомое число"<<endl;
			cin>>key;
			int*A=new int [n];
			for(int i=0;i<n;i++)
			{
				cout<<"Введите "<<i+1<<" елемент массива"<<endl;
				cin>>A[i];
			}
			if(search(A,n,key))
			{cout<<"Елемент есть в массиве"<<endl;}
			else{cout<<"Елемент в массиве нет"<<endl;}
			delete []A;
		
		break;}
	case 3:{
		cout<<"ДОСТУПНА ФУНКЦИЯ НАХОЖДЕНИЯ ДЛИННЫ СЛОВА"<<endl;
		if(argc!=1)
		{
			bool flag;
			cout<<"Были обнаружены необходимые параметры командной строки"<<endl;
			cout<<"Строка взята как параметр"<<endl;
			cout<<"Хотите воспользываться данными? 1/0 'Да/Нет"<<endl;
			cin>>flag;
			if(flag){cout<<"Длинна слова составляет "<<lenght(argv[1])<<" символов"<<endl;break;}
		}
		
			char word[40];
			cout<<"Введите слово"<<endl;
			cin>>word;
			cout<<"Длинна слова составляет "<<lenght(word)<<" символов"<<endl;
		
		break;}
	default: cout<<"Вы ввели неправельный символ"<<endl;
	}
	system("pause");
	return 0;
}