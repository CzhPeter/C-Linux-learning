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
	char buf[128];
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		printf("光标所在位置%ld\n", ftell(fp));
		printf("%s", buf);
	}
	fclose(fp);
	return 0;
}