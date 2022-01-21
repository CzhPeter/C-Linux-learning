#define MAXKEY 1000

#include <stdio.h>
#include <stdlib.h>

int hash(char* key)
{
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
		{
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h % MAXKEY;
}

int main()
{
	char* str[] = { "lele", "xiongda", "fenghua", "python", "c" };
	char* Hash_Table[MAXKEY] = { 0 };
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%s %d\n", str[i], hash(str[i]));
		//·ÅÈë¹þÏ£±í
		Hash_Table[hash(str[i])] = str[i];
	}
	return 0;
}