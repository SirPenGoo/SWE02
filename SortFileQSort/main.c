/*==========================================================
|	Assignment:		SWE02_HUE2
|	File:			SortFileQSort.c
|	Author:			Maximilian Erlmoser
|	University:		FH Salzburg
|	Semester:		ITS-B SS20
|	Date:			19.03.2020
|-----------------------------------------
|	Description:	Read a file with numbers, 
|					sort them and put them on screen.
|					Use the qsort() function to sort.
*=========================================================*/


#define _CRT_SECURE_NO_DEPRECATE
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define ANZ 20

int compa(const void* a, const void* b);
int compd(const void* a, const void* b);
void help();
void output(int a[]);

int main(int argc, char * argv[]) {
	int i=0;
	FILE* datei;
	int arr[20];

	if (argc < 2) {
		help();
		return;
	}

	datei = fopen(argv[argc - 1], "r");
	if (datei == NULL)
		return 1;

	while (fscanf(datei, "%d", &arr[i]) == 1)
		i++;

	for (i = 1; i < (argc - 1); i++) {
		if (strcmp(argv[i], "-h")) {
			help();
			return;
		}

		else if (strcmp(argv[i], "-a")) {
			qsort(arr, ANZ, sizeof(int), compa);
		}
		else if (strcmp(argv[i], "-d")) {
			qsort(arr, ANZ, sizeof(int), compd);
		}
	}
	
	fclose(datei);
	output(arr);
	return;
}

void output(int a[]) {
	for (int i = 0; i < ANZ; i++) {
		printf("%d ", a[i]);
	}
}

void help() {
	printf("Program descrption: \n");
	printf("Reads file with max. 20 int-numbers and prints them sorted. \n\n");
	printf("How to open: SortFileCp [Option] File \n\n");
	printf("Option\tDescription\n");
	printf("-h\tPrints program description\n");
	printf("-a\tSorts ascending (default)\n");
	printf("-d\tSorts descending\n");
}

int compa(const void* a, const void* b)
{
	int* pa = (int*)a;
	int* pb = (int*)b;

	return (*pb - *pa);
}

int compd(const void* a, const void* b)
{
	int* pa = (int*)a;
	int* pb = (int*)b;

	return (*pa - *pb);
}