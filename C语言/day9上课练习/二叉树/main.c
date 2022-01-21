#include "BiTree.h"

int main()
{
	ElemType val;
	pNode_t treeRoot = NULL;
	pQueue_t queHead = NULL, queTail = NULL;
	while (scanf("%c", &val) != EOF)
	{
		if (val == '\n')
		{
			break;
		}
		buildBinaryTree(&treeRoot, &queHead, &queTail, val);
	}
	printf("---------------\n");
	preOrder(treeRoot);
	printf("\n");
	printf("---------------\n");
	midOrder(treeRoot);
	printf("\n");
	printf("---------------\n");
	postOrder(treeRoot);
	printf("\n");
	return 0;
}