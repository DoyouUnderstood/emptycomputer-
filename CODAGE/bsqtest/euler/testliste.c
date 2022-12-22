#include <stdio.h>
#include <stdlib.h>

typedef struct ele{
    int x;
    struct ele* suivant;
} *element;

typedef struct lis{

    struct lis* premier;
    struct lis* courant;
    struct lis* dernier;
} *liste;

void initListe(liste L){

    element Element_liste; 
    L = (liste) malloc ( sizeof(struct lis));
    L->premier = (element) malloc ( sizeof(ele));
    L->courant = (element) malloc ( sizeof(ele));
    L->dernier = (element) malloc ( sizeof(ele));
    L->premier = NULL;
    L->courant = NULL;
    L->dernier = NULL;
}
void insereUnElemt(Pliste L, Pelement nouveau){
    nouveau->suivant = L->premier;

    L->premier = nouveau;
    if( L->dernier ==NULL )
        L->dernier = nouveau;
    }

void creeListeDecroissante(Pliste L, int n)
{

    printf("***** creeListeDecroissante() *****\n");
    int i;
    Pelement Pel;
    for(i=1; i<=n; i++){
        Pel = (Pelement)malloc( sizeof (Element));
        Pel->x = i;
    insereUnElemt(L, Pel);
    }
}
void afficheListe(Pliste L){
    L->courant = L->premier;
    while (L->courant != NULL){
        printf("%d, ", L->courant->x);
        L->courant = L->courant->suivant;
    }
}
float moyenne(Pliste L){

    int som = 0, cpt = 0;
    L->courant = L->premier;
while (L->courant != NULL){
    cpt++;
    som += L->courant->x;
    L->courant = L->courant->suivant;
}
return (som/cpt);
}
int main(){
    initListe(maListe);
    creeListeDecroissante(maListe, 5);
    printf("Liste = [ ");
    afficheListe(maListe);
    printf(" ]\n");
    printf("Moyenne(Liste) = %.2f\n", moyenne(maListe));
    return 0;
}