#include <stdio.h>

int global;

int main(void)
{
	int local;
	printf("Local: %d\n", local);
	printf("Global: %d\n", global);
	return 0;
}
