#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//ָ��ı���������ӷ���
int main()
{
	int i = 3;//*&i �ȼ��� i
	int* p;//int* ������ָ�뷽�㣬�磺int* p, p1��������Ҫint *p,*p1
	p = &i;//&*p �ȼ��� p
	printf("i=%d\n", i);//ֱ�ӷ���
	printf("*p=%d\n", *p);//��ӷ���
	return 0;
}