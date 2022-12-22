#include <stdio.h>
#include <stdlib.h>
int sqqqqqqqqqqqrt(int nb)
{
    return nb * nb; 
}
int main()
{
    int i = 1;
    int j = 1;
    int nbr = 1000;
    for(i; i <= 100; i++)
    {
        for(j; j <= 100; j++)
        {
            if(sqqqqqqqqqqqrt(i) + sqqqqqqqqqqqrt(j) == 1000)
            {
                printf("ceci est une victoire : %d %d ", i,j);
                return 0;
            }
        }
        j = 0;
    }
}