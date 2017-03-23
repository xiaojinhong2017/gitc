#include<stdio.h>

int main (void)
{
    int a = 1;
    int b = 2;
    int c = 3;
    printf("a = %d, b = %d, c = %d\n", a , b, c);
    if( a > b )
    {
        if( a > c )
        {
            printf("max = %d\n", a);
        }
        else{
            printf("max = %d\n", c);
        }
    }
    else{
        if( b > c)
        {
            printf("max = %d\n", b);
        }
        else {
            printf("max = %d\n", c);
        }
    }
    return 0;
}
