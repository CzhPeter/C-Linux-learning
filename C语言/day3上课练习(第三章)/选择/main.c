#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//int i;
	//while (scanf("%d", &i) != EOF)
	//{
	//	if (i > 0)//if后面括号不能加分号，会造成语句体任何时候都会执行
	//	{
	//		printf("i is bigger than 0\n");
	//	}
	//	else {
	//		printf("i is not bigger than 0\n");
	//	}
	//}
	int mon, year;
	while (scanf("%d%d", &year, &mon) != EOF)
	{
		switch (mon)
		{
		case 2:printf("mon=%d is %d days\n", mon, 28 + (year % 4 == 0 && year % 100 != 0 || year % 400 == 0));
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:printf("mon=%d is 31 days\n", mon);
			break;
		case 4:
		case 6:
		case 9:
		case 11:printf("mon=%d is 30 days\n", mon);
		default:
			printf("error mon\n");
		}
	}
	return 0;
}