#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* p = "hello";
	char c[10] = "hello";//�൱��strcpy(c, "hello")
	c[0] = 'H';
	//p[0] = 'H';�������޸��ַ�����������ֻ���ģ�������strcpy
	printf("p=%s\n", p);
	printf("c=%s\n", c);
	p = "world";
	puts(p);
	//c = "world";�����������Ը�ֵ
	puts(c);
	return 0;
}