#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ReadWriteOpen.h>

int writeInFile(int fd, char *data)
{
    int length = strlen(data);
    if ((int written = write(fd, data, legth)) < 0)
    {
        perror("write");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
