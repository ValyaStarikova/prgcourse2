#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//Определить в каком массиве меньше среднее арифметическое элементов, больших заданного числа. 
//Если в двух или трёх массивах значения среднего арифметического совпадают, вывести соответствующее сообщение.

void Arrayinput(int n, int*& arr, FILE* fin);

void Arrayoutput(int n, int* arr, FILE* fout);

float Average(int n, int* arr, bool (*pf)(int));

bool f(int x);

const int d = 3;

int main()

{   setlocale(LC_ALL, "rus");
	FILE* fin;
	FILE* fout;
	fout = fopen("fout.txt", "a");
	fin = fopen("fin.txt", "r");
	fprintf(fout, "Новый запуск программы\n");
	//----------------------------------------INIZIALIZATING IDENTIFEIR-----------------------------------------------------//
	int lengthA ;
	int lengthB ;
	int lengthC ;

	//----------------------------------------CREATING MASS--------------------------------------------------------------//
	fscanf(fin, "%d\n", &lengthA);
	int* arrayA = new int[lengthA];//creating a mas
	Arrayinput(lengthA, arrayA, fin);


	fscanf(fin, "%d\n", &lengthB);
	int* arrayB = new int[lengthB];//creating a mas
	Arrayinput(lengthB, arrayB, fin);

	fscanf(fin, "%d\n", &lengthC);
	int* arrayC = new int[lengthC];//creating a mas  
	Arrayinput(lengthC, arrayC, fin);

	fprintf(fout, "Массив А\n");
	Arrayoutput(lengthA, arrayA, fout);
	fprintf(fout, "Массив B\n");
	Arrayoutput(lengthB, arrayB, fout);
	fprintf(fout, "Массив C\n");
	Arrayoutput(lengthC, arrayC, fout);


	fprintf(fout, "Заданное число:%d\n", d);

    float sumA = Average(lengthA, arrayA, &f);
	float sumB = Average(lengthB, arrayB, &f);
	float sumC = Average(lengthC, arrayC, &f);

	float min = sumA;
	if (min > sumB)
		min = sumB;
	else
		min = sumC;

	if ((sumA != -1) && (sumB != -1) && (sumC != -1))
	{
		if ((sumA == min) && (sumB == min) && (sumC == min)) fprintf(fout, "A B C");
		else
			if ((sumA == min) && (sumB == min) && (min != -1)) fprintf(fout, "А B");
			else
				if ((sumA == min) && (sumC == min) && (min != -1)) fprintf(fout, "  A C");
				else
					if ((sumB == min) && (sumC == min) && (min != -1)) fprintf(fout, " B  C");
					else
						if ((sumA == min) && (min != -1)) fprintf(fout, "  A");
						else
							if ((sumB == min) && (min != -1))  fprintf(fout, " B");
							else
								if ((sumC == min) && (min != -1)) fprintf(fout, " C");
	}
	else
		fprintf(fout, "Упс?!?!\n");
    
	fclose(fin);
	fclose(fout);
	delete[] arrayA;
	delete[] arrayB;
	delete[] arrayC;

	return 0;
}

void Arrayinput(int n, int*& arr, FILE* fin)
{for (int i = 0; i < n; ++i){
	fscanf(fin, "%d", &arr[i]);
	}
fscanf(fin, "\n");
	return;
}

void Arrayoutput(int n, int* arr, FILE* fout)
{for (int i = 0; i < n; ++i){
	fprintf(fout, "%d ", arr[i]);}
fprintf(fout, "\n");
	return;
}

bool f(int x) {
	bool fl;
	if (x > d) { fl=true; }
	else { fl = false; }
	return fl;
}

float Average(int n, int* arr, bool (*pf)(int))
{   float s = 0;
	int k = 0;
	for (int i = 0; i < n; i++){
		if (pf)
		{s += arr[i];
			k++;}
	}
	if (k == 0) {
		s = -1;}
	else{
		s = s / k;}
	return s;
}