/*=========================================================================*/
/*	Fichier : File.c										     */
/*	Role : Module regroupant différentes fonctions sur les files          */
/* 		                    			    					    	*/
/*														     */
/*	Contenu du fichier (fonctions):							    	*/
/*	 		initFile								    	          */
/*			estVideF									          */
/*			ajouterF											*/
/* 			supprimerF										*/
/*             sommetF                                                     */
/*             afficherF                                                   */
/*             libererF                                                    */
/*														     */
/*	Dépendance : File.h		     							     */
/*=========================================================================*/



#include "File.h"
#include <stdlib.h>
#include <stdio.h>


/* -----------------------------------------------------------------------*/
/*                            estVideF

     Role : dire si la file est vide

     Entrée :  file     : pointeur sur structure file
     Sortie : entier : 1 si la file est vide
                       0 sinon
     Variable locales : -
     Sous fonctions : -                                                   */
/* -----------------------------------------------------------------------*/
int estVideF(file_t * file){
     return (file->nbElem==0);
}


/* -----------------------------------------------------------------------*/
/*                            ajouterF

     Role : insérer un élément dans la file
     Condition NECESSAIRE : la pile ne doit pas être pleine

     Entrée :  file   : pointeur sur structure file
               val : valeur à insérer
     Sortie : pile contenant le nouvel élément
     Variable locales :
          - indice : indice où est insérer l'élément
     Sous fonctions : -                                                   */
/* -----------------------------------------------------------------------*/
void ajouterF(file_t * file, element val){
     int indice = (file->fin+1) % file->taille;
     file->fin = indice;
     file->nbElem++;
     (file->base)[indice] = val;
}


/* -----------------------------------------------------------------------*/
/*                            sommetF

     Role : retourner l'élément au sommet de F

     Entrée :  file     : pointeur sur structure file
     Sortie : élément au sommet de la file
     Variable locales : -
     Sous fonctions : -                                                   */
/* -----------------------------------------------------------------------*/
element sommetF(file_t * file){
     return (file->base)[file->deb];
}


/* -----------------------------------------------------------------------*/
/*                            afficherF

     Role : afficher la structure file

     Entrée :  file     : pointeur sur structure file
     Sortie : -
     Variable locales : i : indice de parcours de la file
     Sous fonctions : -                                                   */
/* -----------------------------------------------------------------------*/
void afficherF(file_t * file){
     int i = 0;
     printf("File :\n\t- Nombre d'éléments :%d\n\t- Nombre de cases libres : %d\n\t- File :\n",file->nbElem,file->taille-file->nbElem);
     if (file){
          for (i; i < file->nbElem; i++)
               printf("\t\t|| %0.2f ||\n", (file->base)[(file->deb+i)%file->taille]);
     }
     else printf("La file est vide\n");
}


/* -----------------------------------------------------------------------*/
/*                            initFile

     Role : initialise la structure file
            (retourne NULL si echec)

     Entrée :  taille : taille de la file (nombre max d'éléments)
     Sortie : pointeur sur structure file si allocation OK
              NULL sinon
     Variable locales : f : structure file
     Sous fonctions : -                                                   */
/* -----------------------------------------------------------------------*/
file_t * initFile(int taille){
	file_t * f = malloc(sizeof(file_t));

	if (f){                                                                    // Si l'allocation a réussi:
		f->base = malloc(taille*sizeof(element));                             // Allocation du tableau de taille éléments
		if (f->base){                                                         // Si cette allocation a réussi :
			f->taille = taille;                                              // Initialisation des champs de la file
			f->nbElem = 0;
			f-> deb = 0;
			f-> fin = -1;
		}
		else{                                                                 // Si l'allocation a échoué
			free(f);                                                         // Libération de l'espace occupé
			f = NULL;
		}
	}
	return f ;
}


/* -----------------------------------------------------------------------*/
/*                            supprimerF

     Role : retourner l'élément au sommet de F et le supprime

     Entrée :  file     : pointeur sur structure file
     Sortie : élément au sommet de la file
              suppression de cet élément dans la file
     Variable locales : -
     Sous fonctions : sommetF                                             */
/* -----------------------------------------------------------------------*/
element supprimerF(file_t * file){
	element ret = sommetF(file);
	file->deb = (file->deb + 1) % file->taille;
     file->nbElem--;
	return ret;
}


/* -----------------------------------------------------------------------*/
/*                            libérer

     Role : libérer l'espace ocupé par la structure file

     Entrée :  file     : pointeur sur structure file
     Sortie : -
     Variable locales : -
     Sous fonctions : -                                                   */
/* -----------------------------------------------------------------------*/
void libererF(file_t * file){
     if (file)
          free(file->base);
     free(file);
}
