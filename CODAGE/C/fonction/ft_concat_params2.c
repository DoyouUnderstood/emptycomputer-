#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
char	*ft_concat_params(int argc, char **argv)
{
	char	*args;
	int		i;
	int		j;
	int		o;

	args = malloc((argc) * sizeof(char));
	i = 1;
	o = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			args[o] = argv[i][j];
			o++;
			j++;
		}
		if ((i + 1) < argc)
			args[o] = '\n';
		o++;
		i++;
	}
	args[o - 1] = '\0';
	return (args);
}


int main(int argc, char **argv)
{

    char *str = ft_concat_params(argc,argv);
    printf("%s", str);
}   