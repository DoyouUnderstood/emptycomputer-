#include <stdio.h>
#include <stdlib.h>
struct noeud
{ 
    int cle;
    struct noeud *suivant; 
};

static struct noeud *debut, *z, *t;

void InitialiserPile ()
{
    debut = (struct noeud *)malloc(sizeof *debut); 
    z = (struct noeud *)malloc(sizeof * z);
    debut->suivant = z; 
    z->cle = 0; 
    z->suivant = z;
}
void Empiler (int v)
{ 
    t = (struct noeud *)malloc(sizeof *t);
    t->cle=v;
    t->suivant = debut->suivant; 
    debut->suivant = t;
}

int Depiler ()
{
    int x;
    t = debut->suivant;
    debut->suivant = t->suivant; 
    x = (int)t->suivant; 
    free(t);

    return x;
}

int PileVide() 
{ 
    return debut ->suivant == z;
}
int main()
{
    return 1;
}