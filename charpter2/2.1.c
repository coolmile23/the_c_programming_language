#include <stdio.h>
#include <limits.h>

int main(int argc, char **argv)
{
	/* char */
	printf("SIGNED CHAR MIN: %d\n", SCHAR_MIN);
	printf("SIGNED CHAR MAX: %d\n", SCHAR_MAX);
	printf("UNSIGNED CHAR MAX: %u\n", UCHAR_MAX);
	
	/* short */
	printf("SIGNED SHORT MIN: %d\n", SHRT_MIN);
	printf("SIGNED SHORT MAX: %d\n", SHRT_MAX);
	printf("UNSIGNED SHORT MAX: %u\n", USHRT_MAX);

	/* int */
	printf("SIGNED INT MIN: %d\n", INT_MIN);
	printf("SIGNED INT MIN: %d\n", INT_MAX);
	printf("UNSIGNED INT MAX: %u\n", UINT_MAX);

	/* long */
	printf("SIGNED LONG MIN: %ld\n", LONG_MIN);
	printf("SIGNED LONG MAX: %ld\n", LONG_MAX);
	printf("UNSIGNED LONG MAX: %lu\n", ULONG_MAX); 
	
	
	/* get value by caculate */
	printf("signed char min = %d\n", -((char)((unsigned char)~0 >> 1) + 1));
	printf("signed char max = %d\n", (char)((unsigned char)~0 >> 1 ));

	return 0;
}
