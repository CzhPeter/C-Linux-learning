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
	char** p2 = (char**)malloc(20);//��̬��ָ������
	for (i = 0; i < 5; i++)
	{
		p2[i] = b[i];//p[0]���ַ�ָ������, b[0]��һά�ַ������������

	}
	for (i = 0; i < 5; i++)
	{
		puts(p2[i]);
	}
	//p2 = p;//&p[0]--p�ڲ����洢��ָ�������Ƕ���ָ��
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
	print(p2);//������ַ���
	return 0;
}