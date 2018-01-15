#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include "resource.h"

using namespace std;
HWND hEdit1;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
void funk(HWND hEdit);
void findAlpha( char line1[256]);
bool isAlphabet(char* line1);
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
			funk(hEdit1);
			break;
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

void funk(HWND hEdit)
{
	clock_t start, end;
	char s_text_1[256]={"Время ушедшее на обработку равно: "};
	start=clock();
	char line[256];
	findAlpha(line);
	end=clock();
	char buff[50];
	double val=(((double)end-start)/((double)CLOCKS_PER_SEC));
	sprintf(buff,"%f",val);
	strcat(s_text_1,buff);
	strcat(s_text_1," секундам \n");
	strcat(s_text_1,line);
	SetWindowTextA(hEdit,s_text_1);
}
void findAlpha( char line1[256])
{
	ifstream fin;
	fin.open("text.txt");
	while(!fin.eof())
	{
		char* line =new char [256];
		fin.getline(line,256);
		if(isAlphabet(line)) {fin.close(); strcpy(line1,line); return;}
		delete[] line;
	};
	
	
}
bool isAlphabet(char* line1)
{
	char line[256];
	strcpy(line,line1);
	char* preword=strtok(line, " ");
    char* word;
    bool sorted=true;
    while(preword&&sorted){
        if (word=strtok(NULL, " "))
            sorted=sorted&&strcmp(preword, word)<0;
        preword=word;
    }
	return sorted;
}