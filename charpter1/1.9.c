#include <stdio.h>

#define BLANK_Y 1
#define BLANK_N 0

/* print out the input, and 
replace multi blank space with one*/
int main(int argc, char **argv)
{
	int c;
	int lastc = BLANK_N; /* is last charactor is blank */
	
	while ((c = getchar()) != EOF) {
/* 	version 1
		if (c == ' ') {
			if (lastc == BLANK_N) {
				putchar(c);
			}
			lastc = BLANK_Y;
		} else {
			putchar(c);
			lastc = BLANK_N;
		}
*/

/*	version 2
		if (c != ' ') {
			putchar(c);
		} else if (lastc != ' ') {
			putchar(c);
		}
		lastc = c;	
*/
/*	vertion 3*/
		if (c != ' ' || lastc != ' ') {
			putchar(c);	
		}
		lastc = c;
	}

	return 0;
}
