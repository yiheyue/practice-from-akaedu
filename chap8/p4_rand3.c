#include <stdio.h>
#include <stdlib.h>

int gen_rand(int lower_bound, int upper_bound)
{
	int result;
	do {
		result = rand() % upper_bound;
	} while (result < lower_bound);
	return result;
}

int main(void)
{
	int a[20];
	int i;
	for (i = 0; i < 20; i++) {
		a[i] = gen_rand(10, 20);
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
