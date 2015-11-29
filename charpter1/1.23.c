#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_LINE 	1000 + 1
#define LINE_80  	80
#define MAX_COL 	20	/* max column of input */

#define COMMENT_IN	1	/* a flag about if character posion is in a comment */
#define COMMENT_OUT	0	/* out of comment */

#define TAB_BIT	 	4	/* a tab means how many blank space */

#define ERR_MALLOC	-3
#define ERR_OPEN	-4

int get_line(char *line, int limit);
int copy_line(char *to, char *from);
void reverse_line(char *line);
int detab(char *line, char *new_line);
int blank2tab(char *line, char *new_line);
void cut_line(char *line, char *new_line);
int delete_comment(char *line);
int get_line_from_file(char *buf, char *path, long num);

int main(int argc ,char **argv)
{
	char line[MAX_LINE];		/* current input line */
	char line_longest[MAX_LINE];	/* longest line saved here */
	char line_no_tab[MAX_LINE * 2]; /* line after delete trailing tab */
	char line_blank2tab[MAX_LINE];  /* line after change blank space into tab, every TAB_BIT blank equeal to one tab */
	char line_cut[MAX_LINE];	/* line after cut into several short line */

	int  line_len = 0;        	/* current line length */
	int  line_len_max = 0;		/* maxinum length seen so far */

	memset(line, '\0', sizeof(line));
	memset(line_longest, '\0', sizeof(line_longest));
	memset(line_no_tab, '\0', sizeof(line_no_tab));
	memset(line_blank2tab, '\0', sizeof(line_blank2tab));
	memset(line_cut, 0xcc, sizeof(line_cut));

//	while ((line_len = get_line(line, MAX_LINE)) > 0) {
//		if (line_len > line_len_max) {
//			copy_line(line_longest, line);
//			line_len_max = line_len;
//		}
/*		if (remove_line(line) > 0) {
			printf("line: %s\n", line);
		} else {
			continue;
		}
*/
//		reverse_line(line);
//		printf("reverse line: %s\n", line);
		
//		detab(line, line_no_tab);
//		printf("delete tab line: %s\n", line_no_tab);

//		blank2tab(line, line_blank2tab);
		
/*		cut_line(line, line_cut);
		printf("line cut:\n%s\n", line_cut);
		printf("line:\n%s\n", line);
*/
		/* print out the line longer than 80 */
/*		if (line_len > LINE_80) {
			printf("%d\t%s\n", line_len, line);
		}
*/
//		
//	}
	if (get_line_from_file(line, "1.23.c", 1000) < 0) {
		printf("get line fail.\n");
		return -1;
	}
	printf("line: %s\n", line);

	delete_comment(line);
	printf("line: %s\n", line);
	
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
		if (char_cnt == MAX_COL) {
			printf("char count = %d\n", char_cnt);
			char_cnt = 0;
			pos = iterator;
			printf("pos = %d\tline[pos] = %c\n", pos, line[pos]);
			if (line[iterator] == ' ' || line[iterator] == '\t') {
				while (line[pos] == ' ' || line[pos] == '\t') {
					pos--;
				}
				pos++;
				*(line + pos) = '\n';
			} else  if (line[iterator + 1] == ' ' || line[iterator + 1] == '\t') { /* just the end of word  */
				*(line + iterator + 1) = '\n';
			} else {
				while (line[pos] != ' ' && line[pos] != '\t') {
					pos--;
				}	
				while (line[pos] == ' ' || line[pos] == '\t') {
					pos--;
				}
				pos++;
				*(line + pos) = '\n';
			}
		} 
		iterator++;
	}	
}

/* delete comment in a string 
 * return 0 if delete success
 * else return a negtive value 
 */
int delete_comment(char *line)
{
	int iterator = 0;
	int j = 0;	/* index of new line */
	char *new_line = NULL;
	char *p_comment_start = NULL;
	char *p_comment_end   = NULL;

	int status = COMMENT_OUT;

	if ((new_line = malloc(strlen(line) + 1)) == NULL) {
		printf(__FUNCTION__, "malloc failure.\n");
		return ERR_MALLOC;
	}
	
	while (line[iterator] != '\0') {
		if (line[iterator] == '/' && line[iterator + 1] == '*' || line[iterator] == '/' && line[iterator + 1] == '/') { /* find the start of comment */
			status = COMMENT_IN;
			*(new_line + j) = ' ';
			j++;
		} else if (line[iterator] == '/' && line[iterator - 1] == '*') {
			status = COMMENT_OUT;	
		} else if (status == COMMENT_IN && line[iterator] == '\n') {
			status = COMMENT_OUT;	
		} else if (status == COMMENT_OUT){
			*(new_line + j) = line[iterator];
			j++;
			status = COMMENT_OUT;
		} 
		iterator++;
	}

	memcpy(line, new_line, j);
	line[j] = '\0';

	free(new_line);

	return 0;
}

/* read num bytes from file */
int get_line_from_file(char *buf, char *path, long num)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) < 0) { /* if open fail, -1 returned  */
		printf("open fail.\n");	
		return ERR_OPEN;
	}
	
	while (read(fd, buf, num) > 0) {
		;
	}

	close(fd);
	return 0;
}
