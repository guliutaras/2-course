#include "Root_Methods.h"


void Newton_metod_nolin()
{
	double  xn=-2,fx=pow(xn,3)+2*pow(xn,2)-sin(3*xn+1), f1x=3*pow(xn,2)+4*xn-3*(cos(3*xn+1)),m;
	m=fabs(f1x);
	int n=0;
	for(n;(fabs(fx)/m)>e;n++)
	{
		fx=pow(xn,3)+2*pow(xn,2)-sin(3*xn+1);
		f1x=3*pow(xn,2)+4*xn-3*(cos(3*xn+1));
		xn=xn-fx/f1x;
	}
	cout<<"Количество иттераций: "<<n<<endl;
	cout<<"Корень уравнения x_1= "<<setprecision(30)<<xn<<endl;
	xn=-0.5;
	m=fabs(3*0.1*0.1*0.1+4*0.1-3*cos(3*0.1+1));
	cout<<m<<endl;
	n=0;
	fx=pow(xn,3)+2*pow(xn,2)-sin(3*xn+1);
	f1x=3*pow(xn,2)+4*xn-3*(cos(3*xn+1));
	for(n;(fabs(fx)/m)>e;n++)
	{
		fx=pow(xn,3)+2*pow(xn,2)-sin(3*xn+1);
		f1x=3*pow(xn,2)+4*xn-3*(cos(3*xn+1));
		xn=xn-fx/f1x;
	}
	cout<<"Количество иттераций: "<<n<<endl;
	cout<<"Корень уравнения x_2= "<<setprecision(30)<<xn<<endl;
	xn=0.5;
	n=0;
	fx=pow(xn,3)+2*pow(xn,2)-sin(3*xn+1);
	f1x=3*pow(xn,2)+4*xn-3*(cos(3*xn+1));
	m=fabs(f1x);
	cout<<m<<endl;
	for(n;(fabs(fx)/m)>e;n++)
	{
		fx=pow(xn,3)+2*pow(xn,2)-sin(3*xn+1);
		f1x=3*pow(xn,2)+4*xn-3*(cos(3*xn+1));
		xn=xn-fx/f1x;
	}
	cout<<"Количество иттераций: "<<n<<endl;
	cout<<"Корень уравнения x_3= "<<setprecision(30)<<xn<<endl;

}