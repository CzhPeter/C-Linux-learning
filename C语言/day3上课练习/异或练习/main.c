#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[7] = { 8,9,2,6,2,9,8 };
	int result = 0;
	int i;
	for (i = 0; i < 7; i++)
	{
		result = result ^ arr[i];
	}
	printf("result=%d", result);
	return 0;
}