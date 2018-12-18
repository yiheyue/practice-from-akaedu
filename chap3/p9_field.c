#include <stdio.h>

int hour = 24;

void print_hour(void)
{
	printf("Hour: %d\n", hour);
}

int main(void)
{
	int hour = 12;
	printf("Hour: %d\n", hour);
	print_hour();
	return 0;
}
