#include "Pile.h"
#include "File.h"
#include "Erreur.h"
#include <stdio.h>
#include <stdlib.h>                                    //fonction atoi





/*-----------------------------------------------------*/
/*					main

     Role : Tester le fonctionnement des différentes fonctions
            du module PILE et FILE (regroupe les differents cas)

     Entrées : - Taille de la pile-file (selon cas)
 		     - Nombre d'éléments dans la pile-file
			- Si ces valeurs ne sont pas renseignées:
			  		la pile-file est initialisée à :
                                       taille = 10
  							    NbElement = 10

	 Dépendance : Pile.h
  			    File.h
	  		    Erreur.h						*/
/*-----------------------------------------------------*/



int main (int argc, char * argv[]){
     int                 codeErreur = -1,
                         nbElem = 10,
                         taille = 10,
                         k;                            // indice général de parcours
     pile_t            * maPile;
     file_t            * maFile;

     if (argc < 3)
          AfficheErreur(0);
     else {
          taille = atoi(argv[1]);
          nbElem = atoi(argv[2]);
     }
     
     //***********************************************************************//
     //*              Trace PILE fonction empiler/depiler                    *//
     //*              taille = nbElem = 5                                    *//
     //***********************************************************************//
     /*
     maPile = initPile(taille);
     printf("CAS GENERAL : empiler\n\n");
     afficheP(maPile);
     for (k =0; k < nbElem; k++){
          empiler(maPile,k);
          printf("\tElement empilé : %d\n",k);
     }
     afficheP(maPile);
     printf("CAS GENERAL : depiler\n");
     for (k = nbElem-1; k >0; k--)
          printf("\tElement dépilé : %.2f\n",depiler(maPile));
     afficheP(maPile);
     libererP(maPile);
     */


    //***********************************************************************//
    //*              Trace PILE fonction estVideP-SommetP                   *//
    //*              taille = nbElem = 2                                    *//
    //***********************************************************************//
    /*
    maPile = initPile(taille);
    printf("CAS PILE VIDE :\n");
    afficheP(maPile);
    printf("\tsommetP -> -\n");
    printf("\testVide -> %d\n\nCAS GENERAL:\n",estVideP(maPile));


    empiler(maPile,1);
    afficheP(maPile);
    printf("\tsommetP -> %.2f\n",sommetP(maPile));
    printf("\testVide -> %d\n\nCAS PILE PLEINE\n",estVideP(maPile));

    empiler(maPile,2);
    afficheP(maPile);
    printf("\tsommetP -> %.2f\n",sommetP(maPile));
    printf("\testVide -> %d\n\n",estVideP(maPile));
    libererP(maPile);
    */


     //***********************************************************************//
     //*                  Trace FILE fonction sommetF                        *//
     //*                     taille = nbElem = 5                             *//
     //***********************************************************************//
     /*
     maFile = initFile(taille);
     enfiler(maFile,0);
     afficherF(maFile);
     printf("CAS GENERAL\n\tSommet : %.2f\n",sommetF(maFile));
     for (k =1; k < nbElem; k++)
          enfiler(maFile,k);
     afficherF(maFile);
     printf("CAS FILE PLEINE\n\tSommet : %.2f\n",sommetF(maFile));
     libererF(maFile);
     */


     //***********************************************************************//
     //*              Trace FILE fonction enfiler-defiler                    *//
     //*                     taille = nbElem = 10                             *//
     //***********************************************************************//
     /*
     maFile = initFile(taille);
     for (k =0; k < nbElem; k++)
          enfiler(maFile,k);
     afficherF(maFile);
     printf("\nSuppression des 5 premiers éléments\n");
     for (k =0; k<5; k++)
          defiler(maFile);
     afficherF(maFile);
     printf("\nAjout de 5 nouvelles valeurs\n");
     for (k = nbElem; k<nbElem + 5; k++)
          enfiler(maFile,k);
     afficherF(maFile);
     printf("\nSuppression de 7 éléments\n");
     for (k =0; k<7; k++)
          defiler(maFile);
     afficherF(maFile);
     libererF(maFile);
     */


     //***********************************************************************//
     //*              Trace  FILE fonction estVide                           *//
     //*                     taille = nbElem = 2                             *//
     //***********************************************************************//
     /*
     maFile = initFile(taille);
     printf("\nCAS FILE VIDE :\n");
     afficherF(maFile);
     printf("\tTest fonction : estVideF -> %d\n\nCAS GENERAL\n",estVideF(maFile));
     enfiler(maFile,8);
     afficherF(maFile);
     printf("\tTest fonction : estVideF -> %d\n\nCAS FILE PLEINE :\n",estVideF(maFile));
     enfiler(maFile,6);
     afficherF(maFile);
     printf("\tTest fonction : estVideF -> %d\n",estVideF(maFile));
     libererF(maFile);
     */


}
