#include "head.h"

void cheakin(double lag[5],double newt[5],double *M4sqr,double *M3sqr,double *M2sqr,double *M1sqr, double &Msqrt);
int main()
{
	double lag[5]={0,0,0,0,0};
	double newt[5]={0,0,0,0,0};
	double* mart4=new double [5];
	double* mart3=new double [4];
	double* mart2=new double [3];
	double* mart1=new double [2];
	double mart0;
	cout<<"LAB2SEM4- Solving system of algebric linear equaluation(SLAE)"<<endl;
	cout<<"Polinom Lagranzh"<<endl;
	Lagran_funk(lag);
	cout<<"Polinom Newton"<<endl;
	Newton_funk(newt);
	cout<<"Polinom of the least square"<<endl;
	Midlesqrt_funk(mart4,mart3,mart2,mart1, mart0);
	cheakin(lag,newt,mart4,mart3,mart2,mart1, mart0);
	delete[] mart4;
	delete[] mart3;
	delete[] mart2;
	delete[] mart1;
	system("pause");
	return 0;
}

void cheakin(double lag[5],double newt[5],double *M4sqr,double *M3sqr,double *M2sqr,double *M1sqr, double &Msqrt)
{
	cout<<"TABLET OF NUMERS"<<setw(20)<<setprecision(10)<<endl;
	cout<<setprecision(6)<<setw(4)<<"x"<<setw(16)<<"Ln(x)"<<setw(16)<<"Nn(x)"<<setw(16)<<"Q4n(x)"<<setw(16)<<"Q3n(x)"<<setw(16)<<"Q2n(x)"<<setw(16)<<"Q1n(x)"<<setw(16)<<"Q0n(x)"<<endl;
	for(double i=-1; i<7; i=i+0.5)
	{
		double l=0;
		l=(lag[0]*i*i*i*i)+(lag[1]*i*i*i)+(lag[2]*i*i)+(lag[3]*i)+lag[4];
		double n=0;
		n=(newt[0]*i*i*i*i)+(newt[1]*i*i*i)+(newt[2]*i*i)+(newt[3]*i)+newt[4];
		double m4=0;
		double m3=0;
		double m2=0;
		double m1=0;
		double m=0;
		m4=( M4sqr[0]*i*i*i*i)+( M4sqr[1]*i*i*i)+( M4sqr[2]*i*i)+( M4sqr[3]*i)+ M4sqr[4];
		m3=( M3sqr[0]*i*i*i)+( M3sqr[1]*i*i)+( M3sqr[2]*i)+ M3sqr[3];
		m2=( M2sqr[0]*i*i)+( M2sqr[1]*i)+ M2sqr[2];
		m1=( M1sqr[0]*i)+ M1sqr[1];
		m=Msqrt;
		cout<<setprecision(6)<<setw(4)<<i<<setw(16)<<l<<setw(16)<<n<<setw(16)<<m4<<setw(16)<<m3<<setw(16)<<m2<<setw(16)<<m1<<setw(16)<<m<<endl;
	}
}