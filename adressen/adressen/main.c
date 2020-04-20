/*==========================================================
|	Assignment:		SWE02_HUE03
|	File:			adressen.c
|	Author:			Maximilian Erlmoser
|	University:		FH Salzburg
|	Semester:		ITS-B SS20
|	Date:			18.04.2020
|-----------------------------------------
|	Description:	Manages addresses from file
*=========================================================*/

#define _CRT_SECURE_NO_DEPRECATE
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define LEN 20

struct adres {
	char vname[LEN];
	char nname[LEN];
	int geburtsjahr;
};
typedef struct adres TADRESS;

void help(void);
TADRESS* einlesen(char* filname, int* anzahl);
void ausgabe(TADRESS* p, int anzahl, FILE* fp);
void sort_name(TADRESS* p, int anzahl); // Sortiert Adressen nach Namen
void suche_name(TADRESS* p, int anzahl, char* name); //Sortiert alle Adressen nach Namen und durchsucht diese
int cmp(const void* a, const void* b);

int main(int argc, const char* argv[])
{
	int anzahl;
	char* str;
	char* name = "";

	if ((strcmp(argv[1], "-h")) == 0)
	{
		help();
		return 0;
	}

	if ((strcmp(argv[1], "-f")) == 0) {
		str = argv[3];
		name = argv[2];
	}else
		str = argv[2];

	if (str == NULL) {
		perror("File Error");
		return 0;
	}

	TADRESS* p = einlesen(str, &anzahl);
	
	if ((strcmp(argv[1], "-p")) == 0)
	{
		ausgabe(p, anzahl, stdout);
	}
	else if ((strcmp(argv[1], "-s")) == 0) {
		sort_name(p,anzahl);
	}
	else if ((strcmp(argv[1], "-f")) == 0) {
		suche_name(p, anzahl,name);
	}

}

void help(void) {
	printf("\nOption\tBeschreibung\n");
	printf("-h\tGibt eine kurze Beschreibung der Option aus.\n");
	printf("-p\tAlle Adressen sollen ausgegeben werden.\n");
	printf("-s\tAlle Adressen sollen sortiert nach Namen ausgegeben werden.\n");
	printf("-f 'muster'\tSortiert alle Adressen nach Namen und sucht nach Muster\n");
}

TADRESS* einlesen(char* filename, int* anzahl) {
	FILE* datei;
	char tmp[100];
	int anz;
	TADRESS* p;
	datei = fopen(filename, "r");

	if (datei == NULL) {
		perror("File Error"); 
		return NULL;
	}

	fgets(tmp, 100, datei);
	anz = atoi(tmp);

	p = malloc(anz * sizeof(TADRESS));
	if (p == NULL) {
		perror("Speicherfehler");
		return NULL;
	}

	for (int i = 0; i < anz; i++) {
		fgets(tmp, 100, datei);
		strcpy(p[i].vname, tmp);

		fgets(tmp, 100, datei);
		strcpy(p[i].nname, tmp);

		fgets(tmp, 100, datei);
		p[i].geburtsjahr = atoi(tmp);
	}

	if (datei != NULL) {
		fclose(datei);
	}

	*anzahl = anz;
	return p;
}

void ausgabe(TADRESS* p, int anzahl, FILE* fp) {
	for (int i = 0; i < anzahl; i++)
		fprintf(fp, "Vorname: %s\nNachname: %s\nGeburtsjahr: %d\n\n", p[i].vname, p[i].nname, p[i].geburtsjahr);
}

void sort_name(TADRESS* p, int anzahl) {
	qsort(p, anzahl, sizeof(TADRESS), cmp);
	ausgabe(p, anzahl, stdout);
}

void suche_name(TADRESS* p, int anzahl, char* name) {
	int tmp = 0;
	qsort(p, anzahl, sizeof(TADRESS), cmp);
	for (int i = 0; i < anzahl; i++) {
		if ((strcmp(strtok(p[i].nname,"\n"), name)) == 0)
			tmp = i;
	}
	if (tmp != 0)
		fprintf(stdout, "Vorname: %s\nNachname: %s\n\nGeburtsjahr: %d\n\n", p[tmp].vname, p[tmp].nname, p[tmp].geburtsjahr);
	else
		printf("Keine Adresse unter diesem Namen vorhanden!");
}

int cmp(const void* a, const void* b) {
	TADRESS* pa = a;
	TADRESS* pb = b;

	return (strcmp(pa->nname, pb->nname));
}