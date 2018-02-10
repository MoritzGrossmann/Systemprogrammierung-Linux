#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>

mode_t fileOpenMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
int flags = O_CREAT | O_APPEND | O_WRONLY;

struct myparams {
    unsigned int f:1;
    char *file;
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
                params.f = 1;
                if (optarg)
                {
                    params.file = (char *)optarg;
                }
            break;
            default:
                error(0,0,"-f <file>");
                return EXIT_FAILURE;
        }
    }
    int fd;

    if ((fd = open(params.file, flags, fileOpenMode)) < 0)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}