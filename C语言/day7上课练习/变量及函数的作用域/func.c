#include "func.h"

int k;
void print()//static ���κ��������Ա�����ļ�����
{
	static int t = 0;
	t++;
	printf("print execute %d\n", t);
	printf("print k=%d\n", k);
}