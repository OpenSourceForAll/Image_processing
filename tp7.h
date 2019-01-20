/* -*- c-basic-offset: 4 -*-
*
* ENSICAEN
* 6 Boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students.
* No portion of this document may be reproduced, copied
* or revised without written permission of the authors.
*/
/**
* @author Robin Gehan <rgehan@ecole.ensicaen.fr>
* @version     0.0.1 - 2019-01-05
* @todo nothing
* @bug nothing
*/
/**
* @file tp7.h
* Description of the program objectives.
* All necessary references.
*/

int lire_image (FILE * fichier,int* tableau);
void seuillage (int* tableau,unsigned long taille,int suppr,FILE * fichier);
void lissage (int* tableau,unsigned long taille,double k,FILE * fichier);
int gradient (int* tableau,unsigned long taille,FILE * fichier);
void gradient_significatif (int* tableau,unsigned long taille,FILE * fichier);
