#include <stdio.h>
#include <stdlib.h>

void interger_type()
{
	int i;
	short s;
	long l;
	long long l2;
	short a, b;
	a = 32767;
	b = a + 1;
	printf("%d\n", b);
	unsigned int m = 0x80000000;
	printf("%u\n", m);
}

void float_exercise()
{
	float f = 4.5;
	double a, b;
	a = 1.23456789e10;
	b = a + 20;
	printf("%f\n", b);
}

void char_exercise()
{
	char c = 'a';
	printf("%c\n", c);
	printf("%d\n", c);
}

void mix_calc() 
{
	char b = 0x93 << 1 >> 1;
	printf("%x\n", b);
	b = 0x93 << 1;
	b = b >> 1;
	printf("%x\n", b);
}

//整型常量默认按int型计算
void mix_calc2() 
{
	long m;
	m = (long long)131072 * (long long)131072;
	printf("%lld\n", m);
}

//浮点型常量默认用double型计算
void mix_calc3()
{
	float f = 1234567890.0;
	printf("%f\n", f);
	printf("%f\n", 1234567890.0);
	f = 1.456;
	if (f - 1.456>-0.0001 && f - 1.456 < 0.0001)
	{
		printf("f is equal to 1.456\n");
	}
}

//不同数据类型混合运算，强制类型转换
void mix_cal4()
{
	int i = 5;
	float f = (float)i / 2; //float f = i / 2.0;
	printf("%f\n", f);
}

int main()
{
	//interger_type();
	//float_exercise();
	//char_exercise();
	//mix_calc();
	//mix_calc2();
	//mix_calc3();
	mix_cal4();
	return 0;
}