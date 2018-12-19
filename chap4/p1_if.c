#include <stdio.h>

int main(void)
{
	int x = 3;
	if (3 > 2) {
		printf("3 is bigger than 2\n");
	}
	printf("%d\t%d\n", 15 < 7, -1 > -10);
	if (23) {
		printf("Could run\n");
	}
	if (-29) {
		printf("Could run\n");
	}

	if (x > 0)
		if (x > 10)
			printf("x is bigger than 10\n");
		else
			printf("x is smaller than 10\n");
	return 0;
}
