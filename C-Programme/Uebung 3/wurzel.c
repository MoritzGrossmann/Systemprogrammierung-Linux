#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **args) {
	if (argc != 4){ 
		printf("Wurzel muss aufgerufen werden mit den parametern min max precision!!\n");
		return 1; 
	}
	
	int precision = atoi(args[1]);
	int min = atoi(args[2]);
	int max = atoi(args[3]);

	if (min > max) {
		printf("Minimum muss größer sein als Maximunm!!\n");
		return 1;
	}

	for (int i = min; i < max; i++) {
		printf("%d \t %.*f\n", i, precision, sqrt((float)i));
	}

	return 0;

}
