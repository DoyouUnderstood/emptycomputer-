#include <stdio.h>
#include <stdlib.h>

int divisible(int nbr)
{
    int i = -1;
    while(nbr % ++i == 0)
        i++;
    if(i = 20)
        return 1;
    return 0;  
}
int main()
{
    int i = 2000; 
    while(divisible(i) == 0)
        i+= 5;
    printf("%d", i);
}