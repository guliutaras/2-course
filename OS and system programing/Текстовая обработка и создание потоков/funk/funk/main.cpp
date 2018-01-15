#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void funk(char* line);
int main()
{
	ifstream fin;
	fin.open("text.txt");
	while(!fin.eof())
	{
		char* line =new char [256];
		fin.getline(line,256);
		funk(line);
		delete[] line;
	};
	fin.close();
	system("pause");
	return 0;
}
void funk(char* line)
{
    char* preword=strtok(line, " ");
    char* word;
    bool sorted=true;
    while(preword&&sorted){
        if (word=strtok(NULL, " "))
            sorted=sorted&&strcmp(preword, word)<0;
        preword=word;
    }
    cout<<((sorted)?"alphabetical order":"NO alphabetical order")<<endl;

}