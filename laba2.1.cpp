#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int nmax = 10;
//���� ��� ������� ������� �������.
//��� ��� �� ������, � ������� ������ ������������ ��������� ���������, ��������� ������� ������������� ��������� � ������ ������.

void Matrinput(int size, int matr[][nmax], FILE* f);

void Matroutput(int size, int matr[][nmax], FILE* f);

int Multiplication(int size, int matr[][nmax]);

void Check(int size, int matr[][nmax],bool z[nmax]);

void Answer(FILE* f,bool z[nmax],int size);

int main()


{
	setlocale(LC_ALL, "rus");
	FILE* fin;
	fin = fopen("fin.txt", "r");
	FILE* fout;
	fout = fopen("fout.txt", "a");

	fprintf(fout, "����� ������ ���������\n");

	//-------------------------------------------------

	int matrA[nmax][nmax], matrB[nmax][nmax];
	int a, b, mltpA, mltpB;//matr size

	printf("������� ����������� ������� A:");
	scanf("%d", &a);
	Matrinput(a, matrA, fin);

	fprintf(fout, "������ �\n");
	Matroutput(a, matrA, fout);
    
	printf("������� ����������� ������� B:");
	scanf("%d", &b);
	Matrinput(b, matrB, fin);

	fprintf(fout, "������ B\n");
	Matroutput(b, matrB, fout);

    mltpA = Multiplication(a, matrA);
	mltpB = Multiplication(b, matrB);
 
	if (mltpA == mltpB)
	{fprintf(fout, "�����������e ������������� ��������� � �������� � � � �����\n");
        bool masA[nmax], masB[nmax];
		Check(a, matrA, masA); Answer(fout, masA, a);
		Check(b, matrB, masB); Answer(fout, masB, b);
}
	else
		if (mltpA < mltpB)
		{fprintf(fout, "�����������e ������������� ��������� � ������� � ������,��� � � \n");
	      bool masB[nmax];
          Check(b, matrB, masB); Answer(fout, masB, b);
        }
		else
		{fprintf(fout, "�����������e ������������� ��������� � ������� A ������,��� � B �����\n");
	      bool masA[nmax];
	      Check(a, matrA, masA); Answer(fout, masA, a);
		}
	printf(":))");

	fclose(fin);
	fclose(fout);
return 0;
}

//==============================================================================================================//

void Matrinput(int size, int matr[][nmax], FILE* f)
{for (int i = 0; i < size; i++)
	{for (int j = 0; j < size; j++)
			fscanf(f, "%d", &(matr[i][j]));
       fscanf(f, "\n");
}
return;
}

void Matroutput(int size, int matr[][nmax], FILE* f)
{for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fprintf(f, "%d\t", matr[i][j]);
fprintf(f, "\n");
}
return;
}

int Multiplication(int size, int matr[][nmax])
{int mltp = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matr[i][j]!=0)
				mltp *= matr[i][j];
	return mltp;
}

void Check(int size, int matr[][nmax], bool z[])
{bool fl = false;
for (int i = 0; i < size; i++) {
		int j = 0;
		while ((!fl) && (j<size)){
			if (matr[i][j]> 0) {
				fl = true;
			}
		}
		z[i] = fl;
	}
	return;
}

void Answer(FILE* f, bool z[nmax],int size)
{for (int i = 0; i < size; i++) {
		if (!z[i]) {
			fprintf(f, "� ������ � %d ��� ������������� ��������\n",i+1);
		}
		else {
			fprintf(f, "� ������ � %d ���� ������������� ��������\n", i+1);
        }
	}
return;
}