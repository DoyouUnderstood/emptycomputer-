#include <stdio.h>
#include <stdlib.h>
typedef struct element * Pelement;

typedef struct liste * Pliste;

typedef struct element{
    int x;
    Pelement suivant;
}Element;

typedef struct liste{
    Pelement premier;
    Pelement courant;
    Pelement dernier;
}Liste;

Liste l;
Pliste maListe = &l;

void initListe(Pliste L){
    L = (Pliste) malloc ( sizeof(Liste));
    L->premier = (Pelement) malloc ( sizeof(Element));
    L->courant = (Pelement) malloc ( sizeof(Element));
    L->dernier = (Pelement) malloc ( sizeof(Element));
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