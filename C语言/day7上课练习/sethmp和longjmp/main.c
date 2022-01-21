#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void b(jmp_buf envbuf)
{
	printf("I am func b\n");
	longjmp(envbuf, 5);//回到envbuf现场
}

void a(jmp_buf envbuf)
{
	printf("before b, I am func a\n");
	b(envbuf);
	printf("after b, I am func a\n");
}


//上下文就是当前寄存器的状态
int main()
{
	int ret;
	jmp_buf envbuf;
	ret = setjmp(envbuf);//把当前的上下文
	if (0 == ret)
	{
		a(envbuf);
	}
	return 0;
}