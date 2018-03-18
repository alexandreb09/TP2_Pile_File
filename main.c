#include "Pile.h"
#include "File.h"
#include "Erreur.h"
#include <stdio.h>
#include <stdlib.h>                                    //fonction atoi

int main (int argc, char * argv[]){
     int                 codeErreur = 0,
                         nbElem = 10,
                         taille = 10;
     pile_t            * maPile;

     if (argc < 3)
          AfficheErreur(0);
     else {
          taille = atoi(argv[1]);
          nbElem = atoi(argv[2]);
     }

     maPile = genererPile(taille,nbElem);
     if (maPile){
          afficheP(maPile);

          maPile = inversion(maPile,&codeErreur);
          if (codeErreur == 2)     AfficheErreur(codeErreur);
          afficheP(maPile);
     }
     else AfficheErreur(1);
     libererP(maPile);

}
