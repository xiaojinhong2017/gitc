#include <stdio.h>

int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char  *p;
    int i;
    p = a;
    for(i = 0 ;i < 10 ; i ++)
    {
        printf("%d ", *p);
        p += 4;
    }
    printf("\n");
    return 0;
}
