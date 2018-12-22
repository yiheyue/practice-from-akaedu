#include <stdio.h>

int main(void)
{
	int i;
	char str[6] = "hello";
	char reverse_str[6] = "";

	printf("%s\n", str);
	/*
	 * str[]	 0  1  2  3  4  5
	 * 		 h  e  l  l  o  \0
	 * reverse_str[] 0  1  2  3  4  5
	 * 		 \0 o  l  l  e  h
	 */
	for (i = 0; i < 5; i++) {
		reverse_str[5 - i] = str[i];
	}
	printf("%s\n", reverse_str);
	return 0;
}
