#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[] = "helloworld";
	char str1[] = "how do you do";
	//const char *p;p指向的内容不能用p来修改
	char* const p = str;//p不可以再指向其他地方, 即不能对p再次赋值
	p[0] = 'H';
	puts(p);
	return 0;
}