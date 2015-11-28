#include <stdio.h>
#include <string.h>

#define MAX_LINE 100
#define LINE_80  80
#define LINE_CUT 30	/* how long a line should be */

#define TAB_BIT	 4	/* a tab means how many blank space */

int get_line(char *line, int limit);
int copy_line(char *to, char *from);
void reverse_line(char *line);
int detab(char *line, char *new_line);
int blank2tab(char *line, char *new_line);

int main(int argc ,char **argv)
{
	char line[MAX_LINE];		/* current input line */
	char line_longest[MAX_LINE];	/* longest line saved here */
	char line_no_tab[MAX_LINE * 2]; /* line after delete trailing tab */
	char line_blank2tab[MAX_LINE];  /* line fater change blank space into tab, every TAB_BIT blank equeal to one tab */

	int  line_len = 0;        	/* current line length */
	int  line_len_max = 0;		/* maxinum length seen so far */

	memset(line, '\0', sizeof(line));
	memset(line_longest, '\0', sizeof(line_longest));
	memset(line_no_tab, '\0', sizeof(line_no_tab));
	memset(line_blank2tab, '\0', sizeof(line_blank2tab));

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
//		reverse_line(line);
//		printf("reverse line: %s\n", line);
		
//		detab(line, line_no_tab);
//		printf("delete tab line: %s\n", line_no_tab);

		blank2tab(line, line_blank2tab);
		
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


/* reverse a line */
void reverse_line(char *line)
{
	int iterator = 0;
	int j = 0;
	int temp_char;
	
	while (line[iterator] != '\0') {
		iterator++;
	}
	iterator--;
	
	if (line[iterator] == '\n') {
		iterator--;
	}
	while (iterator > j) {
		temp_char	 = line[j];
		line[j]  	 = line[iterator];
		line[iterator]	 = temp_char;

		iterator--;
		j++;
	}
}

/* delete tab and replace with blank space 
 * return the length of new line
 */
int detab(char *line, char *new_line)
{
	int iterator = 0;
	int i = 0;
	int j = 0;

	while (line[iterator] != '\0') {
		if (line[iterator] == '\t') {
			for (i = 0; i < TAB_BIT; i++) {
				new_line[j++] = ' ';
			}
		} else {
			new_line[j++] = line[iterator];
		}		
		iterator++;
	}
	new_line[j] = '\0';

	return j;
}

/* change blank space to tab with blank space */
int blank2tab(char *line, char *new_line)
{
	int iterator  = 0;	
	int blank_cnt = 0; 	/* blank space counter */
	int j 	      = 0;	/* index of new line */
	int i 	      = 0;	/* for iteration */
	
	while (line[iterator] != '\0') {
		if (line[iterator] == ' ') {
			blank_cnt++;
		} else if (blank_cnt != TAB_BIT) {
			for (i = 0; i < blank_cnt; i++) {
				new_line[j++] = ' ';
			}
			blank_cnt = 0;
			new_line[j++] = line[iterator];
		} 
		if (blank_cnt == TAB_BIT) {
			new_line[j++]  = '\t';
			blank_cnt = 0;
		}
		iterator++;
	}
	
	return 0;
}

/* cut a long line into several short line */
void cut_line(char *line, char *new_line)
{
	int iterator = 0;
	int pos      = 0;	 	/* the position of nearest blank space or tab */
	int char_cnt = 0;		/* character counter */

	while (line[iterator] != '\0') {
		char_cnt++;
		if (line[iterator] == ' ' || line[iterator] == '\t') {
			pos = iterator;			
		}
		if (char_cnt == LINE_CUT) {
			if (line[iterator] == ' ' || line[iterator] == '\t') {
				line[char_cnt] = '\n';
				char_cnt = 0;
			} else {
				line[pos] = '\n';
				
			}
		}
	}	
}
