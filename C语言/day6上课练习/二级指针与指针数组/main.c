#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char** p)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		puts(p[i]);
	}
}

int main()
{
	char* p[5];
	char b[5][10] = { "lele", "fenghua", "java", "python", "c" };
	int i, j;
	char** p2 = (char**)malloc(20);//动态的指针数组
	for (i = 0; i < 5; i++)
	{
		p2[i] = b[i];//p[0]是字符指针类型, b[0]是一维字符数组的数组名

	}
	for (i = 0; i < 5; i++)
	{
		puts(p2[i]);
	}
	//p2 = p;//&p[0]--p内部所存储的指针类型是二级指针
	char* ptmp;
	for (i = 4; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (strcmp(p2[j], p2[j + 1]))
			{
				ptmp = p2[j];
				p2[j] = p2[j + 1];
				p2[j + 1] = ptmp;
			}
		}
	}
	printf("-------------\n");
	print(p2);//有序的字符串
	return 0;
}