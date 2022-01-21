#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct tag
{
	int m_ival;
	struct tag* next;
}Node, *pNode;

typedef struct tagstack
{
	pNode phead;//ջ��ָ��(����ͷ)
	int size;//ջ��Ԫ�ظ���
}Stack, *pStack;

void init_stack(pStack stack);
void pop(pStack stack);
void push(pStack stack, int val);
int top(pStack stack);
int isEmpty(pStack stack);
int size(pStack stack);