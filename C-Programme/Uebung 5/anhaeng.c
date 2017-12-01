#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 512

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Es müssen 2 Argumente übergeben werden!\n");
        return EXIT_FAILURE;
    }

    char *first = argv[1];
    char *second = argv[2];

    int flags1 = O_RDONLY;
    int flags2 = O_CREAT | O_WRONLY | O_APPEND;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;  //0664;

    int fd1, fd2;

    if ((fd1 = open(first, flags1)) == -1 )
    {
        perror("open");
        return EXIT_FAILURE;
    }
    if ((fd2 = open(second, flags2, mode)) == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    size_t read_bytes = read(fd1, buffer, BUFFER_SIZE);

    while(read_bytes > 0)
    {
        if (write(fd2, buffer, read_bytes) == -1) {
            perror("write");
            return EXIT_FAILURE;
        }

        read_bytes = read(fd1, buffer, BUFFER_SIZE);
    }

    return EXIT_SUCCESS;
}