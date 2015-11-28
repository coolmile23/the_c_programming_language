#include <stdio.h>

float temp_exchange(float fahrenheit);

int main(int argc, char **argv)
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step  = 10;

	for (fahr = lower; fahr < upper; fahr = fahr + step) {
		celsius = temp_exchange(fahr);	
		printf("%d\t%d\n", fahr, celsius);
	}	

	return 0;	
}

float temp_exchange(float fahrenheit)
{
	return (fahrenheit - 32) * 5 / 9;
}
