#include <stdio.h>
#include <stdlib.h>

typedef struct lis{
    int a; 
    struct lis* suivant;
} *element;

typedef struct t{
    element prem, der, cour;
} *liste;

typedef struct p{
    char *nom;
} *personne;

liste cree_liste()
{
    liste Liste_entier;
    Liste_entier = (liste)malloc(sizeof(struct t));
    Liste_entier->prem = Liste_entier->der = Liste_entier->cour = NULL;
    return(Liste_entier);
}

void inser_liste(liste Liste_Entier, int Val)
{
    element Element_liste = NULL;
    Element_liste = (element)malloc(sizeof(struct lis));
    Element_liste->a = Val;

    if(Liste_Entier->prem == NULL)
    {
        Liste_Entier->prem = Liste_Entier->der = Liste_Entier->cour = Element_liste;
        Element_liste->suivant = NULL;
    }
    else if(Liste_Entier->cour != Liste_Entier->der)
    {
        
        Element_liste->suivant = Liste_Entier->cour->suivant;
        Liste_Entier->cour->suivant = Element_liste;
        
    }
    else
    {
        Element_liste->suivant = NULL;
        Liste_Entier->cour->suivant = Element_liste;
        Liste_Entier->cour = Liste_Entier->der = Element_liste;
    }

}

int main()
{
    liste l;
    int iCompteur;
    l = cree_liste();
    for(iCompteur = 1; iCompteur < 5 ; iCompteur++)
    {
        inser_liste(l,iCompteur);
        printf("Courant : %d\n", l->cour->a);
    }
    l->cour = l->prem;
    printf("liste dans ca totalité : ");
    while(l->cour != l->der)
    {
        printf("%d", l->cour->a);
        l->cour = l->cour->suivant;
    }
    printf("%d", l->cour->a);
}
