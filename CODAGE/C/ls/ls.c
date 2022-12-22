#include "my.h"

void ls(char* dir)
{
	struct dirent *d;

	DIR *dh = opendir(dir);

	while((d = readdir(dh)) != NULL)
	{
		printf("%s\n", d->d_name);
	}

}
int main(int argc, char **argv)
{
	ls(".");
}