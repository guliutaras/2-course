#include "head.h"
#include "funk.h"



double Ai(double x){return (1+(h/2)*px());}
double Bi(double x){return (-2+h*h*qx(x));}
double Ci(double x){return (1-(h/2)*px());}
double Fi(double x){return (h*h*fx(x));}

void Masfill( double arr[][4])
{
	double xi=0;
	for(int i=0; i<4; i++)
	{
		xi=xi+h;
		arr[0][i]=xi;
		arr[1][i]=Ai(xi);
		arr[2][i]=Bi(xi);
		arr[3][i]=Ci(xi);
		arr[4][i]=Fi(xi);
	}
}

void Grid_metod()
{
	double k1=0;
	double k2=0;
	double F0=(A*h)/(-h*alf0);
	double F5=(-B*h)/(h*bet0);
	double arr[5][4]={
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}};
	double mg[2][5]={
		{0,0,0,0,0},
		{0,0,0,0,0},
	};
	double y[6]={0,0,0,0,0,0};

	Masfill(arr);
	mg[0][0]=k1;
	mg[1][0]=-F0;

	for(int i=1; i<n; i++)
	{
		mg[0][i]=(arr[1][i-1])/(arr[2][i-1]-arr[3][i-1]*mg[0][i-1]);
		mg[1][i]=(arr[4][i-1]-arr[3][i-1]*mg[1][i-1])/(arr[2][i-1]-arr[3][i-1]*mg[0][i-1]);
	}
	y[5]=(k2*mg[1][4]-F5)/(1+k2*mg[0][4]);
	y[4]=mg[1][4]-mg[0][4]*y[5];
	y[3]=mg[1][3]-mg[0][3]*y[4];
	y[2]=mg[1][2]-mg[0][2]*y[3];
	y[1]=mg[1][1]-mg[0][1]*y[2];
	y[0]=mg[1][0];
	double xi=0;
	cout<<"Grid metod------"<<endl;
	cout<<"xi"<<" "<<"yi"<<endl;
	for(int i=0; i<6; i++){cout<< xi <<" "<<y[i]<<endl;xi=xi+h;}
}