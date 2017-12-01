#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <error.h>

int main(int argc, char **argv) 
{
	for (int i = 0; i < 10; i++) {
		errno = 1;
		error_at_line(0, i, __FILE__, __LINE__, "Fehlernummer: %i", i);
	}
	return EXIT_SUCCESS;
}
