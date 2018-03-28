/*=========================================================================*/
/*	Fichier : Pile.h										     */
/*	Role : Fichier en-tête du module pile.c                               */
/* 		                         		    					    	*/
/*														     */
/*	Contenu du fichier (fonctions):							    	*/
/*	 		initPile										    	*/
/*			estVide										     */
/*			empiler											*/
/* 			depiler										     */
/*             affiche											*/
/* 			liberer                                                     */
/*             sommet	                                                  */
/*	Contenu du fichier (structure):							    	*/
/*	 		pile_t										    	*/
/*   Alias :    float --> element                                          */
/*														     */
/*	Dépendance : aucune										    	*/
/*														     */
/*=========================================================================*/


#ifndef Gard2
#define Gard2

typedef float element;

typedef struct pile{                                   // Structure de la pile :
     int taille;                                       // Taille pile
     int indice;                                       // Adresse élément au sommet
     element * base;                                   // Adresse base de la pile
}pile_t;




pile_t * initPile(int );
int estVideP(pile_t *);
void empiler (pile_t *, element);
element depiler (pile_t *);
void afficheP(pile_t *);
void libererP (pile_t *);
element sommetP(pile_t *);
pile_t * inversion(pile_t *, int *);
pile_t * genererPile(int,int);

#endif
