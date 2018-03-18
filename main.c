#include "Pile.h"
#include "File.h"
#include <stdio.h>
#include <stdlib.h>                                    //fonction atoi

int main (int argc, char * argv[]){
     int                 codeErreur = 0,
                         nbElem = 10,
                         taille = 10;
     pile_t            * maPile;

     if (argc < 3)
          printf("Veuillez saisir 2 arguments : la taille de la pile et le nombre d'éléments\n");
     else {
          taille = atoi(argv[1]);
          nbElem = atoi(argv[2]);
     }
     printf("taille : %d\n",taille);
     maPile = genererPile(taille,nbElem);
     afficheP(maPile);

     maPile = inversion(maPile,&codeErreur);

     afficheP(maPile);
     libererP(maPile);

}
