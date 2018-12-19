#include <stdio.h>
#include <math.h>

/*
 * 步骤：
 * 1. 计算用于比较的中间值
 * 2. 如果 x 不小于中间值，则取 ceil
 *    如果 x 小于中间值，则取 floor
 */
double myround(double x)
{
	double y = ceil(x) - 0.5;
	if (x >= y) {
		return ceil(x);
	} else {
		return floor(x);
	}
}

int main(void)
{
	double x = 0.25;
	printf("%f after round: %f\n", x, myround(x));
	return 0;
}
