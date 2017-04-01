#include <stdio.h>


void swap(int *p, int *q);
int main(void)
{
    int a = 1;
    int b = 2;
    swap(&a,&b);
    printf("%d", a);
    printf("%d", b);
    return 0;
}
void swap(int *p, int *q)
{
    int m ;
    m = *p;
    *p = *q;
     *q = m;
}
