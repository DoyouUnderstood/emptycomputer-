#include <stdio.h>
#include <stdlib.h>

int pgcd(int a, int b)
{
  
    long r;
    if(a == 0 || b == 0)
    {
      return 0;
    }
    while(1)
    {
        r = a % b;
        if(r == 0)
            return b; 
        a = b;
        b = r;
    }
}
int main()
{
    int i = 0;
    int j = 0;
    int **tab; 
    tab = malloc(sizeof(int*) * 10);
    while( i < 10)
    {
        tab[i] = malloc(sizeof(int) * 10);
        i++;
    }
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(pgcd(i,j) == 1)
                tab[i][j] = 1;
            else
                tab[i][j] = 0;
        }
    }
} 