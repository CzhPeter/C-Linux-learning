#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[3] = { 2,7,8 };
	int* p;
	int j;
	p = a;
	j = *p++;//��һ�� j=*p; �ڶ��� p++, ��ʱpָ��7�ĵ�ַ
	printf("a[0]=%d,j=%d,*p=%d\n", a[0], j, *p);
	j = p[0]++;//��һ�� j=p[0], ��ʱpָ��7�ĵ�ַ, p[0]Ϊ7; �ڶ��� p[0]++ (p[0] �ȼ��� *p)
	printf("a[0]=%d,j=%d,*p=%d\n", a[0], j, *p);
	return 0;
}