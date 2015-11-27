#include <stdio.h>

#define WORD_OUT 0
#define WORD_IN  1

#define WORD_LEN_MAX 10
#define CHARACTOR_NUM_MAX 26

int main(int argc, char **argv)
{
	int c;		/* input charactor */
	int cnt_c = 0;	/* charactor counter */
	int cnt_w = 0;  /* word counter */
	int cnt_l = 0;  /* line counter */

	int status = WORD_OUT;  		 /* initial status is outside word */
	int len_array[WORD_LEN_MAX]; 		 /* array for word length store */
	int word_len = 0;
	
	int c_freq_array[CHARACTOR_NUM_MAX]; 	 /* array for charactors appearence freqence */
	int max_freq = 0;			 /* max freqenency of charactors */
	
	int histogram_top = 0;			/* histogram top */
	
	int iterator = 0;
	for (iterator = 0; iterator < WORD_LEN_MAX; iterator++) {
		len_array[iterator] = 0;
	}
	for (iterator = 0; iterator < CHARACTOR_NUM_MAX; iterator++) {
		c_freq_array[iterator] = 0;
	}

	while ((c = getchar()) != EOF) {
		cnt_c++;
		if (c == '\n') {
			cnt_l++;
		}
		if (c == ' ' || c == '\t' || c == '\n') {
			status = WORD_OUT;	
			if (word_len > 0) {
				len_array[word_len]++;
			}
			word_len = 0;
		} else { 
			word_len++;
			c_freq_array[c - 'a']++;
			if (status == WORD_OUT) {
				cnt_w++;
				status = WORD_IN;	
			}
		}
	}

	/* get the max frequency of charactors */
	for (iterator = 0; iterator < CHARACTOR_NUM_MAX; iterator++) {
		if (c_freq_array[iterator] > max_freq) {
			max_freq = c_freq_array[iterator];
		}
	}

	printf("\n");
	printf("charactors: %d\n", cnt_c);
	printf("words	  : %d\n", cnt_w);
	printf("lines	  : %d\n", cnt_l);

	printf("\n\n\n-----------------------------------\n\n\n");
	/* print word horizontal histogram */
	printf("frequency of word length:\n\n");
	printf("word length\tfrequency\n");
	int i = 0;
	for (iterator = 0; iterator < WORD_LEN_MAX; iterator++) {
		printf("%d:\t\t%d|", iterator, len_array[iterator]);
		for (i = 0; i < len_array[iterator]; i++) {
			printf("#");
		}
		printf("\n");	
	}
	
	printf("\n\n\n-----------------------------------\n\n\n");
	/* print charactor horizontal histogram */
	printf("charactors frequency of appearence\n\n");
	printf("charactors\tfrequency\n");
	for (iterator = 0; iterator < CHARACTOR_NUM_MAX; iterator++) {
		printf("%c:\t\t%d|", iterator + 'a', c_freq_array[iterator]);
		for (i = 0; i < c_freq_array[iterator]; i++) {
			printf("#");
		}
		printf("\n");
	}

	printf("\n\n\n-----------------------------------\n\n\n");
	/* print word vertical histogram */
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
	
	/* print charactors vertical histogram */
	printf("\n\n\n-----------------------------------\n\n\n");
	histogram_top = max_freq + 5; /* 5 charactors higher than max_freq */
	for (iterator = histogram_top; iterator > 0; iterator--) {
		for (i = 0; i < CHARACTOR_NUM_MAX; i++) {
			if (c_freq_array[i] + 1 == iterator) {
				printf("%-2d", c_freq_array[i]);
			} else if (c_freq_array[i] >= iterator) {
				printf("# ");
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
	for (iterator = 0; iterator < CHARACTOR_NUM_MAX; iterator++) {
		printf("%c ", iterator + 'a');
	}
	printf("\n");
	for (iterator = 0; iterator < CHARACTOR_NUM_MAX; iterator++) {
		printf("--");
	}
	printf("\n");
	

	return 0;	
}
