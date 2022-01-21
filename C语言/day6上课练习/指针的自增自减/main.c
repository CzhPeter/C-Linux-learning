#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[3] = { 2,7,8 };
	int* p;
	int j;
	p = a;
	j = *p++;//第一步 j=*p; 第二步 p++, 此时p指向7的地址
	printf("a[0]=%d,j=%d,*p=%d\n", a[0], j, *p);
	j = p[0]++;//第一步 j=p[0], 此时p指向7的地址, p[0]为7; 第二步 p[0]++ (p[0] 等价于 *p)
	printf("a[0]=%d,j=%d,*p=%d\n", a[0], j, *p);
	return 0;
}