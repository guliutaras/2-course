#include "Root_Methods.h"

void Simple_metod()
{
	double a=2/(m1+M1),xn=1, fx=pow(xn,3)+xn-4;
	int n=0;
	for(n;(fabs(fx)/m1)>e;n++)
	{
		fx=pow(xn,3)+xn-4;
		xn=xn-a*fx;
	};
	cout<<"���������� ���������: "<<n<<endl;
	cout<<"������ ��������� = "<<setprecision(30)<<xn<<endl;
}


