#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int num;
	char name[20];
	float score;
}stu;

int main()
{
	stu s = { 10001,"hanmeimei",95.03 };
	FILE* fp;
	int ret;
	fp = fopen("file.txt", "r+");
	if (NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	fprintf(fp, "%d %s %5.2f\n", s.num, s.name, s.score);
	memset(&s, 0, sizeof(s));
	fseek(fp, 0, SEEK_SET);
	ret = fscanf(fp, "%d%s%f", &s.num, &s.name, &s.score);
	printf(fp, "%d %s %5.2f\n", s.num, s.name, s.score);
	fclose(fp);
	return 0;
}