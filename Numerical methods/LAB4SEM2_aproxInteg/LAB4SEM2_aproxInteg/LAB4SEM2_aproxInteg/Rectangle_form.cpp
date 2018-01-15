#include "head.h"

#include"funk.h"
void Rect_funk()
{
	double h=(b-a)/n;
	double Rleft=0, Rright=0, Rmidl=0;
	for(int i=0; i<n; i++)
	{
		double xk=a+i*h;
		Rleft+=fx(xk);
	}
	Rleft=Rleft*h;
	for(int i=0; i<n; i++)
	{
		double xk=a+(i+1)*h;
		Rright+=fx(xk);
	}
	Rright=Rright*h;
	for(int i=0; i<n; i++)
	{
		double xk=a+(i+1/2.)*h;
		Rmidl+=fx(xk);
	}
	Rmidl=Rmidl*h;
	cout<<Rleft<<" "<<Rmidl<<" "<<Rright<<endl;
}