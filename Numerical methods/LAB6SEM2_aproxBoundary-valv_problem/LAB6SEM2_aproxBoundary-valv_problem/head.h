#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// y"+y'-y*cos x=x
//y(0)=1
//y(1)=0
const int n=5;
const double h=0.2;
const double alf0=1;
const double bet0=1;
const double y0_1=0;
const double y0_2=1;
const double A=1;
const double B=0;


void Colocation();
void Grid_metod();
void Leastsqrt_metod();