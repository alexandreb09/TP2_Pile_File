#include "Pile.h"
#include "File.h"
#include "Erreur.h"
#include <stdio.h>
#include <stdlib.h>                                    //fonction atoi





/*----------------------------------------------*/
/*					main

	Entrées : Taille de la pile
	 		  Nombre d'élément dans la pile
			  Si ces valeurs ne sont pas renseignées : 
			  		la pille est initialisée à : taille =10
			  									 NbElement = 10;
	 Sortie : -
	 Sous fonctions : Affiche Erreur
					  genererPile
					  afficheP
					  inversion
					  libererP
					  
	 Dépendance : Pile.h
	  			  File.h
	  			  Erreur.h						*/
/*----------------------------------------------*/
  


int main (int argc, char * argv[]){
     int                 codeErreur = 0,
                         nbElem = 10,
                         taille = 10;
     pile_t            * maPile;

     if (argc < 3)													// Si le nombre d'arguments est < à 0
          AfficheErreur(0);											// 		Information sur les valeurs par défault prise pour 
																	// 		la taille et le nombre d'éléments
     else {															// Sinon :
          taille = atoi(argv[1]);									// 		Affectation des variables tailles
          nbElem = atoi(argv[2]);									// 		et nombre éléments
     }
	
/*Vérifier que nbElem < taille !!!! */	
     maPile = genererPile(taille,nbElem);							// Création de la pile suivant la fonction genererPile
     if (maPile){													// Si l'allocation s'est bien effectuée
          afficheP(maPile);											// 		Affichage de la Pile

          maPile = inversion(maPile,&codeErreur);					// 		Inversion de la pile
          if (codeErreur == 2)     AfficheErreur(codeErreur);		// 		Si l'inversion a échouée, affichage message d'erreur
          afficheP(maPile);											// 		Affichage de la pile
     }
     else AfficheErreur(1);											// Sinon : affichage message d'erreur
     libererP(maPile);												// Libération de la pile

}
