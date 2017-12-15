#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

#define MAX 10

int main (int argc, char **argv)
{
    int num = 0;

    while(num++ < MAX) {
        pid_t pid = fork();

        if (pid < 0) perror ("could not fork");
        else if (pid == 0) {
            // Kindeprozess
            printf("Kind nummer %d gestartet\n", num);
            sleep(2);
            printf("Kind nummer %d beenden\n", num);
            exit(EXIT_SUCCESS);
        }
    }

    int status;
    while (num-- > 0) 
    {
        wait(&status);
    }

    printf("Elternprozes beendet\n");

    return EXIT_SUCCESS;
}