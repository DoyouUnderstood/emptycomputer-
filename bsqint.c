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
int **make_map(char *str, int len)
{
    int i = -1;
    int j = 0;
    int width = 0;
    int **map;
    while (str[++i] >= '0' && str[i] <= '9')
        width = width * 10 + str[i] - 48;
        printf("%d\n%d\n", len, width);
    map = malloc(sizeof(int*) * width);
    i = -1;
    while(++i < width)
        map[i] = malloc(sizeof(int) * len + 1);
    i = 0;

    return (map);
}
int **fill_map(int **map, char *str)
{
    int i = 0;
    int j = 0;

    while(str[i])
    {
        if(str[i] == '.')
            map[j][i] = 1;
        else if(str[i] == 'o')
            map[j][i] = 0;
        i++;
        if(i = 27)
        {
            i = 0;
            j++;
        }
    }
}
int main(int argc, char **argv)
{
    if(argc != 2)
        return 0;
    char *str = open_map(argv[1]);
    int len = open_map2(str);
    int** map = make_map(str, len);
    fill_map(map,str);
}