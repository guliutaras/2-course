#include "Root_Methods.h"

void Half_metod()
{
	double an=1, bn=2, xn=(an+bn)/2, fa, fb, fx;
	int n=0;
	fa=pow(an,3)+an-4;
	fb=pow(bn,3)+bn-4;
	fx=pow(xn,3)+xn-4;
	for(n;((bn-an)/2)>e;n++)
	{
		
		if(((fa>0) && (fx>0))||((fa<0) && (fx<0)))
		{
			an=xn;
			xn=(an+bn)/2;
			fa=pow(an,3)+an-4;
			fb=pow(bn,3)+bn-4;
			fx=pow(xn,3)+xn-4; continue;
		}
		if(((fb>0) && (fx>0))||((fb<0) && (fx<0)))
		{
			bn=xn;
			xn=(an+bn)/2;
			fa=pow(an,3)+an-4;
			fb=pow(bn,3)+bn-4;
			fx=pow(xn,3)+xn-4; 
		}
	}
	cout<<"Количество иттераций: "<<n<<endl;
	cout<<"Корень уравнения = "<<setprecision(30)<<xn<<endl;
}