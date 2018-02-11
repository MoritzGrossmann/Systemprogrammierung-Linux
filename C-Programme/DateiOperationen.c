#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <error.h>

#define BUFFERSIZE 512

struct myparams {
    unsigned int r:1, w:1;
    unsigned char *read_file;
    unsigned char *write_file;
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

int readFile(int fd)
{
    char *buffer = (char *)malloc(sizeof(char) * BUFFERSIZE);
    size_t read_bytes = 0;

    while((read_bytes = read(fd, buffer, BUFFERSIZE)) > 0)
    {
        if((write(STDOUT_FILENO, buffer, read_bytes)) < 0)
        {
            perror("write");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

mode_t filemode = S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH;
int write_flags = O_CREAT | O_APPEND | O_WRONLY;
int read_flags = O_RDONLY | O_APPEND;

int main(int argc, char **argv)
{
    struct myparams param = {0,0,"", ""};
    char c = 0;

    while((c = getopt(argc, argv, "r:w:"))!= -1)
    {
        switch(c) {
            case 'r':
                param.r = 1;
                if (optarg) param.read_file = (unsigned char *)optarg;
                break;
            case 'w':
                param.w = 1;
                if (optarg) param.write_file = (unsigned char *)optarg;
                break;
            default:
                error(0,0,"-r <file> -w <file>");
                return EXIT_FAILURE;
        }
        
    }

    if (param.r ^ param.w)
    {
        error(0,0,"-r <file> -w <file>");
        return EXIT_FAILURE;
    }

    printf("Read From File %s and Write in %s", param.read_file, param.write_file);

    int fd_read, fd_write;

    if ((fd_read = open(param.read_file, read_flags, filemode)) < 0)
    {
        perror("open");
    }

    if ((fd_write = open(param.write_file, write_flags, filemode)) < 0)
    {
        perror("open");
    }

    char *buffer = (char *)malloc(sizeof(char) * BUFFERSIZE);
    size_t read_bytes = 0;

    while((read_bytes = read(fd_read, buffer, BUFFERSIZE)) > 0)
    {
        if((write(fd_write, buffer, read_bytes)) < 0)
        {
            perror("write");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}