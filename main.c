#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"list.h"
int main()
{   int pos;
    int *k;
    int choix;
    char *nom;
    List *malist;

    malist=(List *)malloc(sizeof(List));
    if (malist==NULL)
    {
        exit(EXIT_FAILURE);
    }
    nom=(char *)malloc(20*sizeof(char));
    if(nom==NULL)
    {
        exit(EXIT_FAILURE);
    }


     malist=initialisation();
    choix=0;

     while(choix!=8)
     {
     choix =  menu(malist,&k);
         switch (choix)
         {
         case 1:
            printf("entrez un element :");
            scanf("%s",nom);
            if (malist->dim==0)
                add_empty_list(malist,nom);
            else
                add_first_list(malist,nom);
            break;
         case 2:
            printf("Entrez un element :");
            scanf("%s",nom);
            add_last_list(malist,nom);
            break;
         case 3:
            printf("Entrez un element :");
            scanf("%s",nom);
            do{
                printf("Entrez la position : ");
                scanf("%d",&pos);
            }while(pos<1||pos>malist->dim);
            if(malist->dim==1||pos==malist->dim)
            {
                k=1;
                printf("Insertion echouée,Utilisez le menu{1|2}\n");
                break;
            }
            add_to_pos_in_list(malist,nom,pos);
            break;
         case 4:
            supp_first(malist);
            if(malist->dim==0)
                printf("liste vide");
            break;
         case 5:
             do
             {
                 printf("Entrez la position :");
                 scanf("%d",&pos);
             }while(pos<1||pos>malist->dim);
             supp_dans_liste(malist,pos);
             if(malist->dim==0)
                printf("la liste est vide");
             break;
         case 6:
             supp_list(malist);
             printf("la liste a ete supprimer : %d elements",malist->dim);
           break;
         case 7:
            affiche(malist);

        printf("la taille de la list est :%d",malist->dim);
        break;
         }
     }
     return 0;
}
