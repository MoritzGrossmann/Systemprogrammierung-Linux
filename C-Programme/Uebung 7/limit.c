#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(int argc, char **argv) {

    struct rlimit limit;
    if ( getrlimit(RLIMIT_CORE, &limit)) perror ("getrlimit");

    printf("CORE-FILE: %d (cur), %d (max)\n", limit.rlim_cur, limit.rlim_max);

    if ( getrlimit(RLIMIT_CPU, &limit)) perror ("getrlimit");

    printf("CPU: %d (cur), %d (max)\n", limit.rlim_cur, limit.rlim_max);

    return EXIT_SUCCESS;
}