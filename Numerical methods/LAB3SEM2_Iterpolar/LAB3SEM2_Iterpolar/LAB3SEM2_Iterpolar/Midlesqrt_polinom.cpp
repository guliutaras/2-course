#include "head.h"

void midlsqrt_mist(double *M4sqr,double *M3sqr,double *M2sqr,double *M1sqr, double &Msqrt)
{
	double M4wrong=0;
	double M3wrong=0;
	double M2wrong=0;
	double M1wrong=0;
	double Mwrong=0;
	for(int i=0; i<4; i++)
	{
		M4wrong+=pow((dots[1][i]-(M4sqr[0]*(dots[0][i]*dots[0][i]*dots[0][i]*dots[0][i])+M4sqr[1]*(dots[0][i]*dots[0][i]*dots[0][i])+M4sqr[2]*(dots[0][i]*dots[0][i])+M4sqr[3]*(dots[0][i])+M4sqr[4])),2.);
		M3wrong+=pow(dots[1][i]-(M3sqr[0]*(dots[0][i]*dots[0][i]*dots[0][i])+M3sqr[1]*(dots[0][i]*dots[0][i])+M3sqr[2]*(dots[0][i])+M3sqr[3]),2);
		M2wrong+=pow(dots[1][i]-(M2sqr[0]*(dots[0][i]*dots[0][i])+M2sqr[1]*(dots[0][i])+M2sqr[2]),2);
		M1wrong+=pow(dots[1][i]-(M1sqr[0]*(dots[0][i])+M1sqr[1]),2);
		Mwrong+=pow(dots[1][i]-Msqrt,2);
	}
	M4wrong=sqrt(M4wrong/5.);
	M3wrong=sqrt(M3wrong/5.);
	M2wrong=sqrt(M2wrong/5.);
	M1wrong=sqrt(M1wrong/5.);
	Mwrong=sqrt(Mwrong/5.);
	cout<<"Midle_sqrt vidhil: "<<endl;
	cout<<setprecision(10)<<"deltaQ4= "<<M4wrong<<endl;
	cout<<setprecision(10)<<"deltaQ3= "<<M3wrong<<endl;
	cout<<setprecision(10)<<"deltaQ2= "<<M2wrong<<endl;
	cout<<setprecision(10)<<"deltaQ1= "<<M1wrong<<endl;
	cout<<setprecision(10)<<"deltaQ0= "<<Mwrong<<endl;
}


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
	switch(n)
	{
	case 5:
		{
			res[4]=arrG[4][5];
			res[3]=arrG[3][5]-res[4]*arrG[3][4];
			res[2]=arrG[2][5]-res[4]*arrG[2][4]-res[3]*arrG[2][3];
			res[1]=arrG[1][5]-res[4]*arrG[1][4]-res[3]*arrG[1][3]-res[2]*arrG[1][2];
			res[0]=arrG[0][5]-res[4]*arrG[0][4]-res[3]*arrG[0][3]-res[2]*arrG[0][2]-res[1]*arrG[0][1];
			break;
		}
	case 4:
		{
			res[3]=arrG[3][4];
			res[2]=arrG[2][4]-res[3]*arrG[2][3];
			res[1]=arrG[1][4]-res[3]*arrG[1][3]-res[2]*arrG[1][2];
			res[0]=arrG[0][4]-res[3]*arrG[0][3]-res[2]*arrG[0][2]-res[1]*arrG[0][1];
			break;
		}
	case 3:
		{
			res[2]=arrG[2][3];
			res[1]=arrG[1][3]-res[2]*arrG[1][2];
			res[0]=arrG[0][3]-res[2]*arrG[0][2]-res[1]*arrG[0][1];
			break;
		}
	case 2:
		{
			res[1]=arrG[1][2];
			res[0]=arrG[0][2]-res[1]*arrG[0][1];
			break;
		}
	}
	for(int i=0; i<(n/2);i++)
	{
		 double temp=res[i];
		 res[i]=res[(n-1)-i];
		 res[(n-1)-i]=temp;
	}
	for(int i=0; i<n; i++)
	{
		if(i==(n-1)){cout<<res[i]<<"x^"<<(n-1)-i<<endl; break;}
		cout<<setprecision(5)<<res[i]<<"x^"<<(n-1)-i<<" + ";	
	}
	cout<<endl;
}

void Midlesqrt_funk(double *M4sqr,double *M3sqr,double *M2sqr,double *M1sqr, double &Msqrt)
{
	int n=5;
	int m=6;
	double **C4= new double* [n];
	double **C3= new double* [n-1];
	double **C2= new double* [n-2];
	double **C1= new double* [n-3];
	double C0=0;
	for (int i=0; i<n; i++)
	{
		C4[i]=new double [m];
		if(i<(n-1)) C3[i]=new double [m-1];
		if(i<(n-2)) C2[i]=new double [m-2];
		if(i<(n-3)) C1[i]=new double [m-3];
	}
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		{
			C4[i][j]=0;
			if(i<(n-1)&&j<(m-1)) C3[i][j]=0;
			if(i<(n-2)&&j<(m-2)) C2[i][j]=0;
			if(i<(n-3)&&j<(m-3)) C1[i][j]=0;
		}
	int k=0;
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5;j++)
		{
			for(int l=0; l<5; l++)
			C4[j][i]+=pow(dots[0][l],j+k);
		}
		k++;
	}
	for(int j=0; j<5;j++)
		for(int k=0; k<5;k++)
				C4[j][5]+=pow(dots[0][k],j)*dots[1][k];
	C0=0;
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-1; j++)
			C3[i][j]=C4[i][j];
	for(int i=0; i<n-2; i++)
		for(int j=0; j<n-2; j++)
				C2[i][j]=C4[i][j];
	for(int i=0; i<n-3; i++)
		for(int j=0; j<n-3; j++)
			C1[i][j]=C4[i][j];
	for(int i=0; i<n; i++)
	{
		if(i<(n-1)) C3[i][4]=C4[i][5];
		if(i<(n-2)) C2[i][3]=C4[i][5];
		if(i<(n-3)) C1[i][2]=C4[i][5];
	}
	Msqrt=C4[0][5]/C4[0][0];
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<6; j++)
			cout<<C4[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<5; j++)
			cout<<C3[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
			cout<<C2[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
			cout<<C1[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	Gause_metod(C4,M4sqr,5,6);
	Gause_metod(C3,M3sqr,4,5);
	Gause_metod(C2,M2sqr,3,4);
	Gause_metod(C1,M1sqr,2,3);
	cout<<Msqrt<<"x^0 "<<endl;
	midlsqrt_mist(M4sqr,M3sqr,M2sqr,M1sqr,Msqrt);
	for (int i=0; i<n; i++)
	{
		delete[] C4[i];
	}
	for (int i=0; i<n-1; i++)
	{
		delete[] C3[i];
	}
	for (int i=0; i<n-2; i++)
	{
		delete[] C2[i];
	}
	for (int i=0; i<n-3; i++)
	{
		delete[] C1[i];
	}
}