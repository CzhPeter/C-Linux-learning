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
	pNode phead;//栈顶指针(链表头)
	int size;//栈中元素个数
}Stack, *pStack;

void init_stack(pStack stack);
void pop(pStack stack);
void push(pStack stack, int val);
int top(pStack stack);
int isEmpty(pStack stack);
int size(pStack stack);