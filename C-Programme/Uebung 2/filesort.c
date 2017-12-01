#include <stdio.h>
#include <stdlib.h>

int comapare( const void *p1, const void *p2) {
	return *(char *)p1 - *(char *)p2; 
}


int main (int argc, char **argv) {
	*FILE file = fopen(argv[1], "r");
	if (fp == NULL) {perror("fopen"); exit(EXIT_FAILURE);}

	usigned long filesize = 0;
	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *buffer = (char *) malloc(filesize * sizeof(char));
	long i = 0;
	while(i < filesize) {
		buffer[i++] = fgetc(fp);
	}
	
	qsort(buffer, (size_t) filesize, sizeof(char), &compare);
	printf("%s\n", buffer);
	free(buffer);
	fclose(fp);

	return EXIT_SUCCESS;
}
