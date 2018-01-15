#include <windows.h>
#include <iostream>
using namespace std;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)//������� ������� ����������
{
	switch (ul_reason_for_call)// ���������� ������� ����������
	{
	case DLL_PROCESS_ATTACH://������� "��������� ����������?"
		cout << "DLL_PROCESS_ATTACH: i'm attached!!" << endl;// ��������� � ��� ��� ���������� ����������
		break;
	case DLL_THREAD_ATTACH://�� ����
		break;
	case DLL_THREAD_DETACH://�� ���������(((
		break;
	case DLL_PROCESS_DETACH://������� "��������� ���������?"
		cout << "DLL_PROCESS_DETACH: i'm detached" << endl;// ��������� � ��� ��� ���������� ���������
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) float functionMin(int (*A)[3])
{
	float s =0,p=1;
	for(int i=0; i<3; i++)
		for(int j =0;j<3; j++)
		{
			p*=A[i][j];
			s+=A[i][j];
		}
     return (p/s);
}

float SimpleFunction(int (*A)[3])
{
		float s =0,p=1;
	for(int i=0; i<3; i++)
		for(int j =0;j<3; j++)
		{
			p*=A[i][j];
			s+=A[i][j];
		}
     return (p/s);
}