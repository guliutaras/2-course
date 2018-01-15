#include <iostream>
#include <ctime>
#include <windows.h>
#include <locale>
#include <iomanip>
using namespace std;

typedef float (*LibraryFunction)(int (*A)[3]);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");

	HINSTANCE hLib;// ����������� ��������� �� ����������
	LibraryFunction  functionMin;// ����������� ��������� �� ������� �� ����������

	hLib = LoadLibrary(TEXT("Writeminfrom.dll"));// ��������� ����������
	if (hLib == NULL)// �����������?
	{
		printf("�� ������� ���������� ���������� 'Writeminfrom.dll'!\n");//���, �� �����������, ����� (((((
		return 1;
	}

	functionMin = (LibraryFunction)GetProcAddress(hLib, "functionMin");// ��������� ������� �� ����������
	if (!functionMin)// �����������??
	{
		cout << "�� ������� ����� ������� 'functionMin'!" << endl;// ���, (((((((((0((((
		system("pause");
		return 1;
	}
	else
		cout << "������� 'functionMin' ������� �������. ���������� ����� ������������� �������." << endl << endl;// �� )))))))0)))0)))
	cout << "������:" << endl;
	int A[3][3];
	int otnosh;
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			A[i][j] = rand() % 21 - 10;
			cout << setw(3) << A[i][j] << " ";
		}
		cout << setw(2) << "|" << endl;
	}
	otnosh=functionMin((&A)[0]);
	cout<<otnosh<<endl;
	FreeLibrary(hLib);// ��������� ���������� 
	system("pause");
	return 0;
}