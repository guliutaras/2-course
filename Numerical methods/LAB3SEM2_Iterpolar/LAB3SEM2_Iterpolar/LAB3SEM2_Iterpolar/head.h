#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const double dots[2][5]={
	{0,1,2,4,5},
	{-1,2,-2,3,0}};

void Lagran_funk(double Lag[5]);
void Newton_funk(double NewUP[5]);
void Midlesqrt_funk(double *M4sqr,double *M3sqr,double *M2sqr,double *M1sqr, double &Msqrt);