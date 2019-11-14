#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include<iostream>
using namespace std;

typedef void (*LibraryFunctionInput)(FILE* fin, char*& str, int& length);
typedef void (*LibraryFunctionRewritingString)(char* str, char*& str2, int length, int& length2, int& k);

int main() {

	HINSTANCE hLib;						// Объявляем идентификатор библиотеки
    LibraryFunctionInput Input;         // Inizializate library`s functions
	LibraryFunctionRewritingString RewritingString;

	hLib = LoadLibrary(TEXT("Dll1.dll"));			// Загружаем библиотеку
	if (hLib == NULL) 						// Проверяем результат загрузки библиотеки
	{
		printf("Unable to load the library 'Dll1.dll'!\n");
		return 0;
	}

	// Получаем указатель на функцию ExampleFunction и преобразуем его к нужному типу
	Input = (LibraryFunctionInput)GetProcAddress(hLib, "Input");
	RewritingString = (LibraryFunctionRewritingString)GetProcAddress(hLib, "RewritingString");
	if (!Input && !RewritingString)							// Проверяем полученный указатель
		printf("Unable to find the function 'Input' and 'RewritingString'!\n\n");
	else
	{
	FILE* fin, * fout;
	if (((fin = fopen("fin.txt", "r")) == NULL) || ((fout = fopen("fout.txt", "w")) == NULL))
		printf("ERROR");
	else {
		setlocale(LC_ALL, "rus");
		char* str = new char[0];
		int length = 0, length2 = 0;
		Input(fin, str, length);
		char* str2 = new char[length + 1];
		int k = 0;
		RewritingString(str, str2, length - 1, length2, k);
		str2[length2] = '\0';
		fprintf(fout, "Вот исходная строка - %s \nВот обработанная строка - %s", str, str2);
		delete[] str;
	      }	
	}

	FreeLibrary(hLib);
    return 0;
}