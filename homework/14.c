#include <stdio.h>

int main(void)
{
    int i , j , m , n, l ;
    scanf("%d", &n);
    m = n;
    for(i = 1; i <= n; i ++)
    {
        for(j = n; j > i; j --)
        {
            printf(" ");
        }
        for(l = 1; l <= 2 * i - 1; l ++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
