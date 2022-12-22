#include <stdio.h>
int main()
{
    int somme = 0;
    int i = 0;
    while(i < 1000)
    {
        if(i % 3 == 0 || i % 5 == 0)
            somme += i;
        i++;
    }
    printf("%d", somme);
}