/*==========================================================
|	Assignment:		SWE02_HUE2
|	File:			SortFileQSort.c
|	Author:			Maximilian Erlmoser
|	University:		FH Salzburg
|	Semester:		ITS-B SS20
|	Date:			10.03.2020
|-----------------------------------------
|	Description:	Read a file with numbers, 
|					sort them and put them on screen.
|					Use the qsort() function to sort.
*=========================================================*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#define ANZ 5

int a[ANZ] = { 34, 4, 55, 23, 6 };

int comp(const void* a, const void* b);
int ausgabe(int a[ANZ]);

//Main

void main()
{
	setlocale(LC_ALL, "de_DE");

	printf("Unsortiert\n");
	ausgabe(a);

	qsort(a, ANZ, sizeof(int), comp);

	printf("Sortiert\n");
	ausgabe(a);
}

//Functions



int comp(const void* a, const void* b)
{
	int* pa = (int*)a;
	int* pb = (int*)b;

	return (*pb - *pa);
}


int ausgabe(int a[ANZ])
{
	for (int i = 0; i < ANZ; i++)
	{
		printf("%d:  %d\n", i, a[i]);
	}

	return 0;
}