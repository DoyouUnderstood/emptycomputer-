#include <stdio.h>
#include <stdlib.h>

struct noeud{
    int cle;
    struct noeud *suivant;
};
int main()
{
    int i = 2;
    int N = 3;
    int M = 8;
    struct noeud *t, *x;
    t = (struct noeud*) malloc(sizeof * t);
    t->cle = 1;
    x = t;
    while(i <= M)
    {
        t->suivant = (struct noeud*) malloc(sizeof * t);
        t = t->suivant;
        t->cle = i;
        i++;
    }
    t->suivant = x;
    while(t != t->suivant)
    {
        for(i = 1; i <= N; i++)
            t = t->suivant;
        printf("%d ", t->suivant->cle);

        x = t->suivant;
        t->suivant = t->suivant->suivant;
        free(x);
        i++;
    }
    printf("%d ", t->cle);
}