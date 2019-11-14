#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int nmax = 10;
//���� ��� ������� ������� �������.
//��� ��� �� ������, � ������� ������ ������������ ��������� ���������, ��������� ������� ������������� ��������� � ������ ������.
void Inizialization(int size, int**& matr);

void Matrinput(int size, int**& matr, FILE* f);

void Matroutput(int size, int** matr, FILE* f);

int Multiplication(int size, int** matr);

bool Check(int* x, int size);

void Answer(FILE* f, int** matr, int size);

void Delete(int size, int**& matr);


int main()
{
	setlocale(LC_ALL, "rus");
	FILE* fin;
	fin = fopen("fin.txt", "r");
	FILE* fout;
	fout = fopen("fout.txt", "a");

	fprintf(fout, "����� ������ ���������\n");

	//--------------------------------------------------------------------------------//
	int a, b;//matr size
	printf("������� ����������� ������� A:");
	scanf("%d", &a);
	printf("������� ����������� ������� B:");
	scanf("%d", &b);

	int** matrA = new int* [a];
	Inizialization(a, matrA);
    int** matrB = new int* [b];
	Inizialization(b, matrB);

	int  mltpA, mltpB;//matr multiplication 

	//----------------------------INPUTMATR-----------------------------------------------//
	
	Matrinput(a, matrA, fin);

	fprintf(fout, "������ �\n");
	Matroutput(a, matrA, fout);

	
	Matrinput(b, matrB, fin);

	fprintf(fout, "������ B\n");
	Matroutput(b, matrB, fout);
	//------------------------------------------------------------------------------------//

	mltpA = Multiplication(a, matrA);
	mltpB = Multiplication(b, matrB);


	if (mltpA == mltpB){
		fprintf(fout, "������������ ������������� ��������� � �������� � � � �����\n");
		Answer(fout, matrA, a);
		Answer(fout, matrB, b);
    }
	else
		if (mltpA < mltpB){
			fprintf(fout, "�����������e ������������� ��������� � ������� � ������,��� � �\n");
			Answer(fout, matrB, b);
		}
		else{
			fprintf(fout, "�����������e ������������� ��������� � ������� A ������,��� � B\n");
			Answer(fout, matrA, a);
		}

	cout << ":))";

	Delete(a,matrA);
	Delete(b, matrB);

	fclose(fout);
	fclose(fin);
	return 0;
}
//=============================================FUNCTIONS===================================================================//
void Inizialization(int size,int**& matr)
{matr = new int* [size]; // ����� ������ ����������
	for (int i = 0; i < size; i++) {
		matr[i] = new int[size];
	}
	return;
}
void Matrinput(int size, int**& matr, FILE* f)
{	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			fscanf(f, "%d", &(matr[i][j]));
		fscanf(f, "\n");
	}
return;
}

void Matroutput(int size, int** matr, FILE* f)
{
	for (int i = 0; i < size; i++) {
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
			if (matr[i][j])
				mltp *= matr[i][j];
	return mltp;
}

bool Check(int* x, int size)
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


void Answer(FILE* f, int** matr, int size)
{
	for (int i = 0; i < size; i++) {
		if (Check(matr[i], size)) {
			fprintf(f, "� ������ � %d ���� ������������� ��������\n", i + 1);
		}
		else {
			fprintf(f, "� ������ � %d ��� ������������� ��������\n", i + 1);
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
}