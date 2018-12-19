#include <stdio.h>

int main(void)
{
	int cond = 3;
	switch (cond) {
	case 1:
		printf("cond 1\n");
		break;
	case 2:
		printf("cond 2\n");
		break;
	case 3:
		printf("cond 3\n");
		break;
	case 4:
		printf("cond 4\n");
		break;
	default:
		printf("default cond\n");
	}
	return 0;
}
