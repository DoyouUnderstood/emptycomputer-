#include "my.h"

int ft_printf(char *ftr, ...)
{
    va_list ap;
    int i,d,p,u,x;
    char c, *s; 
    va_start(ap, ftr);

    i = 0;
    while(ftr[i])
    {
        if(ftr[i] == 'd')
        {    
            d = va_arg(ap, int);
            ft_putnbr(d);
        }
        else if(ftr[i] == 's')
        {
            s = va_arg(ap, char *);
            ft_putstr(s);
        }
        else if(ftr[i] == 'c')
        {
            c = va_arg(ap, int);
            ft_putchar(c);
        }
        else if(ftr[i] == '\n')
            ft_putchar('\n');
        else if(ftr[i] == 'p')
        {
            p = va_arg(ap, int);
            ft_putstr(ft_base(p,16));
        }
        else if(ftr[i] == 'u')
        {
            u = va_arg(ap,int);
            ft_putnbr_unsigned(u);
        }
        else if(ftr[i] == 'x')
        {
            x = va_arg(ap, int);
            ft_putstr(ft_base_unsigned(x,16));
        }

        i++;
    }
}
int main()
{  
    //ft_printf("%x\n", -78);
    printf("%x\n", -6);
}