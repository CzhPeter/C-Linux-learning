#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//二维数组的传递
void print_arr(int a[][4], int row)//a是形参，row是形参
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < sizeof(a[0])/sizeof(int); j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	a[1][2] = 20;
}

int main()
{
	int a[3][4] = { 1,3,5,7,2,4,6,8,11,13,15,17 };
	print_arr(a, 3);
	printf("a[1][2]=%d", a[1][2]);
	return 0;
}