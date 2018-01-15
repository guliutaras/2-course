#include "SLAEsolving.h"


void Gause_metod()
{
	double arrG[n][m] = {
	{2,-5,2,-2},
	{1,1,-4,-4},
	{-7,3,2,-4} };
	double G[n][n] = {
	{2,-5,2},
	{1,1,-4},
	{-7,3,2} };
	double f[n]={-2,-4,-4};
	double res[n]={0,0,0};
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
	res[2]=arrG[n-1][m-1];
	res[1]=arrG[1][m-1]-res[2]*arrG[1][2];
	res[0]=arrG[0][m-1]-res[2]*arrG[0][2]-res[1]*arrG[0][1];
	cout<<"Gause metod-------"<<endl;
	cout<<"Vidpovid :"<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
	vidhil((&G)[0],res,f);
}
