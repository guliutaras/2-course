#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double n,p,s;
  while(cin>>n>>p)
  {
     s=pow(p,1/n);
     cout<<ceil(s)<<endl;
  }
  return 0;
}