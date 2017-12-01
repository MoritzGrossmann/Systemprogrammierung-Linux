#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <libgen.h>


//Funktioniertt !!!

struct myparam {
	unsigned int u:1, o:1;
	unsigned int min, max;
  };

int isQuadrat(int val) {
	double wurzel = sqrt((double) val);
	if (wurzel - (int) wurzel == 0.0) {
		return 1;
	} else {
		return 0;
	}
}

int main(int argc, char **argv) {

	struct myparam param = {0, 0 , 1, 400}; 
	char c = 0;
	while( (c = getopt(argc, argv, "u:o:")) != -1 )
	{
	   switch(c)
	   {
		 case 'u':
		  param.u = 1;
		  if( optarg ) param.min = atoi(optarg);
		  break;
		 case 'o':
		  param.o = 1;
		  if( optarg ) param.max = atoi(optarg);
		  break;
		default:
			error (0,0, "[-u <min>, -o <max>]");
	   }
	}

	if (param.u ^ param.o) {
		error (0,0, "[-u <min>, -o <max>]");
		return EXIT_FAILURE;
	}
	
	int tmp;

	if (param.min > param.max) {
		tmp = param.min;
		param.min = param.max;
		param.max = tmp;
	}

	printf("Berechnung der Quadratzahlen im Interval [%d, %d]\n", param.min, param.max);

	for (int i = param.min; i <= param.max; i++) {
		if (isQuadrat(i) == 1) {
			printf("%d\n", i);
		}
	}

	return EXIT_SUCCESS;
}
