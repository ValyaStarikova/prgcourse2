#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int nmax = 10;
//Даны две матрицы разного размера.
//Для той из матриц, в которой больше произведение ненулевых элементов, проверить наличие положительных элементов в каждой строке.

void Matrinput(int size, int matr[][nmax],FILE* f);

void Matroutput(int size, int matr[][nmax],FILE* f);

int Multiplication(int size, int matr[][nmax]);

bool Check(int size,int matr[][nmax]);

void Answer(FILE* f, int matr[][nmax], int size);


int main()
{
	setlocale(LC_ALL, "rus");
	FILE* fin;
	fin = fopen("fin.txt", "r");
	FILE* fout;
	fout = fopen("fout.txt", "a");

	fprintf(fout, "Новый запуск программы\n");

	//--------------------------------------------------------------------------------//

	
	int matrA[nmax][nmax], matrB[nmax][nmax];
	int a, b, mltpA, mltpB;//matr size
	 
	//----------------------------INPUTMATR-----------------------------------------------//
	printf("Введите размерность матрицы A:");
	scanf("%d", &a);
	Matrinput(a,matrA,fin);

	fprintf(fout, "Массив А\n");
	Matroutput(a, matrA,fout);



	printf("Введите размерность матрицы B:");
	scanf("%d", &b);
	Matrinput(b,matrB,fin);

	fprintf(fout, "Массив B\n");
	Matroutput(b, matrB,fout);
	//------------------------------------------------------------------------------------//

	mltpA = Multiplication(a, matrA); cout << mltpA;
	mltpB = Multiplication(b, matrB); cout << mltpB;

	if (mltpA == mltpB)
	{
		fprintf(fout, "Произведения положительных элементов в массивах А и В равны\n");
			Answer(fout, matrA, a);
			Answer(fout, matrB, b);

	}
	else 
		if (mltpA < mltpB)
		{
			fprintf(fout, "Произведениe положительных элементов в массиве В больше,чем в А\n");
				Answer(fout,matrB, b);
		}
		else
		{
			fprintf(fout, "Произведениe положительных элементов в массиве A больше,чем в B\n");
				Answer(fout,matrA, a);
		}

	fclose(fout);
	fclose(fin);
	return 0;
}
//=============================================FUNCTIONS===================================================================//
void Matrinput(int size, int matr[][nmax],FILE* f)
{  


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fscanf(f, "%d", &(matr[i][j]));
	

		fscanf(f, "\n");
	

	}
	return;
}

void Matroutput(int size, int matr[][nmax],FILE* f)
{for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fprintf(f, "%d\t", matr[i][j]);
		
		fprintf(f, "\n");

	}
return;
}

int Multiplication(int size, int matr[][nmax])
{int mltp=1;
for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
		if (matr[i][j]>0)
			mltp *= matr[i][j];
return mltp;
}

bool Check(int x[], int size)
{
	int j = 0;
	bool fl = true;
	while ((j < size) && fl) {
		if (x[j] < 0) {
			fl = false;
		}
		else j++;
	}
	return fl;
}

void Answer(FILE* f, int matr[][nmax], int size)
{
	for (int i = 0; i < size; i++) {
		if (Check(matr[i], size)) {
			fprintf(f, "В строке № %d есть положительные элементы\n", i+1);
		}
		else {
			fprintf(f, "В строке № %d нет положительных элементы\n", i+1);
		}
	}
		return;
}