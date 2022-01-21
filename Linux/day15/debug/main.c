#include <stdio.h>

int main()
{
#ifdef DEBUG
    printf("I am a debug information, can help you\n");
#endif
    printf("Hello world\n");
    return 0;
}

