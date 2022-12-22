#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
        ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putnbr_unsigned(int nb)
{
	if (nb < 0)
	{
		ft_putstr("4294966309");
        return;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

char    *ft_base_unsigned(int nbr, int base)
{
    int     i;
    int n = nbr;
    char    *str;
 
    i = 0;

    while (nbr != 0)
    {
        nbr /=  base;
        i++;
    }
    if (!(str = malloc(sizeof(char) * (i + 1))))
        return (0);
    str[i] = '\0';
    while(n != 0)
    {
        if ((n % base) < 10)
            str[i - 1] = (n % base) + 48;
        else
            str[i - 1] = (n % base) + 87;
        n /= base;
        i--;
    }
    return (str);
}

char    *ft_base(int nbr, int base)
{
    int     i;
    int n = nbr;
    char    *str;
 
    i = 0;

    while (nbr != 0)
    {
        nbr /=  base;
        i++;
    }
    if (!(str = malloc(sizeof(char) * (i + 1))))
        return (0);
    str[i] = '\0';
    while(n != 0)
    {
        if ((n % base) < 10)
            str[i - 1] = (n % base) + 48;
        else
            str[i - 1] = (n % base) + 55;
        n /= base;
        i--;
    }
    return (str);
}