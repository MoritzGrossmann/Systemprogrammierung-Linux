#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("error: Es müssen 2 Dateien übergeben werden\n");
        return EXIT_FAILURE;
    }

    int flags = O_CREAT | O_WRONLY | O_APPEND;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    int fd1, fd2;

    if ((fd1 = open(argv[1], flags, mode)) < 0) 
    {
        perror("open first file");
    }

    if ((fd2 = open(argv[2], flags, mode)) < 0) 
    {
        perror("open second file");
    }

    return EXIT_SUCCESS;
}