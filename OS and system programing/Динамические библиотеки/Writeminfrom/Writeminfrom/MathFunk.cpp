#include <windows.h>
#include <iostream>
using namespace std;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)//главная функция библиотеки
{
	switch (ul_reason_for_call)// обработчик событий библиотеки
	{
	case DLL_PROCESS_ATTACH://событие "Библотека подключена?"
		cout << "DLL_PROCESS_ATTACH: i'm attached!!" << endl;// сообщение о том что библиотека подключена
		break;
	case DLL_THREAD_ATTACH://не надо
		break;
	case DLL_THREAD_DETACH://не интересно(((
		break;
	case DLL_PROCESS_DETACH://событие "Библотека отключена?"
		cout << "DLL_PROCESS_DETACH: i'm detached" << endl;// сообщение о том что библиотека отключена
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