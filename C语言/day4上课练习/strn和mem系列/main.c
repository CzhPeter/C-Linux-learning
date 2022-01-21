#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char c[100] = { 0 };
	strncpy(c, "helloworld", 5);
	puts(c);
	//memset(c, 0, sizeof(c));//内存设置接口
	strncpy(c, "howareyou", 3);//strncpy不会读取结束符
	//c[3] = '\0';
	puts(c);
	printf("strncmp=%d\n", strncmp("xiongda", "xionger", 5));
	strncat(c, "do you do, lily", 9);//添加9个字符到c里
	puts(c);
	return 0;
}