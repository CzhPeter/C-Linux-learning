#include "stack.h"

//��ʼ��ջ
void init_stack(pStack stack)
{
	stack->phead = NULL;
	stack->size = 0;
}

//��ջ
void pop(pStack stack)
{
	if (!stack->phead)
	{
		printf("stack is empty\n");
		return;
	}
	//ͷ��ɾ����
	pNode pcur = stack->phead;
	stack->phead = pcur->next;
	free(pcur);
	pcur = NULL;
}

//��ջ
void push(pStack stack, int val)
{
	pNode pnew = (pNode)calloc(1, sizeof(Node));
	pnew->m_ival = val;
	if (NULL == stack->phead)//ͷ�巨
	{
		stack->phead = pnew;
	}
	else {
		pnew->next = stack->phead;
		stack->phead = pnew;
	}
	stack->size++;
}

//ֻ����ջ��Ԫ�ز���ջ
int top(pStack stack)
{
	if (!stack->phead)
	{
		printf("stack is empty\n");
		return -1;
	}
	return stack->phead->m_ival;
}

//�п�
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

//����ջ��С
int size(pStack stack)
{
	return stack->size;
}