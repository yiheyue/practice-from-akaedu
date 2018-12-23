#include <stdio.h>

void print_time(int hour, int minute)
{
	printf("Time\t%d : %d\n", hour, minute);
}

int main(void)
{
	print_time(21, 6);
	return 0;
}
