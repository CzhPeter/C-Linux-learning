#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void b()
{
	printf("I am func b\n");
}

void a(void(*p)())
{
	printf("I am func a\n");
	p();
}

int main()
{
	void (*p)();//p����һ������ָ��
	p = b;
	a(p);
	return 0;
}