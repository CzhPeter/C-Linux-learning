#include "BiTree.h"

//��ν���
void buildBinaryTree(pNode_t* treeRoot, pQueue_t* queHead, pQueue_t* queTail, ElemType val)
{
	//�����������ռ�
	pNode_t treeNew = (pNode_t)calloc(1, sizeof(Node_t));
	treeNew->c = val;
	pQueue_t queNew = (pQueue_t)calloc(1, sizeof(Queue_t));
	queNew->insertPos = treeNew;
	pQueue_t queCur;
	if (NULL == *treeRoot)
	{
		*treeRoot = treeNew;
		*queHead = queNew;
		*queTail = queNew;
	}
	else {
		//���
		(*queTail)->pnext = queNew;
		*queTail = queNew;
		//�ж�ĳ�������������Ƿ�Ϊ��
		if (NULL == (*queHead)->insertPos->left)
		{
			(*queHead)->insertPos->left = treeNew;
		}
		//�ж�ĳ���������Һ����Ƿ�Ϊ��
		else if (NULL == (*queHead)->insertPos->right)
		{
			(*queHead)->insertPos->right = treeNew;
			//��ĳ����������Һ��Ӷ����˾ͳ���
			queCur = *queHead;
			*queHead = queCur->pnext;
			free(queCur);
			queCur = NULL;
		}
	}
}


//ǰ�������������ȱ���
void preOrder(pNode_t treeRoot)
{
	if (treeRoot)
	{
		putchar(treeRoot->c);
		preOrder(treeRoot->left);
		preOrder(treeRoot->right);
	}
}

//�������
void midOrder(pNode_t treeRoot)
{
	if (treeRoot)
	{
		midOrder(treeRoot->left);
		putchar(treeRoot->c);
		midOrder(treeRoot->right);
	}
}

//�������
void postOrder(pNode_t treeRoot)
{
	if (treeRoot)
	{
		postOrder(treeRoot->left);
		postOrder(treeRoot->right);
		putchar(treeRoot->c);
	}
}