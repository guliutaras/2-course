#include "SLAEsolving.h"


void Simple_metod()
{
	double A[n][n]= {
		{-7,3,2},
		{2,-5,2},
		{1,1,-4}
	};
	double f[n]={-4,-2,-4};
	double del=0;
	double g[n]={-4,-2,-4};
	double cur[n]={0,0,0};
	double next[n]={0,0,0};
	double B[n][n]= {
		{-7,3,2},
		{2,-5,2},
		{1,1,-4}
	};
	for (int i = 0; i < n; i++)
	{
		del = B[i][i];
		g[i]=g[i]/del;
		for (int j = 0; j < n; j++)
			if (i == j)
				B[i][j]=0;
			else
				B[i][j]=(-1.0)*(B[i][j]/del);
	}
	double norm3=0;
	for(int i=0; i<n;i++)
		cur[i]=g[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			norm3=norm3+fabs(B[i][j])*fabs(B[i][j]);
	norm3=pow(norm3,0.5);
	cout<<norm3;
	int i=0;
	double stap=1;
	double normcheak1 = ((1 - norm3) / norm3) * 0.00001;
	int k=0;
	for(k=0; stap>=normcheak1; k++)
	{
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j <n; j++)
				next[i]+=(B[i][j]*cur[j]);
			next[i] += g[i];
		}
		stap=normcheak(cur,next);
		if(stap>=normcheak1)
		{
		for( int l=0; l<n; l++)
		{
			cur[l]=next[l];
			next[l]=0;
		}
		}
	}
	cout<<"Simple metod-------"<<endl;
	cout<<"Iter: "<<k<<" Vidpovid: "<<next[0]<<" "<<next[1]<<" "<<next[2]<<endl;
	vidhil((&A)[0],next,f);
}