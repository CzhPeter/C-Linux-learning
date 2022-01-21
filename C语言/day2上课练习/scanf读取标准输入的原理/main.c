#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void scanf_exercise()
{
	int i;
	scanf("%d", &i);
	printf("%d\n", i);
}

void convert()
{
	char c;
	while (scanf("%c", &c))
	{
		if (c != 'n')
		{
			printf("%c", c - 32);
		}
		else {
			printf("\n");
			break;
		}
	}
}

int main()
{
	//scanf_exercise();
	convert();
}
