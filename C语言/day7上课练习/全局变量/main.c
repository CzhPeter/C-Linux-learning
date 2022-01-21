#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int i = 10;//main函数开始运行之前就赋值了
void print()
{
	printf("print i = %d\n", i);
}

int main()
{
	printf("main i=%d\n", i);
	print();
	return 0;
}