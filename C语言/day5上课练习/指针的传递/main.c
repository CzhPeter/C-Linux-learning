#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//c语言形参的位置不能出现&，因为c语言不支持引用
void change(int *j)//j叫形参  j=&i
{
	*j = 5;//间接访问
}

//指针传递的使用场景
int main() 
{
	int i = 10;
	printf("before change i=%d\n", i);
	change(&i);//i叫实参，实参赋值给形参的过程，实参可以是变量
	printf("after change i=%d\n", i);
	return 0;
}