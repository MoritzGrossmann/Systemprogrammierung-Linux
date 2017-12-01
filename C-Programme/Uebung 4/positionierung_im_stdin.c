#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    fprintf(stderr, "Positionierung in stdin");
    if (lseek(STDIN_FILENO, 0l, SEEK_CUR) == -1)
    {
        fprintf(stderr, " geht nicht\n");
    } else {
        fprintf(stderr, " ist möglich\n");
    }

    return EXIT_SUCCESS;
}