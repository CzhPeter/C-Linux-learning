#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char c;
	float f;
	double d;//double类型在scanf中要用%lf读取
	int ret;
	ret = scanf("%d %c%f%lf", &i, &c, &f, &d);//%c之前必须要有空格
	printf("i=%d, c=%c, f=%f, d=%f\n", i, c, f, d);
	return 0;
}