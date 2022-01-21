#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 250000

//当使用的栈空间超出了单个函数的占空间，会发生stack overflow异常
int main()
{
	int a[N] = { 0 };
	return 0;
}