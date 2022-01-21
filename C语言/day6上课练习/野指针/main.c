#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//野指针就是申请的空间被释放后，没有将指针赋值为NULL，该指针就是野指针
int main()
{
	int* p1, * p2, * p3;
	p1 = (int*)malloc(4);
	*p1 = 1;
	p2 = (int*)malloc(4);
	*p2 = 2;
	free(p1);
	p1 = NULL;
	p3 = (int*)malloc(4);
	*p3 = 3;
	printf("*p3=%d\n", *p3);
	*p1 = 100;//这里会报错，如果p1不等于NULL就不会报错
	printf("*p3=%d\n", *p3);
	return 0;
}