#include <stdio.h>
int verif(int nb)
{
    int i = 0;
    while ( i <= 20)
    {
        if(nb % i != 0)
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    int j = 5000;
    while(verif(j) != 1)
        j++;
    printf("%i", j);
}