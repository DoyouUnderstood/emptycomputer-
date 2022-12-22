#include <stdlib.h>
#include <stdio.h>
int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + str[i] - '0';
        i++;
    }
    printf("res 2 : %d", res);
    return res;
}
int main()
{
    printf("res : %d\n", atoi("789456"));
    int res = ft_atoi("789456");
}