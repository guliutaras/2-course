#include "head.h"
#include"funk.h"
void Simp_funk()
{
	double h=(b-a)/n;
	double odd=0;
	double even=0;
	double S=0;
	for(int i=1; i<6; i++)
		odd+=fx(a+((2*i)-1)*h);
	for(int i=1; i<5; i++)
		even+=fx(a+2*i*h);
	S=(h/3)*(fx(a)+fx(a+10*h)+4*odd+2*even);
	cout<<S<<endl;
	odd=0;
	even=0;
	h=h/2;
	double S2;
	for(int i=1; i<11; i++)
		odd+=fx(a+((2*i)-1)*h);
	for(int i=1; i<10; i++)
		even+=fx(a+2*i*h);
	S2=(h/3)*(fx(a)+fx(a+20*h)+4*odd+2*even);
	double Rug=0;
	Rug=fabs(S2-S)/15;
	cout<<Rug<<endl;

}