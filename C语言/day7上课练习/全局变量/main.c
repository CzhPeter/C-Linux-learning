#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int i = 10;//main������ʼ����֮ǰ�͸�ֵ��
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