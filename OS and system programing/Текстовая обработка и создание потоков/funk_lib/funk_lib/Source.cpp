#include <stdio.h>
#include <string.h>
#include <fstream>
#include <Windows.h>
#include <time.h>
 
using namespace std;
bool isAlphabet(char* line);
void findAlpha();

extern "C" __declspec(dllexport) void funk(void* Params)
{
	clock_t start, end;
	char s_text_1[100]={"Время ушедшее на обработку равно: "};
	start=clock();
	findAlpha();
	end=clock();
	char buff[50];
	double val=(((double)end-start)/((double)CLOCKS_PER_SEC));
	sprintf(buff,"%f",val);
	strcat(s_text_1,buff);
	strcat(s_text_1," секундам");
	SetWindowTextA(*((HWND *)Params),s_text_1);
}
void findAlpha()
{
	ifstream fin;
	fin.open("text.txt");
	while(!fin.eof())
	{
		char* line =(char*) VirtualAlloc(NULL,256*sizeof(char),MEM_RESERVE, PAGE_READWRITE);
		VirtualAlloc(&line[256],sizeof(char),MEM_COMMIT, PAGE_READWRITE);
		fin.getline(line,256);
		if(isAlphabet(line)) break;
		VirtualFree(line,0,MEM_RELEASE);
	};
	fin.close();
}
bool isAlphabet(char* line)
{
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