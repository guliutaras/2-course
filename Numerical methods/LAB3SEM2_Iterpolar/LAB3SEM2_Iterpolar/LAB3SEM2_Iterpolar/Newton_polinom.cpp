#include "head.h"

void counthalfdif(double tempL[5])
{
	double temp[10]={0,0,0,0,0,0,0,0,0,0};
	tempL[0]=dots[1][0];
	temp[0]=(dots[1][1]-dots[1][0])/(dots[0][1]-dots[0][0]);
	temp[1]=(dots[1][2]-dots[1][1])/(dots[0][2]-dots[0][1]);
	temp[2]=(dots[1][3]-dots[1][2])/(dots[0][3]-dots[0][2]);
	temp[3]=(dots[1][4]-dots[1][3])/(dots[0][4]-dots[0][3]);
	tempL[1]=temp[0];
	temp[4]=(temp[1]-temp[0])/(dots[0][2]-dots[0][0]);
	temp[5]=(temp[2]-temp[1])/(dots[0][3]-dots[0][1]);
	temp[6]=(temp[3]-temp[2])/(dots[0][4]-dots[0][2]);
	tempL[2]=temp[4];
	temp[7]=(temp[5]-temp[4])/(dots[0][3]-dots[0][0]);
	temp[8]=(temp[6]-temp[5])/(dots[0][4]-dots[0][1]);
	tempL[3]=temp[7];
	temp[9]=(temp[8]-temp[7])/(dots[0][4]-dots[0][0]);
	tempL[4]=temp[9];

}

void polinomcreate(double polin[5],double difsum, int por)
{
	for(int i=0; i<5; i++)
		polin[i]=0;
	switch(por)
	{
	case 0:
		{
			polin[4]=difsum;
			return;
		}
	case 1:
		{
			polin[4]=-(difsum*dots[0][0]);
			polin[3]=difsum;
			return;
		}
	case 2:
		{
			polin[4]=difsum*dots[0][0]*dots[0][1];
			polin[3]=difsum*(-dots[0][0]-dots[0][1]);
			polin[2]=difsum;
			return;
		}
	case 3:
		{
			polin[4]=-(difsum*dots[0][0]*dots[0][1]*dots[0][2]);
			polin[3]=difsum*(dots[0][0]*dots[0][1]+dots[0][0]*dots[0][2]+dots[0][1]*dots[0][2]);
			polin[2]=difsum*(-dots[0][0]-dots[0][1]-dots[0][2]);
			polin[1]=difsum;
			return;
		}
	case 4:
		{
			polin[4]=difsum*dots[0][0]*dots[0][1]*dots[0][2]*dots[0][3];
			polin[3]=-(difsum*(dots[0][0]*dots[0][1]*dots[0][2]+dots[0][0]*dots[0][1]*dots[0][3]+dots[0][1]*dots[0][2]*dots[0][3]+dots[0][0]*dots[0][2]*dots[0][3]));
			polin[2]=difsum*(dots[0][0]*dots[0][1]+dots[0][0]*dots[0][2]+dots[0][1]*dots[0][2]+dots[0][0]*dots[0][3]+dots[0][1]*dots[0][3]+dots[0][2]*dots[0][3]);
			polin[1]=difsum*(-dots[0][0]-dots[0][1]-dots[0][2]-dots[0][3]);
			polin[0]=difsum;
			return;
		}
	}
}
void Newton_funk(double NewUP[5])
{
	double halfhdifL[5]={0,0,0,0,0};
	double polin[5];
	counthalfdif(halfhdifL);
	for(int i=0; i<5; i++)
	{
		polinomcreate(polin,halfhdifL[i],i);
		for(int j=0; j<5;j++) NewUP[j]+=polin[j];
	}
	for(int i=0; i<5; i++)
	{
		if(i==4){cout<<NewUP[i]<<"x^"<<4-i<<endl; break;}
		cout<<setprecision(20)<<NewUP[i]<<"x^"<<4-i<<" + ";	
	}
}