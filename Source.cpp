#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//���������� � ����� ������� ������ ������� �������������� ���������, ������� ��������� �����. 
//���� � ���� ��� ��� �������� �������� �������� ��������������� ���������, ������� ��������������� ���������.

void Arrayinput(int n, int* &arr, FILE* fin);

void Arrayoutput(int n, int* arr, FILE* fout);

float Average(int n, int* arr, int d);


int main()

{
	setlocale(LC_ALL, "rus");
	FILE* fin;
	FILE* fout;
    fout = fopen("fout.txt", "a");
	fin = fopen("fin.txt", "r");
	fprintf(fout, "����� ������ ���������\n");
	//----------------------------------------INIZIALIZATING IDENTIFEIR-----------------------------------------------------//
	int lengthA=0;
	int lengthB=0;
	int lengthC=0;

	//----------------------------------------CREATING MASS--------------------------------------------------------------//
	fscanf (fin,"%d\n",&lengthA);
	int* arrayA = new int[4];//creating a mas
    Arrayinput(lengthA ,arrayA,fin);


	fscanf(fin,"%d\n",&lengthB);
	int* arrayB = new int[3];//creating a mas
	Arrayinput(lengthB,arrayB,fin);

	fscanf(fin,"%d\n",&lengthC);
	int* arrayC = new int[lengthC];//creating a mas  
    Arrayinput(lengthC,arrayC,fin);
    
	fprintf(fout,"������ �\n");
	Arrayoutput(lengthA, arrayA, fout);
	fprintf(fout, "������ B\n");
    Arrayoutput(lengthB, arrayB, fout);
	fprintf(fout, "������ C\n");
	Arrayoutput(lengthC, arrayC, fout);

	int d;
	printf("������� �����:");
	scanf("%d", &d);

	fprintf(fout, "�������� �����:%d\n", d);
	

	float sumA = Average(lengthA, arrayA, d); 
	float sumB = Average(lengthB, arrayB, d);
	float sumC = Average(lengthC, arrayC, d);

	float min = sumA;
	if (min>sumB)
		min = sumB;
	else
		min = sumC;

	if ((sumA!=-1) && (sumB!=-1) && (sumC!=-1))
	{
		if ((sumA == min) && (sumB == min) && (sumC == min)) fprintf(fout, "A B C");
		else
			if ((sumA == min) && (sumB == min) && (min != -1)) fprintf(fout, "� B");
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
		fprintf(fout, "���?!?!\n");



	fclose(fin);
	fclose(fout);
	delete [] arrayA;
	delete [] arrayB;
	delete [] arrayC;

	return 0;
}

void Arrayinput(int n, int* &arr, FILE* fin)
{

	for (int i = 0; i < n; ++i)
	{
		fscanf(fin, "%d", &arr[i]);
	}

	fscanf(fin, "\n");
	return;

}

void Arrayoutput(int n, int* arr, FILE* fout)
{

	for (int i = 0; i < n; ++i)
	{
		fprintf(fout, "%d ", arr[i]);

	}

	fprintf(fout, "\n");
	return;
}

float Average(int n, int* arr, int d)
{
	float s = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > d)
		{   
			s += arr[i];
			k++;
		}
	}
	if (k == 0)
     s=-1;
    else
	{ 
		s = s / k;
	}
  return s;
}