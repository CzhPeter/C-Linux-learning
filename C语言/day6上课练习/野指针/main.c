#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//Ұָ���������Ŀռ䱻�ͷź�û�н�ָ�븳ֵΪNULL����ָ�����Ұָ��
int main()
{
	int* p1, * p2, * p3;
	p1 = (int*)malloc(4);
	*p1 = 1;
	p2 = (int*)malloc(4);
	*p2 = 2;
	free(p1);
	p1 = NULL;
	p3 = (int*)malloc(4);
	*p3 = 3;
	printf("*p3=%d\n", *p3);
	*p1 = 100;//����ᱨ�����p1������NULL�Ͳ��ᱨ��
	printf("*p3=%d\n", *p3);
	return 0;
}