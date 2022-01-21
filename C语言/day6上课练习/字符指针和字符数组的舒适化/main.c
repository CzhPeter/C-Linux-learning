#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* p = "hello";
	char c[10] = "hello";//相当于strcpy(c, "hello")
	c[0] = 'H';
	//p[0] = 'H';不可以修改字符串常量区，只读的，不可以strcpy
	printf("p=%s\n", p);
	printf("c=%s\n", c);
	p = "world";
	puts(p);
	//c = "world";数组名不可以赋值
	puts(c);
	return 0;
}