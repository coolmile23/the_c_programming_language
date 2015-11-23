#include <stdio.h>

#define ERR_TYPE -2

int hex2int(char *hex_str);

int main(int argc, char **argv)
{
	char *string = "0xffff";	
	int  num     = 0;

	num = hex2int(string);

	printf("num = %d\n", num);

	return 0;
}

int hex2int(char *hex_str)
{
	int i = 0;
	int num = 0;

	if (hex_str[i++] != '0' && (hex_str[i] != 'x' || hex_str[i] != 'X')) {
		printf("please input a hexdecimal  string.\n");
		return ERR_TYPE;
	}
	i = 2;
	while (hex_str[i] != '\0') {
		if (hex_str[i] >= '0' && hex_str[i] <= '9') {
			num = num * 16 + hex_str[i] - '0';
		} else if (hex_str[i] >= 'A' && hex_str[i] <= 'Z') {
			num = num * 16 + hex_str[i] - 'A' + 10;
		} else if (hex_str[i] >= 'a' && hex_str[i] <= 'z') {
			num = num * 16 + hex_str[i] - 'a' + 10;
		} else {

		}
		i++;
	}

	return num;
}
