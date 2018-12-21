#include <stdio.h>

int main(void)
{
	char first = "Hello"[0];
	printf("%c\n", first);

	char str[] = "Hello world.\n";
	printf("%s", str);
	return 0;
}
