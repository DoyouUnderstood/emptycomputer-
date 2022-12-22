#include <stdio.h>
#include <stdlib.h>

struct pi
{
    int valeur;
    struct pi* suivant;
}*Pile; 

struct pi cree_pile()
{
    struct pi *p;
    p = (struct pi*) malloc(sizeof(struct pi));
    p->suivant = NULL;
}

int afficher_nb_liste(struct pi *p)
{
    int nb_de_liste = 0;
    while(p)
    {
        nb_de_liste += 1;
        p = p->suivant;
    }
    return nb_de_liste;
}
void empiler(struct pi *p, int Valeur)
{
    struct pi *q; 
    q = (struct pi*)malloc(sizeof(struct pi));
    q->valeur = Valeur;
    q->suivant = p;
    p = q;
}
void afficher_liste(struct pi *p)
{
    if(p)
    {
        int val = p->valeur;
        p = p->suivant;
        printf("%d", val);
        afficher_liste(p);
    }
    else
        return;     
}


void empiler_au_debut(int valeur)
{
    struct pi *q;
    q = (struct pi*)malloc(sizeof(struct pi));
    q->valeur = valeur;
    q->suivant = Pile;
    Pile = q;
}

void afficher_echange_depointeur(struct pi *p)
{
    struct pi *q,*r;
    q = NULL;

    while(p)
    {
        r = p->suivant;
        p->suivant = q;
        q = p;
        p = r;
    }
    while(q)
    {
        printf("%d ",q->valeur);
        r = q->suivant;
        q->suivant = p;
        p = q;
        q = r;
    }
}
/*
void ajouter_au_millieu(struct pi *p, int val)
{
    int i = 0; 
    int mid = afficher_nb_liste(*p) / 2;
    struct pi *q;
    q = (struct pi*)malloc(sizeof(struct pi));
    q->valeur = val;
    while(i != mid)
    {
        (*p) = (*p)->suivant;
        i++;
    }
    printf("%d", (*p)->valeur);

    
}
*/
int main()
{
    Pile* p = cree_pile();
    empiler(&p, 1);
    empiler(&p, 2);
    afficher_echange_depointeur(&p);
    empiler(&p, 3);
    empiler(&p, 4);
    //empiler_au_debut(9);
    //ajouter_au_millieu(&p, 8);
}