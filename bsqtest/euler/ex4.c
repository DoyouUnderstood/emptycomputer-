#include <stdio.h>
#include <stdlib.h>

int palyindrome(int nbr)
{
    int nbrInverser = 0;
    int tmp = nbr;
    while(tmp != 0)
    {
        nbrInverser = nbrInverser * 10;
        nbrInverser = nbrInverser + tmp%10;
        tmp = tmp/10;
    }
    if(nbr == nbrInverser)
        return 1;
    else
        return 0;
}
int main()
{
    int nb = 987759;
    while(palyindrome(nb) == 0)
        nb--;
    printf("%d", nb);
}