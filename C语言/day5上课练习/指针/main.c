#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//指针的本质是做间接访问
int main()
{
	int i = 3;//*&i 等价于 i
	int* p;//int* 定义多个指针方便，如：int* p, p1，否则需要int *p,*p1
	p = &i;//&*p 等价于 p
	printf("i=%d\n", i);//直接访问
	printf("*p=%d\n", *p);//间接访问
	return 0;
}