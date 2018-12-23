#include <stdio.h>

int main(void)
{
	// Truncate toward zero
	int a = -25;
	int b = 24;
	int result;

	result = a / b;
	printf("Result: %d\n", result);
	return 0;
}
