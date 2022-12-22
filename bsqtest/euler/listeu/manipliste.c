#include <stdio.h>
#include <stdlib.h>

typedef struct ListeElement
{
    int valeur; 
    struct ListeElement *suivant;
}ListeElement, *Liste;

Liste cree_liste()
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
Liste ajouter_elem_a_x(Liste li, int val, int position)
{
    int i = 0;
    ListeElement *temp; 
    ListeElement *element;
    element = malloc(sizeof(*element));
    temp = li;
    element->valeur = val;
    element->suivant = NULL;
    for(i = 2; i<= position - 1; i++)
    {
        temp = temp->suivant;
    }
    element->suivant = temp->suivant;
    temp->suivant = element;
    return li;
}
Liste suppr_a_x(Liste li, int pos)
{
    ListeElement *todelete,*prevnode;
    todelete = li;
    prevnode = li;
    for(int i = 2; i<=pos; i++)
    {
        prevnode = todelete;
        todelete = todelete->suivant;
    }
    if(todelete != NULL)
    {
        if(todelete == li)
            li = li->suivant;
        prevnode->suivant = todelete->suivant;
        todelete->suivant = NULL;
        free(todelete);
    }
    return li;
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
int nombre_element(Liste li)
{
    int i = 0;
    while(li != NULL)
    {
        li = li->suivant;
        i++;
    }
    return i; 
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
Liste cherche_elem(Liste li,int val)
{
    ListeElement *tmp=li;
    while(tmp != NULL)
    {
        if(tmp->valeur == val)
        {
            /* Si l'élément a la valeur recherchée, on renvoie son adresse */
            return tmp;
        }
        tmp = tmp->suivant;
    }
    return NULL;
}
int nb_occu(Liste li, int val)
{
    int res = 0;
    while(li != NULL)
    {   
        if(li->valeur == val)
            res++;
        li = li->suivant;
    }
    return res;
}
Liste remplir_liste(char **argv, Liste list_a)
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
int check(Liste list_a)
{
    for(list_a; list_a->suivant != NULL; list_a = list_a->suivant)
        if(list_a->valeur >= list_a->suivant->valeur)
            return 0;
    return 1;
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
Liste fonction_sa_3(Liste liste_a)
{
    ListeElement *lst;
    lst = malloc(sizeof(*lst));
    int tmp = liste_a->valeur; //1ère val
    int tmp2 = liste_a->suivant->valeur; //2ème val
    int tmp3 = liste_a->suivant->suivant->valeur;
    lst->valeur = tmp2;
    lst->suivant->valeur = tmp;
    lst->suivant->suivant->valeur = tmp3;
    lst->suivant->suivant->suivant = NULL; 
    liste_a = lst;
    return liste_a;
}
Liste fonction_pa(Liste liste_a, Liste liste_b)
{
    int val = liste_b->valeur;
    liste_a = ajouter_elem_au_debut(liste_a, val);
    return liste_a; 
}
Liste fonction_ra(Liste liste_a)
{
    int val = liste_a->valeur;
    liste_a = suppr_1er_elem(liste_a);
    liste_a = ajouter_elem(liste_a,val);
    return liste_a;
}
int dernier_elem(Liste liste_a)
{
    printf("suu");
    ListeElement *tmp;
    tmp = malloc(sizeof(*tmp));
    printf("suu");
    int val = 0;
    tmp = liste_a;
    while(tmp->suivant != NULL)
    {
        val = tmp->suivant->valeur;
        tmp = tmp->suivant;
    }
    free(tmp);
    return val;
}
Liste fonction_rra(Liste liste_a)
{
    printf("su");
    printf("suu");
    int last_val = dernier_elem(liste_a);
    liste_a = suppr_der_elem(liste_a);
    liste_a = ajouter_elem_au_debut(liste_a, last_val);
    return liste_a;
}
Liste sorted_3_nbr(Liste liste_a)
{
    if(liste_a->valeur < liste_a->suivant->suivant->valeur && liste_a->suivant->valeur < liste_a->suivant->suivant->valeur)
    {
        liste_a = fonction_sa(liste_a);
        printf("suu1");
    }
    if(liste_a->valeur < liste_a->suivant->suivant->valeur && liste_a->suivant->valeur > liste_a->suivant->suivant->valeur)
    {
        //liste_a = fonction_sa_3(liste_a);
        //liste_a = fonction_ra(liste_a);
    }
    if(liste_a->suivant->valeur > liste_a->suivant->suivant->valeur && liste_a->valeur > liste_a->suivant->valeur)
    {
        fonction_sa_3(liste_a);
        fonction_rra(liste_a);
        //afficher_liste(liste_a);

    }
    return liste_a;
}
int main(int argc, char **argv)
{
    ListeElement *list_a = cree_liste();
    ListeElement *list_b = cree_liste();
    list_a = remplir_liste(argv, list_a);
    list_a = sorted_3_nbr(list_a);
    afficher_liste(list_a);

}