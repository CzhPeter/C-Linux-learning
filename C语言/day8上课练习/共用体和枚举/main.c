#include <stdio.h>

union data   //������
{
	int i;
	char ch;
	float f;
};

enum weekday  //ö��
{
	sun, mon, feb, wed, thu, fri, sat
};

int main()
{
	union data a;//������Ҳ��������
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