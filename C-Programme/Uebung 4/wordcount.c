#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

struct myparams {
    unsigned int f:1, s:1;
    char *file;
};

struct fileProperties {
    unsigned int digits;
    unsigned int words;
    unsigned int lines;
};

int isDigit(char c) {
    int val = (int)c;

    if ((val > 64 && val < 91) || (val > 96 && val < 123)) {
        return 1;
    } else {
        return -1;
    }
}

int isNewLine(char c) {
    if (c == '\n') {
        return 1;
    } else {
        return -1;
    }
}

struct fileProperties analyseFile(int fd) {
    char *buffer = (char *)malloc(sizeof(char));
    char current;
    char last = '.';

    struct fileProperties properties = {0,0,0};

    size_t readBytes;
    readBytes = read(fd, buffer, 1);
    while (readBytes > 0) {
        current = buffer[0];
        if (isDigit(current) > 0) {
            properties.digits++;
        } else {
            if (isNewLine(current) > 0 || (current == EOF && last != '\n')) {
                properties.lines++;
            }
            if (isDigit(current) < 0 && isDigit(last) > 0) {
                properties.words++;
            }
        }
        last = current;
        readBytes = read(fd, buffer, 1);
    }

    close(fd);
    return properties;
}

int main(int argc, char **argv) {
    struct myparams param = {0, (char *)""};

    char c;
    while( (c = getopt(argc, argv, "f:s")) != -1 )
	{
	   switch(c)
	   {
		 case 'f':
		  param.f = 1;
		  if( optarg ) param.file = optarg;
          break;
        case 's':
		  param.s = 1;
		  break;
		default:
            error (0,0, "[-f <file>, -s]");
            return EXIT_FAILURE;
	   }
    }

    if (param.s == param.f) {
        error (0,0, "[-f <file> or -s]");
        return EXIT_FAILURE;
    }

    int flags = O_RDONLY;
    struct fileProperties result;
    int fd;

    if (param.f > 0) {
        if ((fd = open(param.file, flags)) < 0) {
            perror("open");
            return EXIT_FAILURE;
        } else {
            printf("Datei %s wird ausgelesen\n", param.file);   
        }
    } else if (param.s > 0){
        printf("Standardeingabe wird ausgelesen!\n");
        fd = STDIN_FILENO;
    }


    result = analyseFile(fd);
    printf("Anzahl Buchstaben: %d\nAnzahl Wörter: %d\nAnzahl Zeilen: %d\n", result.digits, result.words, result.lines);

    return EXIT_SUCCESS;
}