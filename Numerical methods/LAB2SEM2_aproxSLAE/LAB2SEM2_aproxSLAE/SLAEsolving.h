#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int n = 3;
const int m = 4;
const double e = 0.0001;
void coutmas(double (*A)[n], int row, int column);
void Gause_metod();
void Sqrroot_metod();
void Holizhkii_metod();
void Simple_metod();
double normcheak(double *cur, double *last);
void vidhil(double (*G)[n], double *res, double *f);