#include <stdio.h>

int main(void)
{
    char ch[15] = "hello world!";
    char c[15];
    char *p;
    int i;
    p = ch;
    while(*p != '\0')
    {
        c[i] = *p;
        i ++;
        p ++;
    }
     printf("%s", c);
    return 0;
}
