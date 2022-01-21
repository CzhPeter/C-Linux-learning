#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char c[100];
	char d[100];
	while (gets(c) != NULL)
	{
		printf("strlen=%d\n", strlen(c));//strlen不计空字符
		strcpy(d, c);//c中的字符串copy给d
		puts(d);
		printf("strcmp=%d\n", strcmp("how", "hello"));
		strcat(d, "hello");
		puts(d);
	}
	return 0;
}