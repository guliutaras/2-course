#include <Windows.h>
#include <stdio.h>
#include <cstdlib>
#include <process.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include "resource.h"

using namespace std;
HWND hEdit1;

int A[10][10];
int contlsum=0;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
void generaterandmas(void*);
void sedldot(void*);
int controlsum();
int findmax(int &s,int row);
int findmin(int colom);
void AddText (const char* text)
{
	SendMessageA(hEdit1,EM_SETSEL,-1,-1);
	SendMessageA(hEdit1,EM_REPLACESEL,FALSE,reinterpret_cast<LPARAM>(text));
}

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0,(DlgProc),0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_INITDIALOG:
		hEdit1=GetDlgItem(hwnd,IDC_EDIT1);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1: _beginthread(generaterandmas,0,0);break;
		case IDC_BUTTON2: _beginthread(sedldot,0,0); 
			break;
		case IDC_BUTTON3: MessageBoxA(hwnd, "Данная програма по запросу находит первую седловую точку в матрице 10х10", "ПРО ПРОГРАММУ", MB_OK);
			break;
		case IDC_BUTTON4:
			EndDialog(hwnd,0);
			return FALSE;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd,0);
		return FALSE;
	}
	return FALSE;
}

void generaterandmas(void*)
{
	AddText("Запущен первый поток \r\n");
	while(1)
	{
		srand(time(NULL));
		for(int i=0; i<10;i++)
			for(int j=0;j<10;j++)
			{
				srand(time(0));
				Sleep(rand()%200);
				srand(time(0));
				A[i][j]=rand()%100-50;
			}
		contlsum=controlsum();
	}
}
int controlsum()
{ 
	int cs=0;
	for(int i=0; i<10;i++)
		for(int j=0;j<10;j++)
			cs+=A[i][j];
	return cs;
}
void sedldot(void*)
{
	int s;
	for(int i=0; i<10; i++)
	{
		int max=findmax(s,i);
		int min=findmin(s);
		if(max=min)
		{
			char text[256]={"Седловая точка найдена с кординатами "};
			char buff[4];

			sprintf(buff,"%i %i",i,s);
			strcat(text,buff);
			if(controlsum()!=contlsum)
			{
				char buff1[100]={". Данные не точны (контрольные суммы не равны) \r\n"};
				strcat(text,buff1);
				AddText(text);
				return;
			}
			else
			{
				char buff1[100]={". Данные точны (контрольные суммы совпадают) \r\n"};
				strcat(text,buff1);
				AddText(text);
				return;
			}
		}

	}
	char text[256]={"Седловая точка не найдена"};
	if(controlsum()!=contlsum)
	{
		char buff1[100]={". Данные не точны (контрольные суммы не равны) \r\n"};
		strcat(text,buff1);
		AddText(text);
		return;
	}
	else
	{
		char buff1[100]={". Данные точны (контрольные суммы совпадают) \r\n"};
		strcat(text,buff1);
		AddText(text);
		return;
	}
}

int findmax(int &s,int row)
{
	int max=-1;
	for(int i=0; i<10; i++)
		{if(A[i][row]>A[i][max])
		max=i;}
	s=max;
	return A[max][row];
}

int findmin(int colom)
{
	int min=200;
	for(int i=0; i<10; i++) 
	{if(A[colom][i]<A[i][min]) min=i;}
	return A[colom][min];
}