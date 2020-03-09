#define _CRT_SECURE_NO_DEPRECATE
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int main(int argc, char* argv[]){
	FILE* datei;
	int i = 0;
	int arr[20];
	bool asc = true;
	bool desc = false;


	datei = fopen(argv[argc - 1], "r");
	if (datei == NULL)
		return 1;

	while (fscanf(datei, "%d", &arr[i]) == 1)
		i++;

	for (i = 1; i < argc - 1; i++)
	{
		if (strcmp(argv[i], "-h") == 0) {
			printf("-a: sorts ascending\n");
			printf("-d: sorts descending\n");
			return 0;
		}

		if (strcmp(argv[i], "-a") == 0) {
			asc = true;
			desc = false;
		}

		if (strcmp(argv[i], "-d") == 0) {
			desc = true;
			asc = false;
		}

		if (asc == true) {
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (arr[j] > arr[i])
					{
						int tmp = arr[i];
						arr[i] = arr[j];
						arr[j] = tmp;
					}
				}
			}
		}
		else if(desc == true){
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (arr[j] < arr[i])
					{
						int tmp = arr[i];
						arr[i] = arr[j];
						arr[j] = tmp;
					}
				}
			}
		}

		for (i = 0; i < 20; i++)
		{
			printf("%d\n", arr[i]);
		}
	}

	fclose(datei);
}