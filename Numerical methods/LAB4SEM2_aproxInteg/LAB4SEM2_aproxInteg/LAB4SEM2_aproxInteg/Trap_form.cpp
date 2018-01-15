#include "head.h"
#include"funk.h"
void Trap_funk()
{
	double h=(b-a)/n;
	double T=0;
	double temp=0;
	for(int i=1; i<n; i++)
	{
		double xk=a+i*h;
		temp+=fx(xk);
	}
	T=((h/2)*(fx(a)+fx(a+10*h)))+(h*temp);
	cout<<T<<endl;
}