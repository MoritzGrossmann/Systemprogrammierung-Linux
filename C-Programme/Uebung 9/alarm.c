#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void handler(int sig) 
{
    int rest = alarm(0);
    printf("%d %s\n", rest, strsignal(sig));
    alarm(rest);
}

int main(int argc, char **argv)
{
    int dauer = 10;

    if (argc > 1) dauer = atoi(argv[1]);

    alarm(dauer);

    struct sigaction act = {handler, 0,0};

    if (sigaction(SIGUSR2, &act, NULL)) perror("sigaction");

    while (1) pause();

    return EXIT_SUCCESS;
}