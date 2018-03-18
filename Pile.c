/*=========================================================================*/
/*	Fichier : Pile.c										     */
/*	Role : Module regroupant différentes fonctions sur les piles          */
/* 		 (indépendant du TP)			    					    	*/
/*														     */
/*	Contenu du fichier (fonctions):							    	*/
/*	 		initPile										    	*/
/*			estVide										     */
/*			empiler											*/
/* 			depiler										     */
/*             sommet                                                      */
/*             affiche                                                     */
/*             liberer                                                     */
/*														     */
/*	Dépendance : File.h                                                   */
/*                Pile.h		     							     */
/*=========================================================================*/



#include "Pile.h"
#include "File.h"
#include <stdlib.h>
#include <stdio.h>



/* -----------------------------------------------------------------------*/
/*                            initPile

     Role : Ajouter une valeur au sommet de la pile
     Condition nécesaire : l'espace ne doit pas être plein

     Entrée :  taille    : taille de la pile (nombre d'élément maxœ)

     Sortie : pointeur sur struture pile (confère fichier en-tête)
                    indice du premier élément = -1
              NULL si allocation échouée
     Variable locales : -
     Sous fonctions : -                                                   */
/* -----------------------------------------------------------------------*/
pile_t * initPile(int taille){
     pile_t                   * maPile = malloc(sizeof(pile_t));
     if (maPile){                                                     // Si 1ere alloc ok
          maPile->base = malloc(taille*sizeof(element));              // allocation tableaux contigue
          if (maPile->base == NULL){                                  // Si allocation échouée
               free(maPile);                                          // Libération mémoire
               maPile = NULL;
          }
          else{                                                       // Sinon
               maPile->indice = -1;                                   // Initialisation indice
               maPile->taille = taille;                               // Initialisation taille
          }
     }
     return maPile;
}


/* -----------------------------------------------------------------------*/
/*                            estVide

     Role : retourner 1 si la pile est vide, 0 sinon

     Entrée :  pile      : pointeur sur strcture pile

     Sortie : un entier :
                    - 1 si la pile est vide
                    - 0 sinon
     Variable locales : vide (entier) : état de la pile
     Sous foctions : -                                                    */
/* -----------------------------------------------------------------------*/
int estVideP(pile_t * pile){
     int                      vide = 1;
     if (pile->indice > -1)
          vide = 0;
     return vide;
}


/* -----------------------------------------------------------------------*/
/*                            empiler

     Role : Ajouter une valeur au sommet de la pile
     Condition nécessaire : il doit y avoir de l'espace libre dans la pile

     Entrée :  pile      : pointeur sur structure pile
               valeur   	: valeur à ajouter à la pile
     Sortie : pile l'élement ajouté au sommet de la pile

     Variable locales : -
     Sous fonctions : -                                                   */
/* -----------------------------------------------------------------------*/
void empiler (pile_t * pile, element valeur){
     pile->indice += 1;
     (pile->base)[pile->indice] = valeur;

     /* int codeErreur = 1;                                         // Code erreur
     if (pile->indice < pile->taille){
          pile->indice += 1;
          (pile->base)[pile->indice] = valeur;
          codeErreur = 0 ;                                       // Aucun problème
     }
     return codeErreur;
     */
}


/* -----------------------------------------------------------------------*/
/*                            depiler

     Role : retourner l'élément au sommet de la pile et le supprimer
     Condition nécessaire : la pile doit être NON VIDE

     Entrée :  pile      : pointeur sur structure pile
     Sortie : element au sommet de la pile

     Variable locales : valSommet (type element) : valeur au sommet de
                        la pile
     Sous foctions : -                                                    */
/* -----------------------------------------------------------------------*/
element depiler (pile_t * pile){                                 // Test effectué en amont
     element                       valSommet = (pile->base)[pile->indice];
     pile->indice -= 1;
     return valSommet;
}


/* -----------------------------------------------------------------------*/
/*                            sommet

     Role : retourne l'élement au sommet de la pile
     Condition nécessaire : la pile doit être NON VIDE

     Entrée :  pile : pointeur sur structure pile
     Sortie : valeur au sommet de la pile (type element)

     Variable locales : -                                                 */
/* -----------------------------------------------------------------------*/
element sommetP(pile_t * pile){
     return (pile->base)[pile->indice];
}


/* -----------------------------------------------------------------------*/
/*                            affiche

     Role : afficher la pile - espace disponible/occupé

     Entrée :  pile : pointeur sur structure pile
     Sortie : -

     Variable locales : i : indice de parcours de la liste de la pile
                            (liste contigue)
     Sous fonction : -                                                    */
/* -----------------------------------------------------------------------*/
void afficheP(pile_t * pile){
     int                           i;
     printf("PILE :\n\t- Nombre d'éléments : %d\n\t- Nombre cases libres : %d\n\t- Pile :\n",pile->indice+1,pile->taille-pile->indice-1);
     for (i = pile->indice; i>=0; --i)
          printf("\t\t|| %0.2f ||\n\t\t---------\n",(pile->base)[i]);
}


/* -----------------------------------------------------------------------*/
/*                            liberer

     Role : libérer l'espace occupé par la structure pile

     Entrée :  pile     : pointeur sur structure pile
     Sortie : -
     Variable locales : -
     Sous fonctions : -                                                   */
/* -----------------------------------------------------------------------*/
void libererP(pile_t * pile){
     free(pile->base);
     free(pile);
}


/* -----------------------------------------------------------------------*/
/*                            inversion

     Role : inverser les éléments d'une pile

     Entrée :  pile     : pointeur sur structure pile
               codeErreur : 1 si erreur
     Sortie : pile inversée (même pile)
     Variable locales :
          - file : structure file dans laquelle on va empiler tous les
                   élements de la pile
     Sous fonctions : - initFile
                      - estVideP
                      - ajouterF
                      - estVideF
                      - empiler                                           */
/* -----------------------------------------------------------------------*/
pile_t * inversion(pile_t * pile, int * codeErreur){
     file_t * file = initFile(pile->taille);
     if (file){
          while(!estVideP(pile)){
               ajouterF(file, depiler(pile));
          }
          afficherF(file);
          while(!estVideF(file)){
               empiler(pile,supprimerF(file));
          }
     }
     else{
          *codeErreur = 1;
     }
     libererF(file);
     return pile;
}


/* -----------------------------------------------------------------------*/
/*                            genererPile

     Role : remplir une pile de i éléments allant de 0 à taille-1

     Entrée : - taille     : taille de la pile (nombre d'élements max)
     Sortie : - pile contenant taille nombre allant de 0 à taille-1 (si
                allocation réussie)
              - NULL sinon

     Variable locales : i : indice courant allant de 0 à taille-1

     Sous fonction : empiler
                     initPile                                             */
/* -----------------------------------------------------------------------*/
pile_t * genererPile(int taille, int nbElem){
     int              i;
     pile_t         * maPile = initPile(taille);            // Initialisation de la pile
     if (maPile){                                           // si l'allocation a réussi
          for (i = 0; i< nbElem; i++)                       // pour tout i de 0 à taille - 1
               empiler(maPile,i);                           // on l'ajoute dans la pile
     }
     return maPile;
}
