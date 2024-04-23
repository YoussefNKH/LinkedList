#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
typedef struct Element Element;
struct Element{

char *name ;
Element *suivant;
};
typedef struct List List;
struct List{
int dim;
Element *first;
Element *last;
};
List * initialisation ();
void add_empty_list(List*,char *);
void add_first_list(List *,char*);
void add_last_list(List *,char *);
void add_to_pos_in_list(List *,char * , int);
void supp_first(List * );
void supp_dans_liste(List * , int );
void supp_list(List *);
void affiche(List *);
int menu(List *,int *);

#endif // LIST_H_INCLUDED
