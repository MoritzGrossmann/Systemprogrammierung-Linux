#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>


struct myparam {
	unsigned int u:1, o:1, p:1;
	unsigned int min, max, precision;
};

void printSqrt(int num, int precision)
{
	printf("%d\tSquareroot: %.*f\n", num, precision, sqrt((float)num));
}

int main (int argc, char **args) {

	struct myparam params = {0,0,0,1,100, 5};

	char c = 0;

	while((c = getopt(argc, args, "o:u:p")) != -1)
	{
		switch(c)
		{
			case 'o':
				params.o = 1;
				if(optarg) params.max = atoi(optarg);
				break; 
			case 'u':
				params.u = 1;
				if (optarg) params.min = atoi(optarg);
			case 'p':
				params.p = 1;
				if (optarg) params.precision = atoi(optarg);
			default:
				error (0,0, "[-u <min>, -o <max>, -p <precisio>]");
		}
	}

	if (params.o ^ params.u)
	{
		error (0,0, "[-u <min>, -o <max>, -p <precision>]");
		return EXIT_FAILURE;
	}

	if (params.u == 0 && params.o == 0)
	{
		printf("no Interval is given. Calculate standard Interval [1,100]\n");
	}

	if (params.p == 0)
	{
		printf("No precision is given. Calculate with standard precision 5\n");
	}

	if (params.min > params.max) {
		int tmp = params.max;
		params.max = params.min;
		params.min = tmp;
	}

	for (int i = params.min; i < params.max; i++) {
		printSqrt(i, params.precision);
	}

	return EXIT_SUCCESS;

}
