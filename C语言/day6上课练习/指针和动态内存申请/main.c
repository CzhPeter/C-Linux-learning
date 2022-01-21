#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;//使用多少字节空间
	char* p;
	scanf("%d", &n);//读取要申请空间的大小
	p = (char*)malloc(n);//malloc分配的就是堆空间
	strcpy(p, "hello");
	puts(p);
	free(p);//p不能偏移，必须是最初malloc返回的地址
	p = NULL;
	return 0;
}