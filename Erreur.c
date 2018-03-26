/*========================================================================*/
/*	Fichier : erreur.c										    */
/*	Role : Gérer les erreurs et en informer l'utilisateur			    */
/*	Contenu du fichier (fonctions):							    */
/*	 		AfficheErreur									    */
/*														    */
/*	Dépendance : aucune		     							    */
/*========================================================================*/



#include <stdio.h>
#include <stdlib.h>
#include "Erreur.h"



/* -----------------------------------------------------------------------*/
/*                            AfficheErreur

     Role : Afficher une message d'erreur lorsqu'une erreur se produit

     Entrée :  codeErreur : code de l'erreur

     Sortie : -
     Variable locales : -				                             */
/* -----------------------------------------------------------------------*/
void AfficheErreur( int codeErreur ){
	switch (codeErreur) {
	case 0 :
		printf("\n\t- Nombre d'arguments incorrect (2 demandés : taille pile - nombre éléments)\n\t- Valeur par défault : Taille = nombre d\'éléments = 10\n\n");
		break;
	case 1 :
		printf("\t- Erreur allocation pile\n\t- Nombre d'élements > taille\n");
		break;
	case 2 :
		printf("\t- L'inversion a échoué (erreur d'allocation file)");
		break;
	default:
		printf("\t - Une erreur s'est produite\n");
		break;
	}
}
