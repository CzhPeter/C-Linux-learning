#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

char* print_stack()
{
	char c[17] = "I am print_stack";
	puts(c);
	return c;
}

char* print_malloc()
{
	char* p;
	p = (char*)malloc(20);
	strcpy(p, "I am print_malloc");
	puts(p);
	return p;
}

int main()
{
	char* p;
	p = print_stack();//���ݴ����ջ�ռ�
	puts(p);//print_stack����ִ�����ջ�ռ伴�ͷţ���˴�ӡ���쳣����������
	p = print_malloc();//���ݴ���ڶѿռ�
	puts(p);//��ӡ��������Ϊ�ѿռ䲻free�Ͳ����ͷ�
	return 0;
}