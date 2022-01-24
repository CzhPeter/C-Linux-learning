#include <func.h>

int main()
{
    time_t now;
    time(&now);
    printf("%ld\n",now);
    printf("字符串时间=%s",ctime(&now));
    return 0;
}