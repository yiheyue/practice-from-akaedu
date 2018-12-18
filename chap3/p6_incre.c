#include <stdio.h>

/* Because of call by value */
void increment(int x)
{
	x = x + 1;
}

int main(void)
{
	int i = 1;
	int j = 2;
	
	increment(i);
	increment(j);

	printf("i: %d\tj: %d\n", i, j);

	return 0;
}
