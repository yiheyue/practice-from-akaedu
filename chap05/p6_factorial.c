#include <stdio.h>

int factorial(int n)
{
	if (n == 0) {
		return 1;
	} else {
		int recurse = factorial(n - 1);
		int result = n * recurse;
		return result;
	}
}

int main(void)
{
	int n = 3;
	printf("%d! = %d\n", n, factorial(n));
	return 0;
}
