#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char c;
	float f;
	double d;//double������scanf��Ҫ��%lf��ȡ
	int ret;
	ret = scanf("%d %c%f%lf", &i, &c, &f, &d);//%c֮ǰ����Ҫ�пո�
	printf("i=%d, c=%c, f=%f, d=%f\n", i, c, f, d);
	return 0;
}