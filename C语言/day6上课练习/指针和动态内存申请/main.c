#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;//ʹ�ö����ֽڿռ�
	char* p;
	scanf("%d", &n);//��ȡҪ����ռ�Ĵ�С
	p = (char*)malloc(n);//malloc����ľ��Ƕѿռ�
	strcpy(p, "hello");
	puts(p);
	free(p);//p����ƫ�ƣ����������malloc���صĵ�ַ
	p = NULL;
	return 0;
}