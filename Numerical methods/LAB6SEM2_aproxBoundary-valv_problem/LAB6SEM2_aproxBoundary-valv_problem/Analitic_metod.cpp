#include "head.h"
#include "funk.h"

double u0x(double x){return (1-x);}
double u1x(double x){return (x*(x-1));}
double u2x(double x){return (x*x*(x-1));}

double Lu0(double x){return (-1-(1-x)*cos(x));}
double Lu1(double x){return (2+(2*x-1)-(x*x-x)*cos(x));}
double Lu2(double x){return ((6*x-2)+(3*x*x-2*x)-(x*x*x-x*x)*cos(x));}

void Gause_metod(double **arrG,double *res,int n,int  m)
{
	double tmp;
	for (int i=0; i<n;i++)
	{
		for(int j=i+1; j<m; j++)
		{
			arrG[i][j]=arrG[i][j]/arrG[i][i];
		}
		arrG[i][i]=1;
		for(int k=i+1; k<n; k++)
		{ double temp=arrG[k][i];
			for(int j=i; j<m; j++)
			{
				arrG[k][j]=arrG[k][j]+(-arrG[i][j])*temp;
			}
		}
	}
	res[1]=arrG[1][2];
	res[0]=arrG[0][2]-res[1]*arrG[0][1];
}


void Colocation()
{
	double x1=0.25;
	double x2=0.5;
	double ** arr =new double *[2];
	for(int i=0; i<2; i++)
		arr[i]=new double [3];
	double res[2]={0,0};
	arr[0][0]=Lu1(x1);
	arr[0][1]=Lu2(x1);
	arr[0][2]=fx(x1)-Lu0(x1);
	arr[1][0]=Lu1(x2);
	arr[1][1]=Lu2(x2);
	arr[1][2]=fx(x2)-Lu0(x2);
	Gause_metod(arr,res,2,3);
	double xi=0;
	cout<<"Colocation metod------"<<endl;
	cout<<"Function:"<<endl;
	cout<<"y1(x) = u0(x) + "<<res[0]<<" u1(x) + "<<res[1]<<" u2(x)"<<endl;
	cout<<"xi"<<" "<<"yi"<<endl;
	for(int i=0; i<6; i++)
	{
		double yi=u0x(xi)+u1x(xi)*res[0]+u2x(xi)*res[1];
		cout<< xi <<" "<<yi<<endl;
		xi=xi+h;
	}
	for (int i=0; i<2; i++){delete[] arr[i];}
}

double Simp_funk(int i)
{
	double odd=0;
	double even=0;
	double S=0;
	switch (i)
	{
	case 1:
		{
			for(double i=1; i<3; i++)
				odd+=Lu1(((2*i)-1)*h)*Lu1(((2*i)-1)*h);
			for(double i=1; i<3; i++)
				even+=Lu1(2*i*h)*Lu1(2*i*h);
			S=(h/3)*(Lu1(0)*Lu1(0)+Lu1(1)*Lu1(1)+4*odd+2*even);
			break;
		}
	case 2:
		{
			for(double i=1; i<3; i++)
				odd+=Lu2(((2*i)-1)*h)*Lu2(((2*i)-1)*h);
			for(double i=1; i<3; i++)
				even+=Lu2(2*i*h)*Lu2(2*i*h);
			S=(h/3)*(Lu2(0)*Lu2(0)+Lu2(1)*Lu2(1)+4*odd+2*even);
			break;
		}
	case 3:
		{
			for(double i=1; i<3; i++)
				odd+=Lu2(((2*i)-1)*h)*Lu1(((2*i)-1)*h);
			for(double i=1; i<3; i++)
				even+=Lu2(2*i*h)*Lu1(2*i*h);
			S=(h/3)*(Lu1(0)*Lu2(0)+Lu2(1)*Lu1(1)+4*odd+2*even);
			break;
		}
	case 4:
		{
			for(double i=1; i<3; i++)
				odd+=fx(((2*i)-1)*h)-Lu0(((2*i)-1)*h)*Lu1(((2*i)-1)*h);
			for(double i=1; i<3; i++)
				even+=fx(2*i*h)-Lu0(2*i*h)*Lu1(2*i*h);
			S=(h/3)*(fx(0)-Lu0(0)*Lu1(0)+fx(1)-Lu0(1)*Lu1(1)+4*odd+2*even);
			break;
		}
	case 5:
		{
			for(double i=1; i<3; i++)
				odd+=fx(((2*i)-1)*h)-Lu0(((2*i)-1)*h)*Lu2(((2*i)-1)*h);
			for(double i=1; i<3; i++)
				even+=fx(2*i*h)-Lu0(2*i*h)*Lu2(2*i*h);
			S=(h/3)*((fx(0)-Lu0(0)*Lu2(0))+(fx(1)-Lu0(1)*Lu2(1))+4*odd+2*even);
			break;
		}
	}
	return S;
}

void Leastsqrt_metod()
{
	double ** arr =new double *[2];
	for(int i=0; i<2; i++)
		arr[i]=new double [3];
	double res[2]={0,0};
	arr[0][0]=Simp_funk(1);
	arr[0][1]=Simp_funk(3);
	arr[0][2]=Simp_funk(4);
	arr[1][0]=Simp_funk(3);
	arr[1][1]=Simp_funk(2);
	arr[1][2]=Simp_funk(5);
	Gause_metod(arr,res,2,3);
	double xi=0;
	cout<<"The least sqrtmetod metod(with Simpson integral)------"<<endl;
	cout<<"Function:"<<endl;
	cout<<"y2(x) = u0(x) + "<<res[0]<<" u1(x) + "<<res[1]<<" u2(x)"<<endl;
	cout<<"xi"<<" "<<"yi"<<endl;
	for(int i=0; i<6; i++)
	{
		double yi=u0x(xi)+u1x(xi)*res[0]+u2x(xi)*res[1];
		cout<< xi <<" "<<yi<<endl;
		xi=xi+h;
	}
	for (int i=0; i<2; i++){delete[] arr[i];}
}