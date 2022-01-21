#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//文本模式，写入\n磁盘存储\r\n；读取到\r\n，实际内存是\n
//二进制模式，写入\n，就是\n
int main(int argc, char* argv[])
{
	FILE* fp;
	fp = fopen("file.txt", "w+");
	if (NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	fwrite("hello\nworld", sizeof(char), 11, fp);
	fseek(fp, -8, SEEK_CUR);
	char buf[128] = { 0 };
	fread(buf, sizeof(char), sizeof(buf), fp);
	fclose(fp);
	return 0;
}