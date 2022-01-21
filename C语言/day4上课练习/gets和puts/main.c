#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c[20];
	gets(c);//gets把缓冲区的\n读走了
	puts(c);// printf("%s\n", c);
	return 0;
}