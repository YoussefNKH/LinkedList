#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"


List * initialisation (){
List *newlist;
newlist=(List*)malloc(sizeof(List));
if (newlist==NULL)
{
    exit(EXIT_FAILURE);
}
newlist->dim=0;
newlist->first=NULL;
newlist->last=NULL;

return newlist;
}
/*inserting*/
void add_empty_list(List *list  ,char *nom)
{
    Element *e;
    e=(Element *)malloc(sizeof(Element));
    if (list==NULL || e==NULL)
    {
        exit(EXIT_FAILURE);
    }
    e->name=(char*)malloc(20*sizeof(char));
    if(e->name==NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(e->name,nom);
    e->suivant=NULL;
    list->dim=1;
    list->first=e;
    list->last=e;
}

void add_first_list(List *list,char *nom)
{
/*declaration*/
Element *e;
e=(Element*)malloc(sizeof(Element));
/*check*/
if (e==NULL||list==NULL)
{
    exit(EXIT_FAILURE);
}
e->name=(char*)malloc(20*sizeof(char));
if(e->name==NULL)
{
    exit(EXIT_FAILURE);
}
/*partie exucitif*/


strcpy(e->name,nom);
e->suivant=list->first;
list->first=e;
list->dim++;

}
void add_last_list(List *list,char *nom)
{
    Element *nouv;
    nouv=(Element*)malloc(sizeof(Element));
    if (list==NULL || nouv==NULL )
    {
        exit(EXIT_FAILURE);
    }
    if((nouv->name=(char *)malloc(20*sizeof(char))))
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nouv->name,nom);
    nouv->suivant=NULL;
    list->last->suivant=nouv;
    list->last=nouv;
    list->dim++;
}
void add_to_pos_in_list(List *list,char *nom , int pos)
{  /*1 ere cas de sortie*/
   if(list->dim<2)
   {
       exit(EXIT_FAILURE);
   }
   if(pos<1 ||pos>=list->dim)
   {
       exit(EXIT_FAILURE);
   }
   Element *courant;
  Element *nouveau_element;
  int i;

  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL|| list ==NULL )
    {
        exit(EXIT_FAILURE);
    }
  if ((nouveau_element->name = (char *) malloc (20 * sizeof (char)))== NULL)
    {
        exit(EXIT_FAILURE);
    }

  courant = list->first;
  for (i = 1; i < pos; ++i)
    courant = courant->suivant;
  if (courant->suivant == NULL)
    {
        exit(EXIT_FAILURE);/*si pos == fin de la list*/
    }
  strcpy (nouveau_element->name,nom);

  nouveau_element->suivant = courant->suivant;
  courant->suivant = nouveau_element;
  list->dim++;

}
/*suppretion*/
void supp_first(List *list )
{
    Element *e;

    if (list->dim==0)
    {
        exit(EXIT_FAILURE);
    }
    e=list->first;
    list->first=list->first->suivant;
    if(list->dim==1)
    {
        list->last=NULL;
    }
    free(e->name);/*car le donnée est alloc*/
    free(e);
    list->dim--;

}
void supp_list(List *list)
{
    while(list->dim >0)
        supp_first(list);
}
void supp_dans_liste(List *list , int pos)
{ /* partie declaratif*/
    Element *e1;
    Element *e;
    /*Chèque*/
    if(pos<1||pos>=list->dim)
    {
        exit(EXIT_FAILURE);
    }
     if(list->dim<2)
   {
       exit(EXIT_FAILURE);
   }
    if (list==NULL)
    {
        exit(EXIT_FAILURE);

    }
    /*traitement*/
    e=list->first;
    pos--;
    while(pos!=0)
    {
        e=e->suivant;
        e1=e;
        pos--;

    }
    e1->suivant=e->suivant;
    free(e->name);/*hedhi 9bal free e sinon bich tdhi3 l'adresse mta3 name*/
    free(e);
    list->dim--;
}
/*affichage*/
void affiche(List *list)
{   /* declaration*/
    Element *e;
    int nb;
    /*check*/
    if (list==NULL)
    {exit(EXIT_FAILURE);}
    /*partie exucitif*/
    nb=0;
    e=list->first;
    while(e->suivant!=NULL)
    {
     printf(" l'eleve num %d : %s\t",nb,e->name);
     e=e->suivant;
     nb++;
    }
int menu(List *list,int *k)
{     int choix;

        printf("********** MENU **********");
        if (list->dim == 0){
                printf ("1. Ajout du 1er element");
                printf ("2. Quitter");
        } else if(list->dim == 1 || *k == 1){
                printf ("1. Ajout au debut de la liste");
                printf ("2. Ajout a la fin de la liste");
                printf ("4. Suppression au debut de la liste");
                printf ("6. Detruire la liste");
                printf("7.afficher tout la liste");
                printf ("8. Quitter");
        }else {
                printf ("1. Ajout au debut de la liste");
                printf ("2. Ajout a la fin de la liste");
                printf ("3. Ajout apres la position specifie");
                printf ("4. Suppression au debut de la liste");
                printf ("5. Suppression a la position specifie");
                printf ("6. supprimer tout  la liste");
                printf("7.afficher tout la liste");
                                printf ("8. Quitter");
        }
        printf ("Faites votre choix : ");
        scanf ("%d", &choix);

        if (list->dim == 0 && choix == 2)
                choix = 8;
return choix;
}
}
