#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

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
		size = ftell(fsrc);

		str = malloc(size + 1);
		str[0] = '\0';

		buffer = malloc(size + 1);

		while (fgets(buffer, size, fsrc) != NULL)
		{
			strcat(str, buffer);
		}

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