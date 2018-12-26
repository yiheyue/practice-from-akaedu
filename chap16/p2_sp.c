#include <stdio.h>

int main(void)
{
	int a = 0;
	a = (++a) + (++a) + (++a) + (++a);
	printf("a: %d\n", a);
}
