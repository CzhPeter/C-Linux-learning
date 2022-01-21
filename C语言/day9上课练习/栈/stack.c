#include "stack.h"

//初始化栈
void init_stack(pStack stack)
{
	stack->phead = NULL;
	stack->size = 0;
}

//弹栈
void pop(pStack stack)
{
	if (!stack->phead)
	{
		printf("stack is empty\n");
		return;
	}
	//头部删除法
	pNode pcur = stack->phead;
	stack->phead = pcur->next;
	free(pcur);
	pcur = NULL;
}

//进栈
void push(pStack stack, int val)
{
	pNode pnew = (pNode)calloc(1, sizeof(Node));
	pnew->m_ival = val;
	if (NULL == stack->phead)//头插法
	{
		stack->phead = pnew;
	}
	else {
		pnew->next = stack->phead;
		stack->phead = pnew;
	}
	stack->size++;
}

//只是拿栈顶元素不弹栈
int top(pStack stack)
{
	if (!stack->phead)
	{
		printf("stack is empty\n");
		return -1;
	}
	return stack->phead->m_ival;
}

//判空
int isEmpty(pStack stack)
{
	if (!stack->phead)
	{
		return 1;
	}
	else {
		return 0;
	}
}

//返回栈大小
int size(pStack stack)
{
	return stack->size;
}