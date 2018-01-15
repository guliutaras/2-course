#include "head.h"
#include "funk.h"

double delta(double y2, double y1);
void Runge_static(double n);
int Runge_auto(double e, double* next);
double runge(double h, double xn, double yn);
double runge2(double h, double xn, double yn);

void Runge_main(double *next)
{
	int N2=0;
	double e=0;
	cout<<"Auto itarator"<<endl;
	N2=Runge_auto(e,next);
	cout<<"Static itarator"<<endl;
	Runge_static(N2);
}

int Runge_auto(double e, double* next)
{
	int n=0;
	double hstart=0.1;
	double y1=0;
	double y21=0;
	double y22=0;
	double yn=0;
	double xn=0;
	double adamstemp=0;
	double gamma;
	do
	{
		do
		{
		y1=runge(hstart,xn,yn);
		y21=runge(hstart/2.0,xn,yn);
		y22=runge(hstart/2.0,xn+(hstart/2.0),y21);
		gamma=fabs((y22-y1)/(pow(2.0,3.0)-1));
		if(gamma>=e1) {hstart=hstart/2;}
		}while(gamma>=e1);
		xn=xn+hstart;
		yn=y22+((y22-y1)/(pow(2.0,3.0)-1));
		n++;
		cout<<"n= "<<n<<" xn= "<<xn<<" yn= "<<yn<<endl;
		if(gamma<=(e1/pow(2.0,4.0)))hstart=hstart*2;
		double delta=b-xn;
		if(hstart>delta)hstart=delta;
	}while ((b-xn)>=e2);
	double xn1=0;
	double h=0.1;
	for(int i=0; i<n; i++)
	{
		
		next[i]=runge(h,xn1,adamstemp);
		adamstemp=next[i];
		xn1=xn1+h;
	}
	return n;
}

double runge(double h, double xn, double yn)
{
	double k1=h*fx(xn,yn);
	double k2=h*fx(xn+(h/3.0),yn+(k1/3.0));
	double k3=h*fx(xn+((2.*h)/3.0),yn+((2.*k2)/3.0));
	return(yn+(k1/4.0)+((3.*k3)/4.0));
}

void Runge_static(double n)
{
	double h=(b-a)/n;
	double xn=0;
	double yn=0;
	for(int i=0; i<n; i++)
	{
	
		yn=runge(h,xn,yn);
		cout<<"i= "<<i<<" xn= "<<xn+h<<" yn= "<<yn<<endl;
		xn=xn+h;
	}
}