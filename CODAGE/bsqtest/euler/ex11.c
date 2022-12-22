#include <stdio.h>
#include <stdlib.h>
// trouver le nombre triangulaires qui a plus de 500 diviseurs.
int nombre_diviseurs(int nb)
{
    int i = 1;
    int nbrdiv = 0; 
    while(i != nb)
    {
        if((nb % i) == 0)
            ++nbrdiv;
         i++;
    }
    printf("%d ", nbrdiv);
    return nbrdiv;
}
int nombre_triangulairemabite(int nbr)
{
    int res = 0;
    while(nbr != 0)
        res+=nbr--;
    return res;
}
int main()
{
    long long i = 1;
    int j = 0;
    int nb = 1;
    while(nombre_diviseurs(i) < 500)
    {
        i = nombre_triangulairemabite(nb+=50000);
    }
    printf("la reponse est : %d", nb);
}