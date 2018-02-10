#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFERSIZE 512

struct myparams {
    unsigned int f:1, r:1, w:1;
    unsigned char *file;
};

int writeInFile(int fd, char *text)
{
    int length = strlen(text);
    if ((write(fd, text, length)) < 0)
    {
        perror("write");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

char *readFile(int fd)
{
    char *str = (char *)malloc(sizeof(char));
    int actualsize = 0;

    char *buffer = (char *)malloc(sizeof(char) * BUFFERSIZE);
    int length = 0;
    do {
        length = read(fd, buffer, BUFFERSIZE);
        if (length > 0)
        {
            str = (char *)realloc(str, sizeof(char) * actualsize + sizeof(char) * length);
            for (int i = 0; i < length; i++)
            {
                str[actualsize+i] = buffer[i];
            }
        }
        if (length < 0)
        {
            perror("read");
        }
        actualsize += length;
    } while(length == BUFFERSIZE);

    free(buffer);
    return str;
}

mode_t filemode = S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH;
int flags = O_CREAT | O_APPEND | O_WRONLY;

int main(int argc, char **argv)
{
    struct myparams param = {0,""};
    char c = 0;

    while((c = getopt(argc, argv, "rwf:"))!= -1)
    {
        switch(c) {
            case 'f':
                param.f = 1;
                if (optarg){
                    param.file = (char*) optarg;
                } 
                break;
            case 'r':
                param.r = 1;
                break;
            case 'w':
                param.w = 1;
                break;
            default:
                error(0,0,"[OPTION] -f <file>");
        }
        
    }

    if (param.f == 0 || !(param.r ^ param.w))
    {
        error(0,0,"[OPTION] -f <file>");
        return EXIT_FAILURE;
    }

    int fd;

    if ((fd = open(param.file, flags, filemode)) < 0)
    {
        perror("open");
    }

    if (param.w)
    {
        return writeInFile(fd, "Dies ist ein Test\n");
    }

    if (param.r)
    {
        printf("text: %s", readFile(fd));
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}