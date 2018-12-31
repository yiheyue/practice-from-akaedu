#include <stdio.h>

typedef struct {
	unsigned int one:1;
	unsigned int two:2;
	unsigned int three:10;
	unsigned int four:5;
	unsigned int :2;
	unsigned int five:8;
	unsigned int six:8;
} demo_type;

int main(void)
{
	demo_type s = { 1, 5, 513, 17, 129, 0x81 };
	printf("sizeof demo_type = %u\n", sizeof(demo_type));
	printf("Name	Value\n");
	printf("-------------\n");
	printf("one	%u\n", s.one);
	printf("two	%u\n", s.two);
	printf("three	%u\n", s.three);
	printf("four	%u\n", s.four);
	printf("five	%u\n", s.five);
	printf("six	%u\n", s.six);
	return 0;
}
