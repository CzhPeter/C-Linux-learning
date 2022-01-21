#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//char c;
	//c = getchar();//从缓冲区中读取一个字符
	//putchar(c);//输出一个字符
	//putchar('\n');
	//%后面加数字是占用几个位置，默认右对齐，负号是左对齐
	printf("Hello %-10s,age=%-2d\n", "Bob", 20);
	printf("Hello %-10s,age=%-2d\n", "Xiongda", 5);
	printf("float=%0.2f\n", 98.5);
	return 0;
}