#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isquadrat(int a) {
	float teiler = sqrt((float)a);
	if (a / teiler == teiler) {
	       return 1;
	} else {
 		return 0;
	}		
}

int main(int argc, char **argv) {
	
	int min = 1;
       	int max = 200;

	if (argc == 3) {
		min = atoi(argv[1]);
		max = atoi(argv[2]);
	} else {
		perror("Übergabeparameter sollten <min> <max> sein, Standardmäßig wird min = 1 und max = 200 verwendet!");
	}

	for (int i = min; i <= max; i++) {
		if (isquadrat(i) == 1) {
			printf("%d\n", i);
		}	
	}	
	return EXIT_SUCCESS;
}
