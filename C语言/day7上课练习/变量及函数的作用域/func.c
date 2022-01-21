#include "func.h"

int k;
void print()//static 修饰函数不可以被别的文件调用
{
	static int t = 0;
	t++;
	printf("print execute %d\n", t);
	printf("print k=%d\n", k);
}