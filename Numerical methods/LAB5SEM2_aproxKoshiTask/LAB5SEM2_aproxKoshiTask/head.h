#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
  
using namespace std;

const double a=0;
const double b=1;
const double N=5;
const double N1=10;
const double e1=pow(10.0,-4.0);
const double e2=pow(10.0,-6.0);

void Eiler_main();
void Runge_main(double *next);
void Adams_extropolition(double *y);