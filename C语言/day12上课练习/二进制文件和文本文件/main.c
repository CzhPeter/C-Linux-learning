#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ı�ģʽ��д��\n���̴洢\r\n����ȡ��\r\n��ʵ���ڴ���\n
//������ģʽ��д��\n������\n
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