#include <stdio.h>

static int k = 10;//static����ȫ�ֱ������ñ������ܱ������ļ�����
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