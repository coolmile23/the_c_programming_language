#include <stdio.h>

#define WORD_OUT 0
#define WORD_IN  1

int main(int argc, char **argv)
{
	int cnt_c = 0;	/* charactor counter */
	int cnt_w = 0;  /* word counter */
	int cnt_l = 0;  /* line counter */
	int c;		/* input charactor */
	int status = WORD_OUT; /* initial status is outside word */

	while ((c = getchar()) != EOF) {
		cnt_c++;
		if (c == '\n') {
			cnt_l++;
		}
		if (c == ' ' || c == '\t' || c == '\n') {
			status = WORD_OUT;	
			printf("\n");
		} else { 
			putchar(c);
			if (status == WORD_OUT) {
				cnt_w++;
				status = WORD_IN;	
			}
		}
	}

	printf("\n");
	printf("charactors: %d\n", cnt_c);
	printf("words	  : %d\n", cnt_w);
	printf("lines	  : %d\n", cnt_l);

	return 0;	
}
