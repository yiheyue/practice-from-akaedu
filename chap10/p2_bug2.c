#include <stdio.h>

int main(void)
{
	int sum = 0;
	int i = 0;
	char input[5];

	while (1) {
		printf("Please input a number: ");
		scanf("%s", input);
		for (i = 0; input[i] != '\0'; i++) {
			sum = sum * 10 + input[i] - '0';
		}
		printf("input=%d\n", sum);
	}
	return 0;
}
