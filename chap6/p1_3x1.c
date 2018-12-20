#include <stdio.h>

/*
 * 给定一个值 n
 * 1. 如果 n 为偶数，将其除以 2
 * 2. 如果 n 为奇数，将其乘以 3 再加 1
 */
int main(void)
{
	int n = 1;
	while (n != 1) {
		if (n % 2 == 0) {
			n = n / 2;
		} else {
			n = n * 3 + 1;
		}
	}
	return 0;
}
