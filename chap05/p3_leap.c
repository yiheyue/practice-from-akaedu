#include <stdio.h>

/*
 * 在公历中，年份分为闰年和平年。
 * 闰年一年366天，平年一年365天。
 * 闰年分为普通闰年和世纪闰年。
 * 普通闰年：能被4整除但不能被100整除
 * 世纪闰年：能被400整除
 */
int is_leap_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0) {
		return 1;
	} else if (year % 400 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int main(void)
{
	int year = 100;
	if (is_leap_year(year)) {
		printf("%d is leap.\n", year);
	} else {
		printf("%d is not leap.\n", year);
	}
	return 0;
}
