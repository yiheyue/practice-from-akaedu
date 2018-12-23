#include <stdio.h>

void newline(void)
{
	printf("\n");
}

int main(void)
{
	printf("First line.\n");
	newline();
	printf("Second line.\n");
	return 0;
}
