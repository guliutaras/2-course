#include <iostream>
#include <ctime>
#include <locale>
#include <iomanip>
using namespace std;

extern "C" __declspec(dllimport) float functionMin(int (*A)[3]);
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");

	cout << "���������� ������������ ������." << endl << endl;
	int A[3][3];
	cout << "������" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			A[i][j] = rand() % 21 - 10;
			cout << setw(3) << A[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout<<endl;
	cout<<"��������� ������������ � �����: ";
	float vodnosh = functionMin((&A)[0]);
	cout<<vodnosh<<endl;
	system("pause");
	return 0;
}