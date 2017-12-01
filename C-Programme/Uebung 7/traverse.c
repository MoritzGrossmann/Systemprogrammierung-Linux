#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int dir_depth(const char *path)
{
    int z = 0;
    char *zgr = (char *)path;

    while((zgr = strchr(zgr, '/'))) 
    {
        zgr++;
        z++;
    }
    return z;
}

int traverse(const char *path, const struct stat *sb, int typeflags) 
{
    static char firsttime = 1;
    static int initial_depth;

    if (!firsttime)
    {
        for (int i = 1; i < dir_depth(path) - initial_depth; i++) printf("\t|");

        printf("----%s", strrchr(path, '/') + 1);

    } else {
        initial_depth = dir_depth(path);
        firsttime = 0;
        printf("%s\n", path);
    }

    switch (typeflags) 
    {
        case FTW_F:
            printf("\n");
            break;
        case FTW_D:
            printf("/\n");
            break;
        case FTW_DNR:
            printf("/-\n");
            break;
        case FTW_NS:
        default:
            perror("file traverse walk");
    }

    return 0;
}

int main(int argc, char **argv) 
{

    int fd = open("..", O_RDONLY);
    fchdir(fd);
    char *cwd = getcwd(NULL, 0);
    printf("%s\n", cwd);
    free(cwd);
    close(fd);
    chdir("..");

    ftw(".", &traverse, 100); //Aktuelles Verzeichnis

    return EXIT_SUCCESS;
}