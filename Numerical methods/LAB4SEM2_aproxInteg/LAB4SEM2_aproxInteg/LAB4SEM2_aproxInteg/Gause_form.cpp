#include "head.h"
#include"funk.h"

void Gausse_funk()
{
    const double t[6] = { -0.9782286581,-0.8870625997,-0.7301520055,-0.5190961292,-0.2695431559,0.0 };
    const double A[6] = { 0.0556685671,0.1255803694,0.1862902109,0.2331937645,0.2628045445,0.2729250867 };
 
    double sum = 0;
   
    for (int i = 0; i < 6; i++)
        sum += A[i] * fx((3. + t[i]) / 2.);
    for (int i = 4; i != -1; i--)
        sum += A[i] * fx((3. + (-1)*t[i]) / 2.);
 
    cout<<sum*((b-a)/2.)<<endl;;
}