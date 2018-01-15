#include<iostream>
#include<stdlib.h>
using namespace std;
bool search(int* A, int lenght, int key)
{
	for(int i=0;i<lenght;i++)
	{
		if(A[i]==key) return 1;
	}
	return 0;
}