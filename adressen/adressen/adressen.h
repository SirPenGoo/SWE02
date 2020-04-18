#ifndef ADRESSEN_H
#define ADRESSEN_H

#define LEN 20
struct adres {
	char vname[LEN];
	char nname[LEN];
	int geburtsjahr;
};
typedef struct adres TADRESS;

void help(void);
TADRESS* einlesen(char* filname, int* anzahl);
void ausgabe(TADRESS* p, int anzahl, FILE *fp);
void sort_name(TADRESS* p, int anzahl); // Sortiert Adressen nach Namen
void suche_name(TADRESS* p, int anzahl, char* name); //Sortiert alle Adressen nach Namen und durchsucht diese


#endif // !ADRESSEN_H
