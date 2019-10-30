#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <fstream>
#include <iostream>

const int elementsize = 2; // один элемент типа short int весит 2 байта
const int massize = 6;  //количество элементов в записи
typedef short int mas[massize];

void TextToBin(FILE* txtfile, FILE* binfile, int& count);

void BinToText(FILE* binfile, FILE* txt, int& n);

void Swap(FILE* binfile, int n1, int n2);

int main() {
	FILE* fout, * bin;
	FILE* fin;               // open textfile
	fin = fopen("fin.txt", "r");
	fout = fopen("fout.txt", "a");
	bin = fopen("file.bin", "w+b");
	int count;
	TextToBin(fin,bin, count);

	if (count == 0) { // if count of records is zero
		printf("Empty file.");
	}
	else {
		fprintf(fout,"Original file:\n");
		BinToText(bin, fout, count);
		int pos1;
		int pos2;
		printf("What positions do you want to change?:\n");
		scanf("%i%i", &pos1, &pos2);
		//scanf("%i", &n2);
		Swap(bin, pos1, pos2);
		if (pos1 > count || pos2 > count || pos1 < 1 || pos2 < 1) fprintf(fout, "Error.");// if entered positions are wrong
		else {
			fprintf(fout, "We change postion %i %s %i %s\n", pos1, " and ", pos2, ".");
			fprintf(fout, "New file:\n");
			BinToText(bin, fout, count);
		}
	}
	fclose(bin);
	fclose(fout);
	fclose(fin);
	return 0;
}


void TextToBin(FILE* txtfile,FILE* binfile, int& count) {

	mas r;
	count = 0; //count of records
	fseek(txtfile, 0, SEEK_SET);
	char c='/';
	short int i = 0;
	int k = 0;
	while (!feof(txtfile)) {
		while (c!=';') {

        fscanf(txtfile, "%hi %c", &i, &c);

		if (c == ',') {
			r[k] = i;
			k++;
		}
			
			if (c == ';') {
				r[k] = i;
				k++;

				if (k==6){
				count++;
				fwrite(&r, elementsize, massize, binfile);}
				
				k = 0;
                fscanf(txtfile, "\n");

				if (feof(txtfile)) {
					c=';';
				}
				else
				c = '/';
				
			}
		
		}
		
		
	}
	fclose(txtfile);
	return ;
}

void BinToText(FILE* binfile, FILE* txt, int& n) {
    mas r;
	fseek(binfile, 0, SEEK_SET);
	for (int i = 0; i < n; i++) { // cicle by the number of records
		fread(&r, elementsize, massize, binfile);
		fprintf(txt, "%hi %hi %hi %hi %hi %hi\n", r[0], r[1], r[2], r[3], r[4], r[5]);
	}
	return ;
}

void Swap(FILE* binfile, int n1, int n2) {
	int p1 = n1 - 1, p2 = n2 - 1;
	mas a,b;

	fseek(binfile, 6 * p1 * elementsize, SEEK_SET);
	fread(&a, elementsize, 6, binfile);

	fseek(binfile, 6 * p2 * elementsize, SEEK_SET);
	fread(&b, elementsize, 6, binfile);

	fseek(binfile, 6 * p2 * elementsize, SEEK_SET);
	fwrite(&a, elementsize, 6, binfile);

	fseek(binfile, 6 * p1 * elementsize, SEEK_SET);
	fwrite(&b, elementsize, 6, binfile);
	return ;
}