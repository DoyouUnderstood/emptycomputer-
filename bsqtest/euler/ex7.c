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
    int i = 0;
    int res = 0;
    while(res != 10001)
    {
        if(ft_is_prime(++i) == 1)
            res++;
    }
    printf("%d", i);
}