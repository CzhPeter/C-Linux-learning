#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//c�����βε�λ�ò��ܳ���&����Ϊc���Բ�֧������
void change(int *j)//j���β�  j=&i
{
	*j = 5;//��ӷ���
}

//ָ�봫�ݵ�ʹ�ó���
int main() 
{
	int i = 10;
	printf("before change i=%d\n", i);
	change(&i);//i��ʵ�Σ�ʵ�θ�ֵ���βεĹ��̣�ʵ�ο����Ǳ���
	printf("after change i=%d\n", i);
	return 0;
}