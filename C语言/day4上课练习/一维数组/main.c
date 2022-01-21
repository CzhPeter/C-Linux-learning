#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print_arr(int a[], int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("a[%d]=%d\t", i, a[i]);
	}
}

int main()
{
	int j = 10;
	int a[5] = { 1,2,3,4,5 };
	int i = 17;
	/*a[5] = 6;
	a[6] = 7;
	a[7] = 8;
	printf("j=%d", j);*/
	print_arr(a, 5);
	return 0;
}