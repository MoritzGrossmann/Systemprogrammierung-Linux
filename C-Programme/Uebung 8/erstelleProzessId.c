#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    pid_t parent, self, pid;

    if ((pid = fork()) < 0) perror("could not fork");
    else if (pid) // Elternprozess
    {
        printf("Elternprozess:\t");
        parent = getppid();
        self = getpid();

        printf("ppid %d, pid %d, kind: %d\n", parent, self, pid);

        // Um Zombies zu verhindern

        wait();

    } else {
        printf("Kindprozess:\t");
        parent = getppid();
        self = getpid();
        
        printf("ppid %d, pid %d\n", parent, self);
    }

    return EXIT_SUCCESS;
}