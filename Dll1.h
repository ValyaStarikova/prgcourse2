#pragma once
#include<iostream>

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