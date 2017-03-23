#include <stdio.h>

int main (void)
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d;
    if(a < b)
    {
        d = a;
    }
    else{
        d = b;
    }
    if(d < c)
    {
        printf("min = %d\n", d);
    }
    else{
        printf("min = %d\n", c);
    }
    return 0;
}
