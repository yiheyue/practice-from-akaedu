#include <stdio.h>
#include <math.h>

double distance(double x1, double x2,
	       	double y1, double y2)
{
	double dx = x2 - x1;
	double dy = y2 - y1;
	// printf("%f, %f\n", dx, dy);
	double dsquare = dx * dx + dy * dy;
	// printf("%f\n", dsquare);
	double result = sqrt(dsquare);
	// printf("%f\n", result);
	return result;
}

double area(double r)
{
	double result = 3.14 * r * r;
	return result;
}

int main(void)
{
	printf("area: %f\n", area(distance(0.0, 0.0, 4.0, 0.0)));
	return 0;
}
