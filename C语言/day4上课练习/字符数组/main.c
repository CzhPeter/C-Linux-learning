#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print_str(char c[])
{
	int i = 0;
	while (c[i])
	{
		printf("%c", c[i]);
		i++;
	}
	printf("\n");
}

//�������ڴ�����������ʼ��ַ
//%s����ַ���ʱ����һֱ�ң�ֱ������������'\0'
//scanf %s��ȡ�ַ���ʱ����Կո��\n
int main()
{
	char c[10];
	char d[10];
	scanf("%s%s", c, d);//�ӱ�׼�����ȡһ���ַ������ַ�������
	printf("%s----%s\n", c, d);//%s���ʱ��������Ҫ������һ���ַ�������ʼ��ַ
	print_str(c);
	return 0;
}