#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* fp;
	fp = fopen("file.txt", "r+");
	if (NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	char buf[128] = "how are you";
	fwrite(buf, sizeof(char), strlen(buf), fp);
	fseek(fp, 0, SEEK_SET);//让光标偏移到开头(windows要求在读写之间必须刷新位置指针)
	memset(buf, 0, sizeof(buf));
	int ret;
	ret = fread(buf, sizeof(char), sizeof(buf), fp);
	puts(buf);
	fclose(fp);
	return 0;
}