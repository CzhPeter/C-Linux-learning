#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct student
{
	int num;
	char name[20];
	char sex;
}stu, * pstu;

typedef int ELEMTYPE;
//��Ҫ�ñ������ͽṹ����������
int main()
{
	stu s = { 101 };
	pstu p;
	ELEMTYPE i;
	p = &s;
	printf("%d %s %c\n", p->num, p->name, p->sex);
	return 0;
}