#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <locale.h>
#include <stdio.h>
//#include "Dll1.h"
#pragma comment( lib, "Dll1.lib" )

#ifdef DLL1_EXPORTS
#define DLL1_API __declspec(dllexport)
#else
#define DLL1_API __declspec(dllimport)
#endif

extern "C" DLL1_API void Input(FILE* fin, char*& str, int& length);

extern "C" DLL1_API void Word(char* str, int& length, int& k, int& size);

extern "C" DLL1_API bool DuplicateCheck(char*& str, const char& c, const int& indexc, const int& j, const int& bord);

extern "C" DLL1_API	void Addingword(char* str, char*& str2, int& length, int& length2, const int& beginoftheword, int i, int bord);

extern "C" DLL1_API	void RewritingString(char* str, char*& str2, int length, int& length2, int& k);


using namespace std;


int main() {
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
	return 0;
}