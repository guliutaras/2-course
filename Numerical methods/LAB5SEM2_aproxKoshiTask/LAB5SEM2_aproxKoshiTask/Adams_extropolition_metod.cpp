#include "head.h"
#include "funk.h"

void Adams_extropolition(double *y)
{
	double h=0.1;
	double xn=0;
	double yn=0;
	for(int i=0; i<N1; i++)
	{
		xn=xn+h;
		if(i<4)cout<<"i= "<<i<<" xn= "<<xn<<" yn= "<<y[i]<<endl;
		if(i==4)
		{
			yn=y[3]+(h/24)*(55*fx(xn-h,y[3])-59*fx(xn-2*h,y[2])+37*fx(xn-3*h,y[1])-9*fx(xn-4*h,y[0]));
			cout<<"i= "<<i<<" xn= "<<xn<<" yn= "<<yn<<endl;
		}
		if(i>4)
		{
			y[0]=y[1];
			y[1]=y[2];
			y[2]=y[3];
			y[3]=yn;
			yn=yn+(h/24)*(55*fx(xn-h,y[3])-59*fx(xn-2*h,y[2])+37*fx(xn-3*h,y[1])-9*fx(xn-4*h,y[0]));
			cout<<"i= "<<i<<" xn= "<<xn<<" yn= "<<yn<<endl;
		}
	}
}
