#include <stdio.h>

int main (void)
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d;
    printf("a = %d, b = %d, c = %d\n", a , b , c);
    if(a>b)
    {
       d = a; 
    }
    else{
        d = b;
    }
    if(d > c)
    {
        printf("max = %d\n", d);
    }
    else{
        printf("max = %d\n", c);
    }
    return 0;
}
