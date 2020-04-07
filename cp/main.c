
/*==========================================================
|	Assignment:		SWE02_HUE02
|	File:			cp.c
|	Author:			Maximilian Erlmoser
|	University:		FH Salzburg
|	Semester:		ITS-B SS20
|	Date:			23.03.2020
|-----------------------------------------
|	Description:	Copy a file like the cp command
*=========================================================*/


#include "stdio.h"
#include "locale.h"
#include "string.h"

#pragma warning(disable:4996)

int cp(char* src, char* dsc)
{
	FILE* fsrc, * fdest;

	int size = 0;
	char* str, *buffer;

	fsrc = fopen(src, "r");
	fdest = fopen(dsc, "w");

	if (fsrc == NULL || fdest == NULL)
	{
		printf("Error - Could not open or create file!");
		return -1;
	}
	else
	{
		fseek(fsrc, 0L, SEEK_END);
		size = ftell(fsrc);
		fseek(fsrc, 0L, SEEK_SET);

		str = malloc(size + 1);
		str[0] = '\0';

		buffer = malloc(size + 1);

		fread(str, strlen(buffer) + 1, 1, fsrc);

		fputs(str, fdest);

		fclose(fsrc);
		fclose(fdest);

		return 0;
	}
}

void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "de_DE");

	if (argc < 2) {
		printf("Error - too few arguments");
		return -1;
	}

	char* src = argv[1];
	char* dst = argv[2];

	cp(src, dst);

	printf("Copied file from %s to %s", src, dst);

}