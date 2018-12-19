#include <stdio.h>
#include <math.h>

void print_log(double x)
{
	if (x <= 0.0) {
		printf("positive number, please\n");
		return;
	}
	printf("log(%f): %f\n", x, log(x));
}

int main(void)
{
	print_log(0);
	return 0;
}
