#include <stdio.h>
#include <stdlib.h>


#define N 5
//指针的偏移
int main()
{
	int a[N] = { 1,2,3,4,5 };
	int* p;//指针每次加1，是加sizeof(int)大小
	p = a;
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%3d", *(p+i));
	}
	putchar('\n');
	p = &p[4];
	for (i = 0; i < N; i++)//逆序输出
	{
		printf("%3d", *(p - i));
	}
	putchar('\n');
	return 0;
}