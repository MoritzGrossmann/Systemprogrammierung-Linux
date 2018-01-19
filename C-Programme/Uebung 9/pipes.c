#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

void handler(int sig)
{
    printf("cought signal: %s\n", strsignal(sig));
}

int main(int argc, char **argv)
{
    struct sigaction act = {handler, 0};
    sigaction(SIGPIPE, &act, NULL);

    int fd[2];

    if(pipe(fd)) perror("pipe");

    char *str = "I am writing a text t oa pipe, which is buffered in kernel\n";

    int len = strlen(str);

    if (len != write(fd[1], str, len)) perror("write");

    char buf[len];

    buf[0] = 0;

    if (len != read(fd[0], str, len)) perror("read");

    printf("%s", buf);

    return EXIT_SUCCESS;
}