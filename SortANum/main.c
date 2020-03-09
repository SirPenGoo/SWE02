// HUE_01.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "stdio.h"
#include "stdlib.h"

int main(int argc, char* argv[])
{
	int i, j, tmp;
	int value;
	int len = 0;
	int arr[20];

	if (argc > 20) {
		printf("Geben Sie weniger als 20 Argumente ein");
		return 1;
	}

	printf("Ihre Eingabe:\n");

	for (i = 1; i < argc; i++) {
		value = atoi(argv[i]);
		arr[i - 1] = value;
		len = len + 1;
		printf("%d ", value);
	}

	printf("\nSortierte Ausgabe:\n");

	for (i = 1; i < 20; i++)
	{
		for (j = 0; j < 20 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}