#include <stdio.h>

int is_even(int x)
{
	return !(x % 2);
}

int main(void)
{
	int x = 21;
	if (is_even(x)) {
		printf("%d is even\n", x);
	} else {
		printf("%d is odd\n", x);
	}
	return 0;
}
