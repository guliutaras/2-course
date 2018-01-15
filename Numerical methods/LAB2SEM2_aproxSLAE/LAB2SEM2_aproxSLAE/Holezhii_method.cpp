#include "SLAEsolving.h"

void Holizhkii_metod()
{
	double A[n][n] = {
		{-7,3,2},
		{2,-5,2},
		{1,1,-4}
	};
	double f[n]={-4,-2,-4 };
	double y[n]={0,0,0 };
	double x[n]={0,0,0 };
	double C[n][n] = {
	{ 1,0,0 },
	{ 0,1,0 },
	{ 0,0,1 }
	};
	double B[n][n] = {
	{ 0,0,0 },
	{ 0,0,0 },
	{ 0,0,0 }
	};
	for (int i = 0; i < n; i++)
	{
		B[i][0] = A[i][0];
		C[0][i] = A[0][i]/B[0][0];
	}
	double temp;
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n; j++)
		{
			temp = 0;
			for (int k = 0; k < i; k++)
				temp += B[i][k]*C[k][j];
			if (i>=j) B[i][j] = A[i][j]-temp;
			if (i<j) C[i][j] = (1.0/B[i][i])*(A[i][j]-temp);
		}
	coutmas((&B)[0],n,n);
	coutmas((&C)[0],n,n);
	y[0]=f[0]/B[0][0];
	y[1]=(f[1]-y[0]*B[1][0])/B[1][1];
	y[2]=(f[2]-y[0]*B[2][0]-y[1]*B[2][1])/B[2][2];
	x[2]=y[2];
	x[1]=(y[1]-x[2]*C[1][2]);
	x[0]=(y[0]-x[1]*C[0][1]-x[2]*C[0][2]);
	cout<<"Holizkii metod-------"<<endl;
	cout<<"Vidpovid :"<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
	vidhil((&A)[0],x,f);
}