#include <stdio.h>

int main (void)
{
    int i;
    int n = 1;
    for(i = 10; i > 0; i --)
    {
        n = ( n + 1) * 2;
    }
    printf("n = %d\n", n);
    return 0;
}
