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

//int LeftShift(int& x,int n);
int LeftShift(int& x, const int& n, const int& i);

void Output(const int& x, const int& p);

bool b(const int& x, const int& p);


int main() {
    int x;
	printf("Enter the number:\n");
    scanf("%d", &x);
	
    
    printf("Enter the numbers of bits you want to shift:\n");
	int n;
	scanf("%d", &n);

	if ((n < 32)&&(n>-1)) {
		printf("Original number\n");
        Output(x, 31);
		printf("\n");
		printf("Wait....\n");
		LeftShift(x,n,1);
		printf("Received number\n");
		Output(x, 31);
	}
	else {
		printf("ERROR\n");
    }

    return 0;
}
/*int LeftShift(int& x, int n) {
	unsigned mask = 0x80000000,t;
	for (int i = 1; i <= n; i++) {
		t = mask & x;
		x <<= 1;
		if (t) { x | t; }
	}
    return x;
}*/


int LeftShift(int& x, const int& n,const int& i) {
	unsigned mask = 0x80000000, t;
	if (i <= n) {
		t = mask & x;
		x <<= 1;
		if (t) { x | t; }
		LeftShift(x,n,i+1);
	}
	return x;
}

bool b(const int& x, const int& p) {
	return (x>>(p+1))&1;
}

void Output(const int& x,const int& p) {
    printf( "|%d", b(x,p));
	if (p>-1){Output( x, p - 1);}
    
}
