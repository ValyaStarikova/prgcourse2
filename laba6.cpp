/*�������� �������, ��������� � �������, ��������� ������ �������� ��� ������ (������� ���������� � ������� � �.�.).
�� ���� ��������� ���������� ������ ��� ���� �����, � �� �� ������ � �����. ���� ���������� � 0 �� 31 ������� � ������� ����.
��� � ������� p ������ ��������.

�������� ��������� ��� �������� ������������ ������ �������. ��� ����, ����� ���� ������ ��������� ������������ ������ � ������, �������� � ���������� ����� ����� �������,
��������� ������ %08x � ����� ����� � ����������������� ������� ���������, 8 ������, ������� ����������� ����. ���������� ��������� ������������ �������� �������� ���������� n � p.*/
//�������� �������, ������� ���������� �������� x ����� ���������� � ��� ������������ ������ ����� �� n ���.

//x=18=10010 n=3 10100   

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

int LeftShift(int x, const int& n);

void Output(const int& x, const int& p);

bool b(const int& x, const int& p);

int main() {
    int x= 4026728449;
	/*printf("Enter the number:\n");
    scanf("%d", &x);*/
   //  printf("Enter the numbers of bits you want to shift:\n");
	int n=3;
	//scanf("%d", &n);
    if ((n < 32)&&(n>-1)) {
		printf("Original number\n");
        Output(x, 31);
		printf("\n");
		printf("Wait....\n");
		printf("Received number\n");
		Output(LeftShift(x,n), 31);}
	else {
		printf("ERROR\n");}
    return 0;
}

int LeftShift(int x, const int& n){
	unsigned mask=(mask=x)>>(32-n); 
	return (x<<n)|mask;
}

bool b(const int& x, const int& p) {
	return (x>>p)&1;
}

void Output(const int& x,const int& p) {
    printf( "|%d", b(x,p));
	if (p>0){Output( x, p - 1);}
 }
