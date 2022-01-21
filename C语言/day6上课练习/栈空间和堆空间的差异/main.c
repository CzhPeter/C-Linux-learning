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
	p = print_stack();//数据存放在栈空间
	puts(p);//print_stack函数执行完后栈空间即释放，因此打印有异常，出现乱码
	p = print_malloc();//数据存放在堆空间
	puts(p);//打印正常，因为堆空间不free就不会释放
	return 0;
}