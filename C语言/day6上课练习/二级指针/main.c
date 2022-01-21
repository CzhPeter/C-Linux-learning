#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//二级指针用于在子函数中去修改主函数中某一个一级指针变量的值
void change(int** pi, int* pj)
{
	*pi = pj;
}

int main()
{
	int i = 10;
	int j = 5;
	int* pi = &i;
	int* pj = &j;
	printf("i=%d,j=%d,*pi=%d,*pj=%d\n", i, j, *pi, *pj);
	change(&pi, pj);
	printf("i=%d,j=%d,*pi=%d,*pj=%d\n", i, j, *pi, *pj);
	return 0;
}