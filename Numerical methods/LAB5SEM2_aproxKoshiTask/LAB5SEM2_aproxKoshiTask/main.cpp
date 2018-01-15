#include "head.h"

int main()
{
	double ToNext[4]={0,0,0,0};
	cout<<" Eiler metods------"<<endl;
	Eiler_main();
	cout<<" Runge metods------"<<endl;
	Runge_main(ToNext);
	cout<<" Adams extropoliation------"<<endl;
	Adams_extropolition(ToNext);
	system("pause");
	return 0;

}