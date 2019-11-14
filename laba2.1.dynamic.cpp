#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int nmax = 10;
//Даны две матрицы разного размера.
//Для той из матриц, в которой больше произведение ненулевых элементов, проверить наличие положительных элементов в каждой строке.

void Inizialization(int size, int**& matr);

void Matrinput(int size, int**& matr, FILE* f);

void Matroutput(int size, int** matr, FILE* f);

int Multiplication(int size, int** matr);

void Check( int size,int**matr,bool*& z);

void Answer(FILE* f, bool* z, int size);

void Delete(int size, int**& matr);



int main()
{
	setlocale(LC_ALL, "rus");
	FILE* fin;
	fin = fopen("fin.txt", "r");
	FILE* fout;
	fout = fopen("fout.txt", "a");

	fprintf(fout, "Новый запуск программы\n");

	//-------------------------------------------------
	int a, b;
    printf("Введите размерность матрицы A:");
	scanf("%d", &a);
	printf("Введите размерность матрицы B:");
	scanf("%d", &b);

	int  mltpA, mltpB;

	int** matrA = new int* [a];
	Inizialization(a, matrA);
	int** matrB = new int* [b];
	Inizialization(b, matrB);

	
	Matrinput(a, matrA, fin);

	fprintf(fout, "Массив А\n");
	Matroutput(a, matrA, fout);

	
	Matrinput(b, matrB, fin);

	fprintf(fout, "Массив B\n");
	Matroutput(b, matrB, fout);

	mltpA = Multiplication(a, matrA);
	mltpB = Multiplication(b, matrB);

	if (mltpA == mltpB)
	{
		fprintf(fout, "Произведениe положительных элементов в массивах А и В равны\n");
		bool* masA = new bool[a];
		bool* masB=new bool[b];
		Check(a, matrA, masA); Answer(fout, masA, a);
		Check(b, matrB, masB); Answer(fout, masB, b);
	}
	else
		if (mltpA < mltpB)
		{
			fprintf(fout, "Произведениe положительных элементов в массиве В больше,чем в А \n");
			bool* masB = new bool[b];

			Check(b, matrB, masB); Answer(fout, masB, b);
		}
		else
		{
			fprintf(fout, "Произведениe положительных элементов в массиве A больше,чем в B равны\n");
			bool* masA = new bool[a];

			Check(a, matrA, masA); Answer(fout, masA, a);
		}

	printf(":))");
	Delete(a, matrA);
	Delete(b, matrB);

	fclose(fin);
	fclose(fout);
	return 0;
}

//==============================================================================================================//
void Inizialization(int size, int**& matr)
{
	matr = new int* [size]; // через массив указателей
	for (int i = 0; i < size; i++) {
		matr[i] = new int[size];
	}
	return;
}

void Matrinput(int size, int**& matr, FILE* f)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fscanf(f, "%d", &(matr[i][j]));
		fscanf(f, "\n");
	}
	return;
}

void Matroutput(int size, int** matr, FILE* f)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fprintf(f, "%d\t", matr[i][j]);
		fprintf(f, "\n");
	}
	return;
}

int Multiplication(int size, int** matr)
{
	int mltp = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matr[i][j] != 0)
				mltp *= matr[i][j];
	return mltp;
}


void Check(int size, int** matr, bool*& z)
{
	bool fl = false;
	for (int i = 0; i < size; i++) {
		int j = 0;
		while ((!fl) && (j < size)) {
			if (matr[i][j] > 0) {
				fl = true;
			}
		}
		z[i] = fl;
	}
	return;
}


void Answer(FILE* f, bool*z, int size)
{
	for (int i = 0; i < size; i++) {
		if (!z[i]) {
			fprintf(f, "В строке № %d нет положительных элементы\n", i + 1);
		}
		else {
			fprintf(f, "В строке № %d есть положительные элементы\n", i + 1);


		}
	}
	return;
}


void Delete(int size, int**& matr)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
	return;
}

