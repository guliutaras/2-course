#include "SLAEsolving.h"

void coutmas(double (*A)[n], int row, int column)
{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
				cout << setw(4) << A[i][j] << " ";
			cout << endl;
		}
		cout << endl;
}
double normcheak(double *cur, double *last)
{
	double norm3=0;
	for (int i = 0; i < n; i++)
		norm3 += pow((last[i] - cur[i]), 2);
	return sqrt(norm3);
}
void vidhil(double (*G)[n], double *res, double *f)
{
	double sigma[n]={0,0,0};
	for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				sigma[i] += G[i][j] * res[j];
	cout<<"Vidhil: "<<sigma[0]-f[0]<<" "<<sigma[1]-f[1]<<" "<<sigma[2]-f[2]<<endl;
}