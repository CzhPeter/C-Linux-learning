#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const int monday = 1;//const变量使用
	//monday = 3;不可修改
	char str[] = "helloworld";
	const char* p = str;//const修饰char*时，指针指向的空间不可被改变
	str[0] = 'H';
	puts(str);
	//p[1] = 'E';
	puts(p);
	return 0;
}