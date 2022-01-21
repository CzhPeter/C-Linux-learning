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
	void (*p)();//p就是一个函数指针
	p = b;
	a(p);
	return 0;
}