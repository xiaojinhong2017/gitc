#include <stdio.h>

int main(void)
{
    char ch[10] = "hello";
    int i = 0;
    while(ch[i] !='\0')
    {
        i ++;
    }
    printf("%d", i);
    return 0;
}
