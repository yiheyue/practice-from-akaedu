#include <stdio.h>

enum coordinate_type { RECTANGULAR, POLAR };

struct complex_struct {
	enum coordinate_type t;
	double a;
	double b;
};

int main(void)
{
	return 0;
}
