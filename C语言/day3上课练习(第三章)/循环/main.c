#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//��1�ӵ�100��goto������ת
//int main()
//{
//	int i = 1, total = 0;
//lable:
//	total = total + i;
//	i++;
//	if (i <= 100)
//	{
//		goto lable;
//	}
//	printf("total=%d\n", total);
//	return 0;
//}

//������ת��ʵ�ֲ��ִ��벻ִ��
//int main()
//{
//	int disk = 0;
//	if (0 == disk)
//	{
//		goto label_disk_error;
//	}
//	printf("I am writing disk\n");
//label_disk_error:
//	printf("disk error\n");
//	return 0;
//}

//�ų����ѭ����ѭ�����������ڴ�ϵ�
//while�ӷֺŻ���ѭ����for�ӷֺŲ�����ѭ��

int main()
{
	int i, total = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
		{
			continue;
		}
		total += i;
	}
	printf("total=%d\n", total);
	return 0;
}