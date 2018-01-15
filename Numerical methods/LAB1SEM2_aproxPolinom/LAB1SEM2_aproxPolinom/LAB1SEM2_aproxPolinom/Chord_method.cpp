#include "Root_Methods.h"

void Chord_metod()
{
	double xn=1,fx=pow(xn,3)+xn-4,fb=0,b=2;
	int n=0;
	fb=2*2*2+2-4;
	for(n;fabs(fx)/m1>e;n++)
	{
	fx=pow(xn,3)+xn-4;
	xn=xn-((fx)/(fb-fx))*(b-xn);
	}
	cout<<"Количество иттераций: "<<n<<endl;
	cout<<"Корень уравнения = "<<setprecision(30)<<xn<<endl;
}

