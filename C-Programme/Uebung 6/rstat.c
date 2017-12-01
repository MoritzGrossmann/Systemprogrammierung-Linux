#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print_inode_stats(struct stat *stats, char *dateiname)
{
    printf("Dateiname:\t\t\t%s\n",dateiname);
    printf("Gerätenummer:\t\t\t%ld\n", (long)stats->st_dev);
    printf("I-Node Nummer:\t\t\t%ld\n", (long)stats->st_ino);
    printf("Dateiart und Zugriffsrecht:\t%ld\n", (long)stats->st_mode);
    printf("Anzahl der Links:\t\t%ld\n", (long)stats->st_nlink);
    printf("User-Id:\t\t\t%ld\n", (long)stats->st_uid);
    printf("Group-Id:\t\t\t%ld\n", (long)stats->st_gid);
    printf("Geraetenummer:\t\t\t%ld\n", (long)stats->st_rdev);
    printf("Groesse in Byte:\t\t%ld\n", (long)stats->st_size);
    printf("Optimale Bockgroesse:\t\t%ld\n", (long)stats->st_blksize);
    printf("Anzahl belegter Bloecke:\t%ld\n", (long)stats->st_blocks);
    printf("Letzter Zugriff:\t\t%ld\n", (long)stats->st_atime);
    printf("Letzte Aenderung:\t\t%ld\n", (long)stats->st_mtime);
    printf("Aenderungszeit INode:\t\t%ld\n", (long)stats->st_ctime);

    printf("\n");
}


int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        printf("error: Rstat <Dateipfad>\n");
        return EXIT_FAILURE;
    }

    struct stat stats;
    //ino_t inode_number = stats.st_ino;

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &stats) < 0) perror("stat");
        print_inode_stats(&stats, argv[i]);
    }
    return EXIT_SUCCESS;
}