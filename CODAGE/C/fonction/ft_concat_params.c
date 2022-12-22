#include <stdlib.h>
#include <stdio.h>
int ft_strlen(const char *s)
{
     int count = 0;
    while(*s!='\0')
    {
        count++;
        s++;
    }
    return count;
}
char * ft_concat_params(int argc, char **argv)
{
    int     i = 0;
    int     len = 0;
    char    *str;
    int     j = 0;
    int     k = 0;

    str = malloc(sizeof(char) * argc);

    i = 1;
    while(i < argc)
    {
        while(argv[i][j] != '\0')
        {
            str[k] = argv[i][j];
            k++;
            j++;
        }
        if ((i + 1) < argc)
			str[k] = '\n';
        k++;
        i++;
        j = 0;
    }
    str[k - 1] = '\0';
    printf("%s", str);
    return str;
}
int main(int argc, char **argv)
{
    char *str = ft_concat_params(argc,argv);
}   