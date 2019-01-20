#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "tp7.h"

int main (int argc, char *argv[])
{
	FILE* fichier = NULL;
	unsigned long taille;
	int* tableau=NULL;
	tableau=malloc(512*512*3*(sizeof(*tableau)));
	fichier = fopen(argv[2], "r");
	
	taille=lire_image (fichier,tableau);
	printf("\n");
	
	FILE * sortie;

	sortie = fopen(argv[3] , "wb");
	seuillage(tableau,taille,atoi(argv[1]),sortie);


}
