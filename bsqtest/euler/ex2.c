#include <stdio.h>

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
    long long current = 600851475143; 
    int i = 3;
    int high = 0;

    while (1)
    {
        while (!(current % i)) // while no remainder
        {
            current /= i;  // divide and replace
            high = i; 
        }
        if (current == 1)
            break;
        i +=2 ; // skip all even numbers since not prime
    }


    printf ("Highest prime factor of 600851475143 is %d\n", high);
    return 1;
}