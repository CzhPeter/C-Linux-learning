#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	//argc�Ǹ�exe���εĸ���������exe����
	int i;
	for (i = 0; i < argc; i++)//argv[i]��ִ��ÿһ������
	{
		puts(argv[i]);
	}
	FILE* fp;
	fp = fopen(argv[1], "r+");
	if (NULL == fp)//���fpΪNULL�������ʧ��
	{
		perror("fopen");
		return -1;
	}
	int ret;
	//ret = fputc('H', fp);
	//if (-1 == ret)
	//{
	//	perror("fputc");//Bad file descriptor����û��дȨ��
	//}
	char c;
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	fclose(fp);//�ر��ļ�
	return 0;
}