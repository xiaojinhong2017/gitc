#include <stdio.h>

int main(void)
{
    char *p;
    char ch[15] = "hello world";
    int count = 0;
    for(p = ch; *p != '\0';p++)
    {
        count ++;
    }
    printf("%d", count);
    return 0;
}
