#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <unistd.h>

struct opt {
    int days;
    int hours;
    int minutes;
    int seconds;
}

int main (int argc, char **argv) {
    struct opt opts = (0);
    char c;
    while ((c = getopt(argc, argv, "d::h::m::s::")) >= 0) {
        switch(opt)
        {
            case 'd':
                if( c ) opts.days = atoi(c);
                break;
            case 'h':
                if( c ) opts.hours = atoi(c);
                break;
            case 'm':
                if( c ) opts.minutes = atoi(c);
                break;
            case 's':
                if( c ) opts.seconds = atoi(c);
                break;
            case '?':
                printf("%s -x[0-9]+ -y -z\n", basename(argv[0]));
                //abort();
        }
    }
}