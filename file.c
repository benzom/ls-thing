#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h> /*library for retrieving information on files and directories*/
#include <string.h>

int main (int argc, char *argv[])
{
	DIR *dir; /*represents a directory stream */
	struct dirent * sd;
	char mfile[127];
	
	if (argc < 2) 
	{
		strcpy(mfile, ".");
	}
	else
        strcpy(mfile, argv[1]);

        printf("%s\n\n", mfile);
        dir = opendir(mfile);

	while((sd = readdir(dir)) != NULL)
	{
		printf(">> %s\n", sd->d_name);
		sd = readdir(dir);
	}

	closedir(dir);

	return 0;
}
