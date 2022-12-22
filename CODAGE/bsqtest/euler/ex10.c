#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);

	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
int main()
{
    long long somme = 0;
    long long i = 0;
    while( i < 2000000)
    {
        if(ft_is_prime(i))
            somme+=i;
        i++;
    }
    printf("%lld",somme);
}