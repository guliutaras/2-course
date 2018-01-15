#include "head.h"

void gen_pol(double temp[5], int include)
{
	double mn,ml;
	ml=1;
	mn=dots[1][include];
	for(int i=0;i<5;i++)
	{
		temp[i]=0;
		if(i==include) continue;
		ml=ml*(dots[0][include]-dots[0][i]);
	}
	temp[0]=(mn/ml);
	for(int j=1; j<5; j++)
	{
		switch(j)
		{
		case 1:
			{
				double count=0;
				for(int l=0; l<5;l++)
					if(l!=include)count=count-dots[0][l];
				temp[j]=(mn/ml)*count;
				continue;
			}
		case 2:
			{
				double count=0;
				for(int l=0; l<5;l++)
					for(int i=l+1; i<5;i++)
						if((l!=include)&&(i!=include))count=count+dots[0][l]*dots[0][i];
				temp[j]=(mn/ml)*count;
				continue;
			}
		case 3:
			{
				double count=0;
				for(int l=0; l<5;l++)
					for(int i=l+1; i<5;i++)
						for(int k=i+1; k<5;k++)
							if((l!=include)&&(i!=include)&&(k!=include))count=count-dots[0][l]*dots[0][i]*dots[0][k];
				temp[j]=(mn/ml)*count;
				continue;
			}
		case 4:
			{
				double count=1;
				for(int l=0; l<5;l++)
					if(l!=include)count=count*dots[0][l];
				temp[j]=(mn/ml)*count;
				continue;
			}
		}
		
	}
}
void Lagran_funk(double Lag[5])
{
	double temp[5]={0,0,0,0,0};
	for(int i=0;i<5; i++)
	{
		gen_pol(temp, i);
		for(int j=0;j<5;j++) Lag[j]+=temp[j];
	}
	for(int i=0; i<5; i++)
	{
		if(i==4){cout<<Lag[i]<<"x^"<<4-i<<endl; break;}
		cout<<setprecision(20)<<Lag[i]<<"x^"<<4-i<<" + ";	
	}
}

