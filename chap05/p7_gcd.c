#include <stdio.h>

/*
 * 最大公约数（GCD，Greatest Common Divisor），Euclid 算法：
 * 1. 如果 a 除以 b 能整除，则最大公约数是 b。
 *    否则，最大公约数是 b 和 a%b 的最大公约数。
 */
int get_gcd(int a, int b)
{
	if (a % b == 0) {
		return b;
	} else {
		return get_gcd(b, a % b);
	}
}

int main(void)
{
	int a = -16;
	int b = -3;
	printf("The GCD between %d and %d is %d.\n", a, b, get_gcd(a, b));
	return 0;
}
