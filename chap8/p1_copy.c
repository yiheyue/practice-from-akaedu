#include <stdio.h>

int main(void)
{
	int src[8] = { 23, 64, 128, 20, -102, 2, 0, 11 };
	int dest[8];
	int i;
	for (i = 0; i < 8; i++) {
		printf("src[%d]: %d\n", i, src[i]);
	}
	for (i = 0; i < 8; i++) {
		dest[i] = src[i];
	}
	printf("\n");
	for (i = 0; i < 8; i++) {
		printf("dest[%d]: %d\n", i, dest[i]);
	}
	return 0;
}
