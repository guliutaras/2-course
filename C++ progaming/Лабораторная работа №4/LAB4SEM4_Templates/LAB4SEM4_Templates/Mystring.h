#pragma once
#include <iostream>
#define MAX_SIZE 1024
#define NULL 0

int strlen(char *word)// функция длинны строки
{
	int count = 0;
	while (*word++) ++count;
	return count;
}
int strcmp(char *a, char *b)//функция сравнение строк
{
	int c = 0;

	while (a[c] != '\0'|| b[c] != '\0')
	{
		if (a[c] > b[c]) return 1;
		if (a[c] < b[c]) return -1;
		c++;
	}
	return 0;
}

void strcpy(char* Dest, char* Sourse)//функция копирования строки в строку(без дописи)
{
	int i;
	for (i = 0; i < strlen(Sourse); i++)
		Dest[i] = Sourse[i];
	Dest[i] = '\0';
}
char* strstr(char *a, char *b)//нахождение подстроки
{
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] == b[0])
			return &a[i];
	return NULL;
}


class string
{
	char *str;
public:
	string():str(NULL){}
	string(char* strn){str=new char[strlen(strn)+1]; strcpy(str,strn);}
	string(const string &s){str=new char[strlen(s.str)+1]; strcpy(str,s.str);}
	bool operator>=(string &s)
	{
		for(int i=0; str[i]!='\0'||s.str[i]!='\0'; i++)
		{
			if (str[i]>s.str[i]) return 1;
			else if (str[i]<s.str[i]) return 0;
		}
		if(s.size()==this->size()) return 1;
		return 0;
	}
	bool operator<=(string &s)
	{
		for(int i=0; str[i]!='\0'||s.str[i]!='\0'; i++)
		{
			if (str[i]<s.str[i]) return 1;
			else if (str[i]>s.str[i]) return 0;
		}
		if(s.size()==this->size()) return 1;
		return 0;
	}
	string& operator=(string &s)
	{
		if (!str){str=new char[strlen(s.str)+1]; strcpy(str,s.str);}
		else{str=new char[strlen(s.str)+1]; strcpy(str,s.str);}
			if (strcmp(str,s.str)){delete[]str;}
		return *this;
	}
	bool operator>(string &s)
	{
		for(int i=0; str[i]!='\0'||s.str[i]!='\0'; i++)
		{
			if (str[i]>s.str[i]) return 1;
			else if (str[i]<s.str[i]) return 0;
		}
		return 0;
	}
	bool operator<(string &s)
	{
		for(int i=0; str[i]!='\0'||s.str[i]!='\0'; i++)
		{
			if(str[i]<s.str[i]) return 1;
			else if(str[i]>s.str[i]) return 0;
		}
		return 0;
	}
	bool operator==(string &s){if (!strcmp(str,s.str))return true; else return false;}
	int size(){return strlen(str);}
	friend std::ostream& operator<<(std::ostream &o,string &s)
	{
		return o<<s.str;
	}
	friend std::istream& operator>>(std::istream &i,string &s)
	{
		char tmpString[MAX_SIZE];
		i >> tmpString;
		if (s.str!=NULL) delete[]s.str;
		s.str = new char[strlen(tmpString)+1];	
		strcpy(s.str,tmpString);
		return i;
	}
	~string(){delete[]str;}
};