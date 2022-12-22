#include <stdio.h>
#include <stdlib.h>

typedef struct ListeElement
{
    int valeur; 
    struct ListeElement *suivant;
}ListeElement, *Liste;

Liste *cree_liste()
{
    return NULL;
}

int liste_vide(Liste li)
{
	return (li == NULL)? 1 : 0;
}

Liste ajouter_elem(Liste li,int val)
{
    ListeElement *element;
    ListeElement *temp;

    element = malloc(sizeof(*element));
    if (element == NULL)
        printf("erreur alloc ");
    element->suivant = NULL;
    element->valeur = val;
    if (liste_vide(li))
        return element;
    
    temp = li;
    while(temp->suivant != NULL)
        temp = temp->suivant;

	temp->suivant = element;
    return li;
}
Liste *remplir_liste(char **argv, Liste *list_a)
{
    int i = 1;
    int j;
    int nbr = 0;
    while(argv[i] != '\0')
    {
        j = 0;
       while (argv[i][j] >= 48 && argv[i][j] <= 57)
	    {
		    nbr = nbr * 10 + (argv[i][j] - 48);
            j++;
	    }
        list_a = ajouter_elem(list_a,nbr);
        nbr = 0;
        i++;
    }
    return list_a;
}
Liste ajouter_elem_au_debut(Liste li, int val)
{
    ListeElement *element;
    element = malloc(sizeof(*element));
    if (element == NULL)
        printf("erreur alloc ");
    element->valeur = val;
    element->suivant = li;
    return element;
}
void afficher_liste(Liste li)
{
    if(liste_vide(li))
    {
        printf("liste vide frerot rien a affichay\n");
        return;
    }
    while(li != NULL)
    {
        printf("[%d] ", li->valeur);
        li = li->suivant;
    }
    printf("\n");
}
Liste suppr_der_elem(Liste li)
{
    ListeElement *element;
    ListeElement *temp;
    temp = li;
    element = li;

    while(temp->suivant != NULL)
    {
        element = temp;
        temp = temp->suivant;
    }
    element->suivant = NULL;
    free(temp);
    temp = NULL;

    return li;

}
Liste suppr_1er_elem(Liste li)
{
    ListeElement *element;
    element = malloc(sizeof(element));
    element = li->suivant;
    free(li);
    li = NULL;
    return element;

}

Liste fonction_ra(Liste liste_a)
{
    int val = liste_a->valeur;
    liste_a = suppr_1er_elem(liste_a);
    liste_a = ajouter_elem(liste_a,val);
    return liste_a;
}

Liste fonction_sa(Liste liste_a)
{
    ListeElement *temp,*lst;
    temp = malloc(sizeof(*temp));
    lst = malloc(sizeof(*lst));
    int tmp = liste_a->valeur; //1ère val
    int tmp2 = liste_a->suivant->valeur; //2ème val
    temp = liste_a->suivant->suivant; //copie 
    lst->valeur = tmp2;
    lst->suivant->valeur = tmp;
    lst->suivant->suivant = temp;
    liste_a = lst;

    return liste_a;
}

int main(int argc, char **argv)
{
    ListeElement list_a = cree_liste();
    ListeElement list_b = cree_liste();
    remplir_liste(argv, list_a);
    afficher_liste(list_a);
}