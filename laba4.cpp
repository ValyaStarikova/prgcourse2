#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <locale.h>
#include <stdio.h>
using namespace std;

void RecordingString(int i,const int& length,char*& newstr,char* str){
	if (i < length) {
		newstr[i] = str[i];
		RecordingString(i + 1, length, newstr, str);
	}else return;
}

void Input (FILE* fin, char*& str, int& length) {
	if (!(feof(fin))) {
		char c;
		fscanf(fin, "%c", &c);
		if (((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))) {
			char* newstr = new char[length + 2];
			RecordingString(0, length, newstr, str);
			delete[] str;
			newstr[length] = c;
			newstr[length + 1] = '\0';
			str = newstr;
			length = length + 1;
		}Input(fin, str, length);
	}else return;
}

void WordLength(char* str, int& length,int& k,int& size) {
	if (str[k] != ' ' && k <= length) {
		k++;
		size++;
		WordLength(str, length,k,size);
	}else return;
}

/*bool DuplicateCheck( char*& str,const char& c,const int& indexc,const int& j, const int& bord) {//j коретка по слову , board-граница проверяемого слова, e индекс символа чтобы не пересекались
	if (j <= bord) { 
		if ( (str[j] != c) || (indexc == j) ) { //если индексы пересекутся то у нас все равно продолжается проверка 
			DuplicateCheck(str, c, indexc, j+1, bord);
		}else {return true;} // когда символы совпадают возвращает true и символ не добавляются в строку
	} else return false; 
}*/

bool DuplicateCheck(char*& str, const char& c, const int& indexc, const int& j, const int& bord) {//j коретка по слову , board-граница проверяемого слова, e индекс символа чтобы не пересекались
	if ((str[j] != c) || (indexc == j)) { //если индексы пересекутся то у нас все равно продолжается проверка 
		DuplicateCheck(str, c, indexc, j + 1, bord);}// когда символы совпадают возвращает true и символ не добавляются в строку
    else { if (j <= bord) return true;
          else  return false; }
}

void Addingword(char* str, char*& str2, int& length, int& length2,const int& beginoftheword, int i, int bord) {
	if (i < bord) {
		if (!DuplicateCheck(str, str[i],i, beginoftheword, bord)) {
			str2[length2] = str[i];
			length2++;}
	    Addingword(str, str2, length, length2, beginoftheword,i+1, bord);
	}else return;
}

void RewritingString(char* str, char*& str2, int length, int& length2,int& k) {
	if (k <= length) {
		int size = 0, size2 = 0;// размер нового слова//str-основная строка//length-длина основной строки //k-коретка строки
		WordLength(str, length, k, size);//после выполнения Word,k указывает на пробел после слов
		int i = k - size;// начало слова
		Addingword(str, str2, length, length2, i, i, k);
		str2[length2] = ' ';
		length2 = length2 + 1;
		k++;
		RewritingString(str, str2, length, length2, k);
	}else return;
}

int main() {
	FILE* fin, * fout;
	if (((fin = fopen("fin.txt", "r")) == NULL) || ((fout = fopen("fout.txt", "w")) == NULL))
		printf("Ошибка чтения из файла");
	else {
		setlocale(LC_ALL, "rus");
		char* str = new char[0];
		int length = 0, length2 = 0;
		Input(fin, str, length);
		char* str2 = new char[length + 1];
		int k = 0;
		RewritingString(str, str2, length - 1, length2,k);
		str2[length2] = '\0';
		fprintf(fout, "Вот исходная строка - %s \nВот обработанная строка - %s", str, str2);
		delete[] str;
	}
	return 0;
}