#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void squeeze(char *s1, char *s2);

int main(int argc, char **argv)
{
	char *s = NULL;

	if (argc != 3) {
		printf("usage: ./a.out string word\n");
		return 0;
	}	

	s = malloc(strlen(argv[1]) + 1);		
	if (s == NULL) {
		printf("malloc error!\n");
		return -1;
	}

	memcpy(s, argv[1], strlen(argv[1]));
	squeeze(s, argv[2]);
	
	printf("after squeeze:\n%s\n", s);

	free(s);
	return 0;
}


void squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i = k = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++) {
			;
		}

		if (s2[j] == '\0') {
			s1[k++]	= s1[i];
		}
	}
	s1[k] = '\0';
}
//void squeeze(char *s1, char *s2)
//{
//	int i = 0;	/* index of s1 */
//	int j = 0;	/* index of s2 */
//	int iterator = 0;
//	int index = 0;
//
//	int k = 0;	
//
//	char buf[100];
//	
//	printf("strlen(s1) = %d\n", strlen(s1));
//
//	printf("sizeof(buf) = %d\n", strlen(buf));
//	memset(buf, '\0', 20);	/* store the processed string */
//	
//	int s2_len = 0;
//	
//	/* counting the length of delete word */
//	while (s2[i] != '\0') {
//		i++;
//	}
//	s2_len = i;
//
//	i = 0;
//	while (s1[i] != '\0') {
//		if (s2[0] == s1[i]) {
//			for (k = 0; k < s2_len; k++) {
//				if (s1[i + k] != s2[j + k]) {
//					break;
//				}
//			}
//			if (k == s2_len) {
//				i = i + s2_len;
//				j = 0;
//				k = 0;
//				continue;
//			}
//		} 
//		for (iterator = 0; iterator <= k; iterator++) {
//			buf[index + iterator] = s1[i + iterator];
//			index++;
//		}
//		i = i + 1 + k;
//		j = 0;
//	}
//	buf[i] = '\0';
//
//	memcpy(s1, buf, 100);
//}
