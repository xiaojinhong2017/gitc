#include <stdio.h>

int main(void)
{
    int a,b,c,d,f,n,i;
    for(i=10000;i<99999;i++)
    {
        n = i;
        a = n % 10;
        b = (n / 10) % 10;
        c = (n / 100) % 10;
        d = (n / 1000) % 10;
        f = (n / 10000) % 10;
        if(b == a + 1 && c == b + 1&&c == d + 1&& d == f + 1)
        {
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}
