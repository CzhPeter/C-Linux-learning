#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 4 + 5 * 2 - 20 / 2 % 3;
	int num = 1234;
	printf("i=%d\n", i);
	while (num)
	{
		printf("%d", num % 10);
		num = num / 10;
	}
	printf("\n");
	//用加减法交换2个数，不用第三个变量
	int a = 3, b = 6;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d%d", a, b);
	return 0;
}