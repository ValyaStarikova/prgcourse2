//#define _CRT_SECURE_NO_WARNINGS
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "Dll1.h"
#include<iostream>




void Input(FILE* fin, char*& str, int& length) {
	if (!(feof(fin))) {
		char c;
		fscanf_s(fin, "%c", &c);
		if (((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))) {
			char* newstr = new char[length + 2];
			for (int i = 0; i < length; i++)
				newstr[i] = str[i];
			delete[] str;
			newstr[length] = c;
			newstr[length + 1] = '\0';
			str = newstr;
			length = length + 1;
		}Input(fin, str, length);
	}
	else return;
}

void Word(char* str, int& length, int& k, int& size) {
	if (str[k] != ' ' && k <= length) {
		k++;
		size++;
		Word(str, length, k, size);
	}
	else return;
}

bool DuplicateCheck(char*& str, const char& c, const int& indexc, const int& j, const int& bord) {//j коретка по слову , board-граница проверяемого слова, e индекс символа чтобы не пересекались
	if (j <= bord) {
		if ((str[j] != c) || (indexc == j)) { //если индексы пересекутся то у нас все равно продолжается проверка 
			DuplicateCheck(str, c, indexc, j + 1, bord);
		}
		else { return true; } // когда символы совпадают возвращает true и символ не добавляются в строку
	}
	else return false;
}

void Addingword(char* str, char*& str2, int& length, int& length2, const int& beginoftheword, int i, int bord) {
	if (i < bord) {
		i++;
		if (!DuplicateCheck(str, str[i - 1], i - 1, beginoftheword, bord)) {
			str2[length2] = str[i - 1];
			length2++;
		}
		Addingword(str, str2, length, length2, beginoftheword, i, bord);
	}
	else return;
}

void RewritingString(char* str, char*& str2, int length, int& length2, int& k) {
	if (k <= length) {
		int size = 0, size2 = 0;// размер нового слова//str-основная строка//length-длина основной строки //k-коретка строки
		Word(str, length, k, size);//после выполнения Word,k указывает на пробел после слов
		int i = k - size;// начало слова
		Addingword(str, str2, length, length2, i, i, k);
		str2[length2] = ' ';
		length2 = length2 + 1;
		k++;
		RewritingString(str, str2, length, length2, k);
	}
	else return;
}