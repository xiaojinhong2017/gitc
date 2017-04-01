#include <stdio.h>

int main(void)
{
    char ch[15] = "hello world!";
    char c[15] = "hello guy!";
    char *p;
    char *q;
    int i;
    p = ch;
    q = c;
    while(*p != '\0')
    {
        p ++;
    }
    while(*q != '\0')
    {
        q ++;
    }
    if(p < q)
    {
        printf("ch > c\n");
    }
    else if(p > q)
    {
        printf("c > ch\n");
    }
    else{
        for(i = 0; i <= p; )
        {
            if('ch[i]' < 'c[i]')
            {
               printf("c > ch\n");
            }
            else if('ch[i]' > 'c[i]')
            {
               printf("ch > c\n");
            }
            else{
                i ++;
            }
        }
        printf("ch = c\n");
    }
    return 0;
}
