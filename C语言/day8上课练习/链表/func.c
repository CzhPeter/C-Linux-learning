#include "func.h"

//ͷ�巨
void list_head_insert(LinkList *pphead, LinkList **pptail, ElemType i)
{
	LinkList pnew = (LinkList)malloc(sizeof(LNode));//����һ���ṹ���С�ռ�
	pnew->num = i;
	pnew->pnext = NULL;
	//�������Ϊ�գ��½����ͷ���(Ҳ�������һ�����)
	if (NULL == *pphead)
	{
		*pphead = pnew;//�½����Ϊͷ��㣬ҲΪβ���
		*pptail = pnew;
	}
	else {
		pnew->pnext = *pphead;//�½��ָ��ԭ����ͷ��(ͷ�巨)
		*pphead = pnew;
	}
}

//β�巨
void list_tail_insert(LinkList* pphead, LinkList* pptail, ElemType i)
{
	LinkList pnew = (LinkList)malloc(sizeof(LNode));//����һ���ṹ���С�ռ�
	pnew->num = i;
	pnew->pnext = NULL;
	//�������Ϊ�գ��½����ͷ���(Ҳ�������һ�����)
	if (NULL == *pphead)
	{
		*pphead = pnew;//�½����Ϊͷ��㣬ҲΪβ���
		*pptail = pnew;
	}
	else {
		(*pptail)->pnext = pnew;//�½�㸳ֵ��βָ���pnext
		*pptail = pnew;
	}
}

//��ӡ����
void list_print(LinkList phead)
{
	while (phead != NULL)
	{
		printf("%3d %5.2f\n", phead->num, phead->score);
		phead = phead->pnext;
	}
	printf("\n");
}

//�������(��֤��������)
void list_sort_insert(LinkList* pphead, LinkList* pptail, ElemType i)
{
	LinkList pnew = (LinkList)calloc(1, sizeof(LNode));//calloc�������Ŀռ�ȫ����ʼ��Ϊ0
	pnew->num = i;
	LinkList pcur, ppre;
	pcur = ppre = *pphead;//pcur��ppre��ָ������ͷ��
	//�������Ϊ�գ��½����ͷ���(Ҳ�������һ�����)
	if (NULL == *pphead)
	{
		*pphead = pnew;//�½����Ϊͷ��㣬ҲΪβ���
		*pptail = pnew;
	}
	else if (pnew->num < pcur->num)//���뵽ͷ��
	{
		pnew->pnext = *pphead;//�½��ָ��ԭ����ͷ��
		*pphead = pnew;
	}
	else {
		while (pcur)//���뵽�м�
		{
			if (pnew->num < pcur->num)
			{
				ppre->pnext = pnew;
				pnew->pnext = pcur;
				return;
			}
			ppre = pcur;
			pcur = pcur->pnext;
		}
		//������뵽�м䣬��return
		(*pptail)->pnext = pnew;
		*pptail = pnew;
	}
}

//����ɾ��
void list_delete(LinkList* pphead, LinkList* pptail, ElemType i)
{
	LinkList pcur, ppre;
	pcur = ppre = *pphead;
	if (!pcur)
	{
		printf("list is empty");
		return;
	}
	//���ɾ������ͷ��
	if (i == pcur->num)
	{
		*pphead = pcur->pnext;
		if (NULL == *pphead)
		{
			*pptail = NULL;//���ɾ���������һ����㣬βָ����ΪNULL
		}
		free(pcur);
		pcur = NULL;
	}
	else {//ɾ���м��β��
		while (pcur)
		{
			if (i == pcur->num)
			{
				ppre->pnext = pcur->pnext;
				free(pcur);
				break;
			}
			ppre = pcur;
			pcur = pcur->pnext;
		}
		if (NULL == ppre->pnext)//����ɾ������β���
		{
			*pptail = ppre;
		}
		if (NULL == pcur)
		{
			printf("�����ڸý��");
			return;
		}
		pcur = NULL;
	}
}

//�����޸�
void list_modify(LinkList phead, ElemType i, float score)
{
	while (phead)
	{
		if (i == phead->num)
		{
			phead->score = score;
			break;
		}
		phead = phead->pnext;
	}
	if (NULL == phead)
	{
		printf("û�иý��\n");
	}
}