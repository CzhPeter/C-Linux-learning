#include <stdio.h>
#include <stdlib.h>


#define N 5
//ָ���ƫ��
int main()
{
	int a[N] = { 1,2,3,4,5 };
	int* p;//ָ��ÿ�μ�1���Ǽ�sizeof(int)��С
	p = a;
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%3d", *(p+i));
	}
	putchar('\n');
	p = &p[4];
	for (i = 0; i < N; i++)//�������
	{
		printf("%3d", *(p - i));
	}
	putchar('\n');
	return 0;
}