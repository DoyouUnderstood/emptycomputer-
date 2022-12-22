#include <stdio.h>
#include <stdlib.h>

typedef struct pi
{
    int val;
    struct pi* precedent;
}*pile;

pile creer_pile()
{
    pile *p;
    p = malloc(sizeof(*p));
    if (p != NULL)
        return NULL;
}
int vide(pile p)
{
    if(p != NULL)
        return 0;
    return 1;
}
int sommet(pile p)
{
    if(p)
        return p->val;
    else 
        return -32768;
}
void empiler(pile* p, int Val)
{
    pile e;
    e = (pile)malloc(sizeof(pile));
    e->val = Val;
    e->precedent = *p;
    *p = e;
}

void desempiler(pile* p)
{
    pile q;
    if(*p)
        q = *p;
    *p = (*p)->precedent;
    free(q);   
}
void afficher_recursive(pile p)
{
    if(p)
    {
        int Val = p->val;   
        p = p->precedent;
        printf("%d ", Val);
        afficher_recursive(p);
    }
    else
        return;
    
}
void afficher_echange_depointeur(pile p)
{
    pile q,r;
    q = NULL;

    while(p)
    {
        r = p->precedent;
        p->precedent = q;
        q = p;
        p = r;
    }
    while(q)
    {
        printf("%d ",q->val);
        r = q->precedent;
        q->precedent = p;
        p = q;
        q = r;
    }
}
int afficher_nb_liste(pile p)
{
    int nb_de_liste = 0;
    while(p)
    {
        nb_de_liste += 1;
        p = p->precedent;
    }
    return nb_de_liste;
}

pile empiler_au_debut(pile p, int vale)
{
    pile q;
    q = malloc(sizeof(*q));
    q->val = vale;
    q->precedent = p;
    return q;
}

int main()
{
    pile p = creer_pile();
    empiler(&p, 5);
    afficher_echange_depointeur(p);
    printf("\n");
    empiler(&p, 6);
    afficher_echange_depointeur(p);
    printf("\n");
    empiler(&p, 7);
    afficher_echange_depointeur(p);
    printf("\n");
    p = empiler_au_debut(p, 9);
    afficher_echange_depointeur(p);
}
