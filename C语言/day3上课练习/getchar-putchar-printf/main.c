#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//char c;
	//c = getchar();//�ӻ������ж�ȡһ���ַ�
	//putchar(c);//���һ���ַ�
	//putchar('\n');
	//%�����������ռ�ü���λ�ã�Ĭ���Ҷ��룬�����������
	printf("Hello %-10s,age=%-2d\n", "Bob", 20);
	printf("Hello %-10s,age=%-2d\n", "Xiongda", 5);
	printf("float=%0.2f\n", 98.5);
	return 0;
}