#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Es muss 1 Argument übergeben werden!\n");
        return EXIT_FAILURE;
    }

    char *file = argv[1];
    char current;
    char *buffer = (char *)malloc(sizeof(char));
    int flags = O_RDONLY, fd;

    int linesize = 0;

    if ((fd = open(file, flags)) == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    if (lseek(fd, -1l, SEEK_END) == -1)
    {
        perror("lseek");
    }

    while(read(fd, &current, 1) > 0)
    {
        if (current == '\n') 
        {
            buffer = (char *)realloc(buffer, linesize);

            size_t read_bytes = read(fd, buffer, linesize);
            write(STDOUT_FILENO, buffer, read_bytes);

            lseek(fd, -(linesize+1), SEEK_CUR); //Zum ende der nächsten Zeile Springen
            linesize = 0;
            current = '\n';
            write(STDOUT_FILENO, &current, 1);
        } else 
        {
            linesize++;
        }

        if (lseek(fd, -2l, SEEK_CUR) == -1) 
        {
            break;
        }
    }

    linesize = 0;


    //Erste Zeile vom Dokument ausgeben 
    lseek(fd, 0l, SEEK_SET);
    while(read(fd, &current, 1) > 0)
    {
        if (current == '\n'){
            break;
        }
        write(STDOUT_FILENO, &current, 1);
    }
    return EXIT_SUCCESS;
}