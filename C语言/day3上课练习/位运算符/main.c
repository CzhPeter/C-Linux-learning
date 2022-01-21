#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0x8023;
	i = i << 1;
	printf("◊Û“∆i=%d\n", i);
	unsigned short us = 0x8023;//Œﬁ∑˚∫≈ ˝”““∆∏ﬂŒª≤π0
	us = us >> 1;
	printf("”““∆i=%d\n", us);
	short s = 0x8023;
	s = s >> 1;
	printf("”““∆i=%d\n", s);
	//Œª‘ÀÀ„
	int a = 5, b = 7;
	printf("a&b=%d\n", a & b);
	printf("a|b=%d\n", a | b);
	printf("a^b=%d\n", a ^ b);
	printf("~a=%d\n", ~a);
	return 0;
}