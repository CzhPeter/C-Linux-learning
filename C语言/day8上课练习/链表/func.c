#include "func.h"

//头插法
void list_head_insert(LinkList *pphead, LinkList **pptail, ElemType i)
{
	LinkList pnew = (LinkList)malloc(sizeof(LNode));//申请一个结构体大小空间
	pnew->num = i;
	pnew->pnext = NULL;
	//如果链表为空，新结点是头结点(也是链表第一个结点)
	if (NULL == *pphead)
	{
		*pphead = pnew;//新结点作为头结点，也为尾结点
		*pptail = pnew;
	}
	else {
		pnew->pnext = *pphead;//新结点指向原来的头部(头插法)
		*pphead = pnew;
	}
}

//尾插法
void list_tail_insert(LinkList* pphead, LinkList* pptail, ElemType i)
{
	LinkList pnew = (LinkList)malloc(sizeof(LNode));//申请一个结构体大小空间
	pnew->num = i;
	pnew->pnext = NULL;
	//如果链表为空，新结点是头结点(也是链表第一个结点)
	if (NULL == *pphead)
	{
		*pphead = pnew;//新结点作为头结点，也为尾结点
		*pptail = pnew;
	}
	else {
		(*pptail)->pnext = pnew;//新结点赋值给尾指针的pnext
		*pptail = pnew;
	}
}

//打印链表
void list_print(LinkList phead)
{
	while (phead != NULL)
	{
		printf("%3d %5.2f\n", phead->num, phead->score);
		phead = phead->pnext;
	}
	printf("\n");
}

//有序插入(保证链表有序)
void list_sort_insert(LinkList* pphead, LinkList* pptail, ElemType i)
{
	LinkList pnew = (LinkList)calloc(1, sizeof(LNode));//calloc会把申请的空间全部初始化为0
	pnew->num = i;
	LinkList pcur, ppre;
	pcur = ppre = *pphead;//pcur和ppre都指向链表头部
	//如果链表为空，新结点是头结点(也是链表第一个结点)
	if (NULL == *pphead)
	{
		*pphead = pnew;//新结点作为头结点，也为尾结点
		*pptail = pnew;
	}
	else if (pnew->num < pcur->num)//插入到头部
	{
		pnew->pnext = *pphead;//新结点指向原来的头部
		*pphead = pnew;
	}
	else {
		while (pcur)//插入到中间
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
		//如果插入到中间，就return
		(*pptail)->pnext = pnew;
		*pptail = pnew;
	}
}

//链表删除
void list_delete(LinkList* pphead, LinkList* pptail, ElemType i)
{
	LinkList pcur, ppre;
	pcur = ppre = *pphead;
	if (!pcur)
	{
		printf("list is empty");
		return;
	}
	//如果删除的是头部
	if (i == pcur->num)
	{
		*pphead = pcur->pnext;
		if (NULL == *pphead)
		{
			*pptail = NULL;//如果删除的是最后一个结点，尾指针置为NULL
		}
		free(pcur);
		pcur = NULL;
	}
	else {//删除中间或尾部
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
		if (NULL == ppre->pnext)//代表删除的是尾结点
		{
			*pptail = ppre;
		}
		if (NULL == pcur)
		{
			printf("不存在该结点");
			return;
		}
		pcur = NULL;
	}
}

//链表修改
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
		printf("没有该结点\n");
	}
}