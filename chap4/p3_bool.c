#include <stdio.h>

int main(void)
{
	int x = 10;
	if (x > 0 && x < 100) {
		printf("x is bigger than 0 and smaller than 100.\n");
	}

	if (x > 20 || x < 30) {
		printf("x is bigger than 20 or smaller than 30.\n");
	}

	if (!x) {
		printf("I will never be printed.\n");
	}
	return 0;
}
