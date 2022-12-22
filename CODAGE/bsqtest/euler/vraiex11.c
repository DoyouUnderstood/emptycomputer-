#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE_MAX 10000

char* openfile()
{
    struct stat sb;
    char *buf;
    int size;

    int fd = open("fichiertxtex11.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    
    buf = malloc(sizeof(char) * sb.st_size);
    size = read(fd, buf, sb.st_size);
    buf[size] = '\0';
    return buf;
}
int main(){

    char *str = openfile();
    printf("%s", str);
    
}