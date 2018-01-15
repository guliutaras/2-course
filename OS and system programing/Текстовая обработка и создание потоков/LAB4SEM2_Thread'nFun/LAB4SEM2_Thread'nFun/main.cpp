#include <Windows.h>
#include "resource.h"
#include <process.h>

HWND hEdit1;
extern "C" __declspec(dllimport) void funk(void* Params);
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

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
		case IDC_BUTTON1:
			{
			unsigned id=0;
			HWND *param=&hEdit1;
			_beginthread(funk,0,(void *)param); 
			break;
			}
		case IDC_BUTTON2:
			MessageBoxA(hwnd, "Данная програма находит в файле text.txt первую строку в которой все слова расположены в алфавитном порядке", "ПРО ПРОГРАММУ", MB_OK);
			break;
		case IDC_BUTTON3:
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

