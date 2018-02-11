#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>

#define BUFFERSIZE 512


struct myparams {
    unsigned int f:1;
    unsigned char *file;
};

int main(int argc, char **argv)
{
    struct myparams params = {0,""};
    char option = 0;

    while((option = getopt(argc, argv, "f:")) < 0)
    {
       switch (option)
        {
            case 'f':
                {
                    params.f = 1;
                    if (optarg)
                    {
                        params.file = optarg;
                    }
                }

            break;
            default:
                error(0,0,"-f <file>");
                return EXIT_FAILURE;
        }
    }

    int fd_write;
    mode_t fileOpenMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    int flags = O_CREAT | O_TRUNC | O_WRONLY;

    printf("File: %s", params.file);

    if ((fd_write = open(params.file, flags, fileOpenMode)) < 0)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    char *data = (char *)malloc(sizeof(char) * BUFFERSIZE);
    size_t read_bytes = 0;

    while((read_bytes = read(STDIN_FILENO, data, BUFFERSIZE)) > 0)
    {
        if ((write(fd_write, data, read_bytes)) < 0)
        {
            perror("open");
        }
    }

    return EXIT_SUCCESS;
}