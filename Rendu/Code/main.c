/*=========================================================================*/
/*	Fichier : Code/main.c      								     */
/*	Role : Tester le bon fonctionnement des fonctions des modules Pile    */
/*          et File (exemple d'utilisation : inverser une pile             */
/* 			    					    	                              */
/*														     */
/*	Contenu du fichier (fonctions):							    	*/
/*	 		main.c										    	*/
/*	Dépendance : File.h                                                   */
/*                Pile.h		     							     */
/*                Erreur.c                                                 */
/*                                                                         */
/*	Toutes les cas limites sont gérés en dehors des fonctions des modules */
/* 	Pile et File												*/
/*=========================================================================*/













#include "Pile.h"
#include "File.h"
#include "Erreur.h"
#include <stdio.h>
#include <stdlib.h>                                    //fonction atoi





/*-----------------------------------------------------*/
/*					main
     Role : Tester le fonctionnement des fonctions du
            module Pile et File en inversant une pile

     Entrées : - Taille de la pile
 		     - Nombre d'élément dans la pile
			- Si ces valeurs ne sont pas renseignées:
			  		la pille est initialisée à :
                                       taille = 10
  							    NbElement = 10
	 Sortie : -
	 Sous fonctions : Affiche Erreur
				   genererPile
				   afficheP
				   inversion
				   libererP

	 Dépendance : Pile.h
  			    File.h
	  		    Erreur.h						*/
/*-----------------------------------------------------*/



int main (int argc, char * argv[]){
     int                 codeErreur = -1,
                         nbElem = 10,
                         taille = 10;
     pile_t            * maPile;

     if (argc < 3)													// Si le nombre d'arguments est < à 2
          AfficheErreur(0);											// Information sur les valeurs prises par défault
     else {														// Sinon :
          taille = atoi(argv[1]);									     // Affectation de la variable taille
          nbElem = atoi(argv[2]);									     // Affectation de la variable nbElem
     }

     if (nbElem > taille) AfficheErreur(1);                                     // Si nbElem > taille : affichage message d'erreur
     else {                                                                     // Sinon :
          maPile = genererPile(taille,nbElem);							// Création de la pile suivant la fonction genererPile
          if (maPile){											     // Si l'allocation s'est bien effectuée
               afficheP(maPile);										// Affichage de la Pile
               maPile = inversion(maPile,&codeErreur);					     // Inversion de la pile
               if (codeErreur == 3)     AfficheErreur(codeErreur);		     // Si l'inversion a échouée, affichage message d'erreur
               afficheP(maPile);										// Affichage de la pile
               libererP(maPile);										// Libération de la pile
          }
          else AfficheErreur(2);										// Sinon : affichage message d'erreur
     }
}
