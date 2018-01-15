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

	HINSTANCE hLib;// специальный указатель на библиотеку
	LibraryFunction  functionMin;// специальный указатель на функцию из библиотеки

	hLib = LoadLibrary(TEXT("Writeminfrom.dll"));// загружаем библиотеку
	if (hLib == NULL)// загрузилась?
	{
		printf("Не удалось подключить библиотеку 'Writeminfrom.dll'!\n");//нет, не загрузилась, жалка (((((
		return 1;
	}

	functionMin = (LibraryFunction)GetProcAddress(hLib, "functionMin");// загружаем функцию из библиотеки
	if (!functionMin)// загрузилась??
	{
		cout << "Не удалось найти функцию 'functionMin'!" << endl;// нет, (((((((((0((((
		system("pause");
		return 1;
	}
	else
		cout << "Функция 'functionMin' успешно найдена. Начинается явное использование функции." << endl << endl;// да )))))))0)))0)))
	cout << "Массив:" << endl;
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
	FreeLibrary(hLib);// отключаем библиотеку 
	system("pause");
	return 0;
}