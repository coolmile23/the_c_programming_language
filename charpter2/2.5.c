#include <stdio.h>

int any(char s1[], char s2[]);

int main(int argc, char **argv)
{
	int pos = 0;

	pos = any("helloworld", "ow");
	
	printf("pos = %d\n", pos);

	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;
	
	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				return i;
			}
		}
	}

	return (-1);
}
