#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0; 
    int somme = 0;
    long somme2 = 0;
    while (i <= 100)
    {
        somme += i * i;
        i++;
    }
    printf("somme de tout les carrés jusqu'a 100 : %d\n", somme);
    i = 1; 
    while (i <= 100)
    {
        somme2 += i;
        i++;
    }
    somme2 = somme2*somme2;
    printf("carre de la somme de tout les nombres jusqu'a 100 : %d\n", somme2);
    printf("diffrence entre les 2 : %d", somme2 - somme);
    
}