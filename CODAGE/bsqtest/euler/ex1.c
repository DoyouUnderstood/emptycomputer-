#include <stdio.h>
int fibonaci(unsigned int nb)
{
    if (nb < 0)
		return (-1);
	if (nb == 0)
		return (0);
	if (nb == 1)
		return (1);
    return(fibonaci(nb - 1) + fibonaci(nb - 2));
}
int main()
{
    unsigned int i = 0;
    unsigned somme = 0;
    while(fibonaci(i) < 4000000)
    {
        if (fibonaci(i) % 2 == 0 && fibonaci(i) < 4000000)
        {
            somme += fibonaci(i);
            i++;
        }
        i += 2;
    }
    printf("%d", somme);
}