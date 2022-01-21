#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c, max1;
	while (scanf("%d%d%d", &a, &b, &c) != EOF)
	{
		max1 = (a > b ? a : b) > c ? (a > b ? a : b) : c;
		printf("max=%d\n", max1);
	}
	return 0;
}