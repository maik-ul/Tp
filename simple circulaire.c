#include <stdio.h>
#include <stdlib.h>

      typedef struct cellule{
           int info;
           struct cellule* suiv;
       } cellule, *liste;

       void insererTete(int val, cellule** l) {
           liste t = (cellule*) malloc(sizeof(cellule));

             if(t == NULL){
                return;
             }
             t->info = val;

              if(l == NULL){
                  t->suiv = t;
                    return ;
              }
        cellule* dernier = *l;
            while(dernier->suiv != *l){
                dernier = dernier->suiv;
            }

             t->suiv = *l;
             dernier->suiv = t;
              return ;
   }

        void insererFin(int val, cellule** l) {
            liste t=(cellule*) malloc(sizeof(cellule));
               t->info = val;
                  if(l == NULL){
                      t->suiv=t;
                      return ;
                  }
                cellule* dernier = *l;
                  while(dernier->suiv != *l){
                          dernier = dernier->suiv;
                          dernier->suiv = t;
                           t->suiv = *l;
                            return ;
       }
   }
   void afficherListe(cellule* l){
        if(l==NULL){
           printf("liste vide\n");
            return;
          }
            cellule* ptr = l;
         do {
              printf("%d",ptr->info);
               ptr = ptr->suiv;
           } while(ptr!=l);
         printf("(retour à %d)\n",l->info);
   }

  int main() {
      cellule* l = NULL;
      int choix,val;

   printf("==== GESTION DE LISTE CIRCULAIRE ====\n");
         do{
             printf("1.Afficher la liste\n");
             printf("2.Inserer en tete\n");
             printf("3.Inserer en fin\n");
             printf("4.Quitter");
             printf("Votre choix: \n");
              scanf("%d",&choix);

         switch(choix) {
            case 1:
                afficherListe(l);
             break;
            case 2:
              printf("Entrez la valeur a inserer en tete : ");
              scanf("%d", &val);
              insererTete(val, &l);
              afficherListe(l);
             break;
           case 3:
               printf("Entrez la valeur a inserer en fin : ");
               scanf("%d", &val);
               insererFin(val, &l);
               afficherListe(l);
             break;
         default :
            printf("Choix invalide !\n");
      }
   } while(choix !=3);

  return 0;
}
