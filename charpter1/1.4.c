#include <stdio.h>

int main(int argc, char **argv)
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step  = 10;

	for (fahr = lower; fahr < upper; fahr = fahr + step) {
		celsius = (fahr - 32) * 5 / 9;	
		printf("%d\t%d\n", fahr, celsius);
	}	

	return 0;	
}
