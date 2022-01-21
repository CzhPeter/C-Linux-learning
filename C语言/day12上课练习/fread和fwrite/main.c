#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* fp;
	fp = fopen("F:\\C&Linux\\day12上课练习\\fread和fwrite\\file.txt", "r+");
	if (NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	char buf[128] = { "how are you" };
	int ret;
	//ret = fread(buf, sizeof(char), sizeof(buf), fp);
	//puts(buf);
	//int i = 123456;
	//ret = fwrite(&i, sizeof(int), 1, fp);写一个整型文件
	int i = 0;
	ret = fread(&i, sizeof(int), 1, fp);
	printf("i=%d", i);
	fclose(fp);
	return 0;
}