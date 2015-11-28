#include <stdio.h>
#include <string.h>

#define MAX_LINE 100
#define LINE_80  80

int get_line(char *line, int limit);
int copy_line(char *to, char *from);

int main(int argc ,char **argv)
{
	char line[MAX_LINE];		/* current input line */
	char line_longest[MAX_LINE];	/* longest line saved here */

	int  line_len = 0;        	/* current line length */
	int  line_len_max = 0;		/* maxinum length seen so far */

	memset(line, '\0', sizeof(line));
	memset(line_longest, '\0', sizeof(line_longest));

	while ((line_len = get_line(line, MAX_LINE)) > 0) {
		if (line_len > line_len_max) {
			copy_line(line_longest, line);
			line_len_max = line_len;
		}
		if (remove_line(line) > 0) {
			printf("line: %s\n", line);
		} else {
			continue;
		}
		/* print out the line longer than 80 */
/*		if (line_len > LINE_80) {
			printf("%d\t%s\n", line_len, line);
		}
*/
	}
	
	if (line_len_max > 0) {
		printf("longest line: %d\n%s\n", line_len_max, line_longest);
	}
	
	return 0;
}

int get_line(char *line, int limit)
{
	int iterator = 0;
	int c;

	int j = 0; /* for line index */
	for (iterator = 0; /*iterator < limit - 1 &&*/ (c = getchar()) != EOF && c != '\n'; iterator++) {
		if (j < limit - 2 ) {
			line[j] = c;
			j++;
		}
	}
	if (c == '\n') {
		line[j] = c;
		j++;
		iterator++;
	}
	line[j] = '\0';

	return iterator;
}

int copy_line(char *to, char *from)
{
	int iterator = 0;

/*	while (from[iterator] != '\0') {
		to[iterator] = from[iterator];
		iterator++;
	}
*/
	while ((to[iterator] = from[iterator++]) != '\0')
	to[iterator] = '\0';
}

/* remove the trailing balnks and tabs from character string line */
int remove_line(char *line)
{
	int iterator = 0;
	
	while (line[iterator] != '\n') {
		iterator++;
	}
	iterator--;
	while (iterator >= 0) {
		if (line[iterator] == ' ' || line[iterator] == '\t') {
			iterator--;
		} else {
			break;
		}
	}
	if (iterator >= 0) {
		line[++iterator] = '\n';
		line[++iterator] = '\0';
	}
	
	return iterator;
}
