#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	//argc是给exe传参的个数，包含exe本身
	int i;
	for (i = 0; i < argc; i++)//argv[i]是执行每一个参数
	{
		puts(argv[i]);
	}
	FILE* fp;
	fp = fopen(argv[1], "r+");
	if (NULL == fp)//如果fp为NULL，代表打开失败
	{
		perror("fopen");
		return -1;
	}
	int ret;
	//ret = fputc('H', fp);
	//if (-1 == ret)
	//{
	//	perror("fputc");//Bad file descriptor代表没有写权限
	//}
	char c;
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	fclose(fp);//关闭文件
	return 0;
}