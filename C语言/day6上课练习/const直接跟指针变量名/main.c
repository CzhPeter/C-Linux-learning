#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[] = "helloworld";
	char str1[] = "how do you do";
	//const char *p;pָ������ݲ�����p���޸�
	char* const p = str;//p��������ָ�������ط�, �����ܶ�p�ٴθ�ֵ
	p[0] = 'H';
	puts(p);
	return 0;
}