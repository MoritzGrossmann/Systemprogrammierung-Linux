#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 512

int main (int argc, char **argv) {

    int flags = O_CREAT | O_WRONLY | O_APPEND;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;  //0664;

    int *files = (int *)malloc(sizeof(int) * (argc - 1));

    for (int i = 0; i < argc - 1; i++) {
        if ((files[i] = open(argv[i+1], flags, mode)) == -1) {
            perror("open");
            return EXIT_FAILURE;
        }
    }

    int standardeingabe = STDIN_FILENO;     //Filedeskriptor für Standardeingabe
    int standardausgabe = STDOUT_FILENO;    //Filedeskriptor für Standardausgabe

    char *eingabe;
    eingabe = (char *)malloc(sizeof(char) * BUFFER_SIZE);


    size_t readBytes;
    readBytes = read(standardeingabe, eingabe, BUFFER_SIZE);

    while (readBytes != 0) {

        // In Standardausgabe Schreiben

        if (write(standardausgabe, eingabe, readBytes) == -1) {
            perror("write");
            return EXIT_FAILURE;
        }

        for (int j = 0; j < argc-1; j++) {

            //In alle Übergebenen Dateien schreiben

            if (write(files[j], eingabe, readBytes) == -1) {
                perror("write");
                return EXIT_FAILURE;
            }
        }

        readBytes = read(standardeingabe, eingabe, BUFFER_SIZE);
    }

    for (int k = 0; k < argc -1; k++) {
        close(files[k]);
    }
    return EXIT_SUCCESS;
}