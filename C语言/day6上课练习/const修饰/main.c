#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const int monday = 1;//const����ʹ��
	//monday = 3;�����޸�
	char str[] = "helloworld";
	const char* p = str;//const����char*ʱ��ָ��ָ��Ŀռ䲻�ɱ��ı�
	str[0] = 'H';
	puts(str);
	//p[1] = 'E';
	puts(p);
	return 0;
}