#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = -1;
	int j;
	j = i++ > -1;
	//j = ++i > -1;
	printf("i=%d,j=%d\n", i, j);
	j = !++i;
	printf("i=%d,j=%d,sizeof(i)=%d\n", i, j, sizeof(i));
	return 0;
}