#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//从1加到100，goto向上跳转
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

//向下跳转，实现部分代码不执行
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

//排除多层循环死循环，从外向内打断点
//while加分号会死循环，for加分号不会死循环

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