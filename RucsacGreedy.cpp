#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>

// Problema rucsacului - metoda Greedy

typedef struct {
	int cost;
	int valoare;
	float raport;
} obiect;

typedef struct {
	int nrObiecte;
	int capacitate;
	obiect obiecte[100];
} Ghiozdan;

Ghiozdan ghiozdan;

// Citire din fisier
void citireFisier() {
	FILE* f = fopen("ghiozdan.txt", "r");
	if (f == NULL) {
		printf("Eroare la deschiderea fisierului!\n");
		return;
	}
	fscanf(f, "%d %d", &ghiozdan.nrObiecte, &ghiozdan.capacitate);
	for (int i = 0; i < ghiozdan.nrObiecte; i++)
		fscanf(f, "%d", &ghiozdan.obiecte[i].cost);
	for (int i = 0; i < ghiozdan.nrObiecte; i++) {
		fscanf(f, "%d", &ghiozdan.obiecte[i].valoare);
		ghiozdan.obiecte[i].raport = (float)ghiozdan.obiecte[i].valoare / ghiozdan.obiecte[i].cost;
	}
	fclose(f);
	printf("Citire realizata cu succes!\n");
}

// Afisare obiecte
void afisare() {
	printf("Nr obiecte: %d\n", ghiozdan.nrObiecte);
	printf("Capacitate ghiozdan: %d\n", ghiozdan.capacitate);
	for (int i = 0; i < ghiozdan.nrObiecte; i++)
		printf("Obiect %d: cost = %d, valoare = %d, raport = %.2f\n", i + 1,
			ghiozdan.obiecte[i].cost, ghiozdan.obiecte[i].valoare, ghiozdan.obiecte[i].raport);
}

// Functie comuna pentru aplicarea strategiei greedy
void aplicaGreedy(const char* strategie) {
	int costTotal = 0, valoareTotala = 0;
	for (int i = 0; i < ghiozdan.nrObiecte; i++) {
		if (costTotal + ghiozdan.obiecte[i].cost <= ghiozdan.capacitate) {
			costTotal += ghiozdan.obiecte[i].cost;
			valoareTotala += ghiozdan.obiecte[i].valoare;
		}
	}
	printf("\n\tMetoda %s:", strategie);
	printf("\nCost total = %d, Valoare totala = %d\n", costTotal, valoareTotala);
}

// Metoda 1 - Obiecte in ordinea data
void greedyRandom() {
	aplicaGreedy("I - Random (in ordinea data)");
}

// Metoda 2 - Sortare crescatoare dupa cost
void sortareCost() {
	for (int i = 0; i < ghiozdan.nrObiecte - 1; i++) {
		for (int j = i + 1; j < ghiozdan.nrObiecte; j++) {
			if (ghiozdan.obiecte[i].cost > ghiozdan.obiecte[j].cost) {
				obiect aux = ghiozdan.obiecte[i];
				ghiozdan.obiecte[i] = ghiozdan.obiecte[j];
				ghiozdan.obiecte[j] = aux;
			}
		}
	}
	aplicaGreedy("II - Sortare crescatoare dupa cost");
}

// Metoda 3 - Sortare descrescatoare dupa valoare
void sortareValoare() {
	for (int i = 0; i < ghiozdan.nrObiecte - 1; i++) {
		for (int j = i + 1; j < ghiozdan.nrObiecte; j++) {
			if (ghiozdan.obiecte[i].valoare < ghiozdan.obiecte[j].valoare) {
				obiect aux = ghiozdan.obiecte[i];
				ghiozdan.obiecte[i] = ghiozdan.obiecte[j];
				ghiozdan.obiecte[j] = aux;
			}
		}
	}
	aplicaGreedy("III - Sortare descrescatoare dupa valoare");
}

// Metoda 4 - Sortare descrescatoare dupa raport valoare/cost
void sortareRaport() {
	for (int i = 0; i < ghiozdan.nrObiecte - 1; i++) {
		for (int j = i + 1; j < ghiozdan.nrObiecte; j++) {
			if (ghiozdan.obiecte[i].raport < ghiozdan.obiecte[j].raport) {
				obiect aux = ghiozdan.obiecte[i];
				ghiozdan.obiecte[i] = ghiozdan.obiecte[j];
				ghiozdan.obiecte[j] = aux;
			}
		}
	}
	aplicaGreedy("IV - Sortare descrescatoare dupa raport valoare/cost");
}

int main() {
	citireFisier();
	afisare();
	greedyRandom();
	sortareCost();
	sortareValoare();
	sortareRaport();

	printf("\nToate metodele au fost executate.\n");
	return 0;
}
