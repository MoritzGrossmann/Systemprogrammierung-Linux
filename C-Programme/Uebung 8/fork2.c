#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main (int argc, char **argv)
{
    int num = 0;

    while (num++ < MAX) {
        pid_t pid = fork();
        if (pid < 0) perror ("could not fork");
        else if (pid == 0) {

        } else {
            // Elternprozess
            printf("Eltern %d warten auf ihre Kinder\n", num);
            wait();
            exit(EXIT_SUCCESS);
        }
    }
            
    printf("Urenkel %d beendet\n", num);
    wait();

    return EXIT_SUCCESS;
}