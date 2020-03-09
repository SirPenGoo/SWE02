#define _CRT_SECURE_NO_DEPRECATE
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

int main(int argc, char* argv[]) {
	FILE* datei;
	int i;
	int n = 100;
	int r = 100;

	for (i = 0; i < argc-1; i++)
	{
		if (strcmp(argv[i], "-h") == 0) {
			printf("-n: Anzahl der Zahlen (default = 100)\n");
			printf("-r Zahlenbereich (default = 100)\n");
			return 0;
		}

		if (strcmp(argv[i], "-n") == 0) {
			n = atoi(argv[i + 1]);
		}

		if (strcmp(argv[i], "-r") == 0) {
			r = atoi(argv[i + 1]);
		}
	}

	datei = fopen(argv[argc - 1], "w");
	if (datei == NULL)
		return 1;

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		fprintf(datei, "%d\n", rand() % 100);
	}

	fclose(datei);

	return EXIT_SUCCESS;
}