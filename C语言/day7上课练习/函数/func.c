#include "func.h"

int printStar(int i, int j)
{
	printf("*******************\n");
	printf("printStar i=%d", i);
	return i + 3;
}

void printMessage()
{
	printf("how do you do\n");
	printStar(5, 3);
}