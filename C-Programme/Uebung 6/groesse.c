#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_stats(struct stat *stats, char *dateiname)
{
    printf("Dateiname:\t%s\nGroesse in Byte:\t%ld\nBelegte Bloecke:\t%ld\n\n",dateiname, (long)stats->st_size, (long)stats->st_blocks);
}

int main (int argc, char **argv) 
{
    if (argc < 2) 
    {
        printf("error: Groesse <Dateipfad>\n");
        return EXIT_FAILURE;
    }

    struct stat stats;

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &stats) < 0) perror("stat");
        print_stats(&stats, argv[i]);
    }
    
    return EXIT_SUCCESS;
}