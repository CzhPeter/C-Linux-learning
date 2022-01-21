#include <stdio.h>

union data   //共用体
{
	int i;
	char ch;
	float f;
};

enum weekday  //枚举
{
	sun, mon, feb, wed, thu, fri, sat
};

int main()
{
	union data a;//共用体也叫联合体
	enum weekday workday;
	a.i = 10;
	a.ch = 'm';
	a.f = 98.2;
	workday = wed;
	if (workday == wed)
	{
		printf("wed=%d\n", wed);
	}
	return 0;
}