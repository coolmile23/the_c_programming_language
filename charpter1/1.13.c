#include <stdio.h>

#define WORD_OUT 0
#define WORD_IN  1

#define WORD_LEN_MAX 10

int main(int argc, char **argv)
{
	int c;		/* input charactor */
	int cnt_c = 0;	/* charactor counter */
	int cnt_w = 0;  /* word counter */
	int cnt_l = 0;  /* line counter */

	int status = WORD_OUT;   /* initial status is outside word */
	int len_array[WORD_LEN_MAX]; /* array for word length store */
	int word_len = 0;
	
	int iterator = 0;
	for (iterator = 0; iterator < WORD_LEN_MAX; iterator++) {
		len_array[iterator] = 0;
	}

	while ((c = getchar()) != EOF) {
		cnt_c++;
		if (c == '\n') {
			cnt_l++;
		}
		if (c == ' ' || c == '\t' || c == '\n') {
			status = WORD_OUT;	
			if (word_len) {
				len_array[word_len]++;
				word_len = 0;
			}
		} else { 
			word_len++;
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

	/* print horizontal histogram */
	int i = 0;
	for (iterator = 0; iterator < WORD_LEN_MAX; iterator++) {
		printf("%d:\t%d|", iterator, len_array[iterator]);
		for (i = 0; i < len_array[iterator]; i++) {
			printf("#");
		}
		printf("\n");	
	}
	

	printf("\n\n\n-----------------------------------\n\n\n");
	/* print vertical histogram */
	for (iterator = WORD_LEN_MAX; iterator > 0; iterator--) {
		for (i = 0; i < WORD_LEN_MAX; i++) {
			if (len_array[i] + 1 == iterator) {
				printf("%-2d", len_array[i]);
			} else if (len_array[i] >= iterator) {
				printf("# ");
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
	for (iterator = 0; iterator < WORD_LEN_MAX; iterator++) {
		printf("%d ", iterator);
	}
	printf("\n");
	for (iterator = 0; iterator < WORD_LEN_MAX; iterator++) {
		printf("--");
	}
	printf("\n");
	

	return 0;	
}
