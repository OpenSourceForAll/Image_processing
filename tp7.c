#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "tp7.h"

int lire_image (FILE * fichier,int* tableau)
{
	
	int lignes,colonnes;
	unsigned long cptTab;
	unsigned char line[12000];
	int R,G,B,i,maximum;

	if (fichier != NULL)
	    {
		fgets(line, 12000, fichier);
		do
		{                                      
		    fgets(line, 12000, fichier);
		}
		while (line[0]=='#');
		sscanf(line, "%d %d", &lignes, &colonnes);
		
		fscanf(fichier, "%d", &maximum);
		fgets(line, 12000, fichier);
		for (i = 0; i < lignes * colonnes; i++)
		{
		    fscanf(fichier, "%d", &R);
		    fscanf(fichier, "%d", &G);
		    fscanf(fichier, "%d", &B);
		    tableau[cptTab++]=R;
		    tableau[cptTab++]=G;
		    tableau[cptTab++]=B; 
		}
		}
	return lignes*colonnes*3;
}

void seuillage (int* tableau,unsigned long taille,int suppr,FILE * fichier)
{

	
	for(unsigned long cpt=0;cpt<taille;cpt++)
	{
		
		if(tableau[cpt]>suppr) 
		tableau[cpt]=0;


	}
	
	
	
	char text [10];
	text[0]='P';
	text[1]='6';
	fwrite( &text , sizeof(char) , 2 , fichier);
	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);
	
	text[0]='5';
	text[1]='1';
	text[2]='2';
	text[3]=' ';
	text[4]='5';
	text[5]='1';
	text[6]='2';
	
	fwrite( &text , sizeof(char) , 7 , fichier);

	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);

	text[0]='2';
	text[1]='5';
	text[2]='5';
	fwrite( &text , sizeof(char) , 3 , fichier);
	
	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);

	char temp;
	for(long cpt=0;cpt< taille;cpt++)
	{
		temp=tableau[cpt];
		fwrite( &temp , sizeof(char) , 1 , fichier);
		if(cpt%taille==0)
			fwrite( &text , sizeof(char) , 2 , fichier);
	}
	
	

}

void lissage (int* tableau,unsigned long taille,double k,FILE * fichier)
{

	
	for(unsigned long cpt=0;cpt<taille;cpt++)
	{
		
		
		tableau[cpt]=tableau[cpt]*k;


	}
	
	
	
	char text [10];
	text[0]='P';
	text[1]='6';
	fwrite( &text , sizeof(char) , 2 , fichier);
	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);
	
	text[0]='5';
	text[1]='1';
	text[2]='2';
	text[3]=' ';
	text[4]='5';
	text[5]='1';
	text[6]='2';
	
	fwrite( &text , sizeof(char) , 7 , fichier);

	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);

	text[0]='2';
	text[1]='5';
	text[2]='5';
	fwrite( &text , sizeof(char) , 3 , fichier);
	
	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);

	char temp;
	for(long cpt=0;cpt< taille;cpt++)
	{
		temp=tableau[cpt];
		fwrite( &temp , sizeof(char) , 1 , fichier);
		if(cpt%taille==0)
			fwrite( &text , sizeof(char) , 2 , fichier);
	}
	
	

}

int gradient (int* tableau,unsigned long taille,FILE * fichier)
{

	int prec;
	int max;
	for(unsigned long cpt=2;cpt<taille-2;cpt+=3)
	{
		prec=tableau[cpt];
		
		tableau[cpt]=(tableau[cpt+3]-prec)/2;
		if(tableau[cpt]>max)max=tableau[cpt];

	}
	
	printf("max %d",max);
	
	char text [10];
	text[0]='P';
	text[1]='6';
	fwrite( &text , sizeof(char) , 2 , fichier);
	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);
	
	text[0]='5';
	text[1]='1';
	text[2]='2';
	text[3]=' ';
	text[4]='5';
	text[5]='1';
	text[6]='2';
	
	fwrite( &text , sizeof(char) , 7 , fichier);

	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);

	text[0]='2';
	text[1]='5';
	text[2]='5';
	fwrite( &text , sizeof(char) , 3 , fichier);
	
	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);

	char temp;
	for(long cpt=0;cpt< taille;cpt++)
	{
		temp=tableau[cpt];
		fwrite( &temp , sizeof(char) , 1 , fichier);
		if(cpt%taille==0)
			fwrite( &text , sizeof(char) , 2 , fichier);
	}
	
	
	return max;
}

void gradient_significatif (int* tableau,unsigned long taille,FILE * fichier)
{
	
	int prec=0;
	int max=0;
	int tempo=0;
	for(unsigned long cpt=2;cpt<taille-2;cpt+=3)
	{
		prec=tableau[cpt];
		
		tempo=(tableau[cpt+3]-prec)/2;
		if(tempo>max)max=tableau[cpt];

	}
	printf("%d",max);
	for(unsigned long cpt=0;cpt<taille;cpt++)
	{
		
		if(tableau[cpt]>max) 
		tableau[cpt]=0;


	}
	
	
	
	
	char text [10];
	text[0]='P';
	text[1]='6';
	fwrite( &text , sizeof(char) , 2 , fichier);
	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);
	
	text[0]='5';
	text[1]='1';
	text[2]='2';
	text[3]=' ';
	text[4]='5';
	text[5]='1';
	text[6]='2';
	
	fwrite( &text , sizeof(char) , 7 , fichier);

	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);

	text[0]='2';
	text[1]='5';
	text[2]='5';
	fwrite( &text , sizeof(char) , 3 , fichier);
	
	text[0]='\r';
	text[1]='\n';
	fwrite( &text , sizeof(char) , 2 , fichier);

	char temp;
	for(long cpt=0;cpt< taille;cpt++)
	{
		temp=tableau[cpt];
		fwrite( &temp , sizeof(char) , 1 , fichier);
		if(cpt%taille==0)
			fwrite( &text , sizeof(char) , 2 , fichier);
	}
	
	

}


