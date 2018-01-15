#include "Root_Methods.h"

void Newton_metod()
{
	double  xn=1,fx=pow(xn,3)+xn-4, f1x=3*pow(xn,2)+1;
	int n=0;
	for(n;(fabs(fx)/m1)>e;n++)
	{
		fx=pow(xn,3)+xn-4;
		f1x=3*pow(xn,2)+1;
		xn=xn-fx/f1x;
	}
	cout<<"Количество иттераций: "<<n<<endl;
	cout<<"Корень уравнения = "<<setprecision(30)<<xn<<endl;
}