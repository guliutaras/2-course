#include "SLAEsolving.h"

void Sqrroot_metod()
{	double A[n][n] = {
	{ 1,-2,-5 },
	{ -2,13,16 },
	{ -5,16,33 }};
	double f[n]={18,-18,18};
	double y[n]={0,0,0};
	double x[n]={0,0,0};
	double S[n][n]= {
	{ 0,0,0 },
	{ 0,0,0 },
	{ 0,0,0 }}; 
	double St[n][n]= {
	{ 0,0,0 },
	{ 0,0,0 },
	{ 0,0,0 }};
	double res[n];
	double tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i)
			{
				tmp = 0;
				for (int k = 0; k <=i-1; k++)
					tmp += pow(S[k][i], 2);
				S[i][i] = sqrt(A[i][i] - tmp);
			}
			if (i < j)
			{
				tmp = 0;
				for (int k = 0; k<=i-1; k++)
					tmp += S[k][i] * S[k][j];
				S[i][j] = (A[i][j] - tmp) / S[i][i];
			}
		}
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			St[j][i]=S[i][j];
	y[0]=f[0]/St[0][0];
	y[1]=(f[1]-St[1][0]*y[0])/St[1][1];
	y[2]=(f[2]-St[2][0]*y[0]-St[2][1]*y[1])/St[2][2];
	x[2]=y[2]/S[2][2];
	x[1]=(y[1]-S[1][2]*x[2])/S[1][1];
	x[0]=(y[0]-S[0][2]*x[2]-S[0][1]*x[1])/S[0][0];
	cout<<"Square root metod-------"<<endl;
	cout<<"Vidpovid :"<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
	vidhil((&A)[0],x,f);
}