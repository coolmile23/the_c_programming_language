#include <stdio.h>

#define LOWER 0.0f
#define UPPER 300.0f
#define STEP  10

/* print Fahrenheit-Celsius table */
int main(int argc, char **argv)
{
	float fahr, celsius;

	LOWER = 0.0f;
	UPPER = 300.0f;
	STEP  = 10;

	if (argc > 1) {
		printf("Usage:\n");
		printf("./a.out	-i	print out in invert order.\n");
		/* in invert order */
		printf("Temperature Exchange:\n");
		if (strcmp(argv[1], "-i") == 0) {
			for (fahr = UPPER; fahr > LOWER; fahr = fahr - STEP) {
				celsius = (fahr - 32.0f) * 5.0 / 9.0;	
				printf("%6.2f\t%6.2f\n", fahr, celsius);
			}	
			
		}
	} else {
		printf("Temperature Exchange:\n");
		for (fahr = LOWER; fahr < UPPER; fahr = fahr + STEP) {
			celsius = (fahr - 32.0f) * 5.0 / 9.0;	
			printf("%6.2f\t%6.2f\n", fahr, celsius);
		}	
	}

	return 0;	
}
