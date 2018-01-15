#include<iostream>
#include<stdlib.h>
using namespace std;
int suman(int a, int b)
{
	int S=0;
	if(a>b) swap(a,b);
	if(a==b) return 0;
	for(a;a<=b;a++)
	S+=a;
	return S;
}