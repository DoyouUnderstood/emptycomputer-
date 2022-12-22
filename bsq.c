#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

char *open_map(char *str)
{
    char *tab;
    int i = -1;
    int fd; 
    struct stat sb;
    stat(str, &sb);
    fd = open (str, O_RDONLY);
    tab = malloc(sizeof(char) * (sb.st_size + 1));
    read (fd, tab, sb.st_size);
    return (tab);
}
int open_map2(char *tab)
{
    int i = -1;
    int width = 0;
    int len = 0;
    while (tab[++i] >= '0' && tab[i] <= '9')
        width = width * 10 + tab[i] - 48;
    while (tab[++i] != '\n')
        len++;
    tab[(width * len) + width + 1] = '\0';
    return (len);
}
char **make_map(char *str, int len)
{
    int i = -1;
    int j = 0;
    int k = 0;
    int l = 0; 
    int m = 0;
    int width = 0;
    char **map;
    while (str[++i] >= '0' && str[i] <= '9')
        width = width * 10 + str[i] - 48;
        printf("%d\n%d\n", len, width);
    map = malloc(sizeof(char*) * width);
    i = -1;
    while(++i < width)
        map[i] = malloc(sizeof(char) * len + 1);
    i = 0;
     while(i < width * len)
    {
        while(str[i] != '\n')
        {
          map[j][k] = str[i];
          i++;
          k++;
        }
        k = 0;
        i++;
        j++;
    }
        for(j = 0; j < 29; j++)
        {
            my_putchar('c');
        }
    free(map);
    return (map);
}
int main(int argc, char **argv)
{
    if(argc != 2)
        return 0;
    char *str = open_map(argv[1]);
    int len = open_map2(str);
    make_map(str, len);
}