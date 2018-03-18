/*=========================================================================*/
/*	Fichier : File.h										     */
/*	Role : Fichier en-tête du module file.c                               */
/* 		 (indépendant du TP)			    					    	*/
/*														     */
/*	Contenu du fichier (fonctions):							    	*/
/*	Contenu du fichier (structure):							    	*/
/*	 		file_t										    	*/
/*   Alias :    float --> element                                          */
/*														     */
/*	Dépendance : aucune										    	*/
/*														     */
/*=========================================================================*/


#ifndef Gard
#define Gard

typedef float element;

typedef struct file{                                   // Structure de la liste chainée :
     int taille;                                       // Taille pile
     int nbElem;                                       // Nombre d'élément dans la file
     int deb;                                          // indice "premier" élément
     int fin;                                          // indice "dernier" élément
     element * base;                                   // Adresse base de la pile
}file_t;


int estVideF(file_t *);
void ajouterF(file_t *, element);
element sommetF(file_t *);
void afficherF(file_t *);
file_t * initFile(int);
element supprimerF(file_t *);
void libererF(file_t *);

#endif
