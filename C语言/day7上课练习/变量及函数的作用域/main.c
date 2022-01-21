#include <stdio.h>

static int k = 10;//static修饰全局变量，该变量不能被其他文件借用
int main()
{
	int i = 10;
	{
		int j = 5;
	}
	printf("i=%d,k=%d\n", i, k);
	print();
	print();
	return 0;
}