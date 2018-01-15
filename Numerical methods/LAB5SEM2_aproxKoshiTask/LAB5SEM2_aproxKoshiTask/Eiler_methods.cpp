#include "head.h"
#include "funk.h"



void Eiler(double *dots);
void Eiler_Koshi(double *dots);
void Eiler_accurat(double *dots);

void Eiler_main()
{
	double ei[5]={0,0,0,0,0};
	double ek[5]={0,0,0,0,0};
	double ea[5]={0,0,0,0,0};
	Eiler(ei);
	Eiler_Koshi(ek);
	Eiler_accurat(ea);
	cout<<setprecision(6)<<setw(4)<<"Eiler"<<setw(16)<<"Eiler-Koshi"<<setw(16)<<"Eiler Accurat"<<endl;
	for(int i=0; i<N; i++)
	{
		cout<<setprecision(6)<<setw(4)<<ei[i]<<setw(16)<<ek[i]<<setw(16)<<ea[i]<<endl;
	}
}

void Eiler(double *dots)
{
	double h=(b-a)/N;
	double yn=0;
	for(int n=0; n<N; n++)
	{
		double xn=a+n*h;
		yn=yn+h*fx(xn,yn);
		dots[n]=yn;
	}
}

void Eiler_Koshi(double *dots)
{
	double h=(b-a)/N;
	double yn=0;
	double yn1=0;
	for(int n=0; n<N; n++)
	{
		double xn=a+n*h;
		double xn1=a+(n+1)*h;
		yn1=yn+h*fx(xn,yn);
		yn=yn+(h/2.0)*(fx(xn,yn)+fx(xn1,yn1));
		dots[n]=yn;
	}
}

void Eiler_accurat(double *dots)
{
	double h=(b-a)/N;
	double yn=0;
	double ynl=0;
	double ynn=0;
	for(int n=0; n<N; n++)
	{
		double xn=a+n*h;
		double xn1=a+(n+1)*h;
		ynl=yn+h*fx(xn,yn);
		for(int k=1; fabs(ynn-ynl)>e1; k++)
		{
			ynl=ynn;
			ynn=yn+(h/2.0)*(fx(xn,yn)+fx(xn1,ynl));
		}
		yn=ynn;
		dots[n]=yn;
	}
}