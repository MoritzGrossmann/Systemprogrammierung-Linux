#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int flags = O_RDONLY, fd;
    
    if ( (fd = open("/dev/null", flags) < 0))
    {
        perror("open");
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}