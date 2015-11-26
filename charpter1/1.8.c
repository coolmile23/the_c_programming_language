#include <stdio.h>

int main(int argc, char **argv)
{
	int c;
	long ccnt = 0;	/* charactor counter */
	long lcnt = 0;  /* line counter */
	long tcnt = 0;  /* table counter */
	long bcnt = 0;  /* blank space counter */
	
	
	while ((c = getchar()) != EOF) {
		ccnt++;
		switch (c) {
			case ' '  : bcnt++; break;
			case '\t' : tcnt++; break;
			case '\n' : lcnt++; break;
			default: break;
		}
	}

	printf("ccnt = %ld\n", ccnt);
	printf("lcnt = %ld\n", lcnt);
	printf("tcnt = %ld\n", tcnt);
	printf("bcnt = %ld\n", bcnt);

	return 0;
}
