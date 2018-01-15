#include<iostream>
#include<stdlib.h>
using namespace std;
int lenght(char* A)
{
	int i=0;
	while(A[i]!='\0')
		i++;
	return i;
}