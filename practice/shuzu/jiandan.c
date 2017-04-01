#include <stdio.h>

int main(void)
{
    int a[10] = {9 ,1 , 2, 5, 7, 4, 8, 6, 3,5};
    int i, m , n ,j;
    for(i = 0; i < 10; i++)
    {
        m = a[i];
    for(j = 1 + i; j < 10; j++)
    {
        if(a[j] < m)
        {
            m = a[j];
            n = j;

        }
    }
    printf("%d ", m);
    a[n] = a[i];
    a[i] = m;
    }
    printf("\n");
    return 0;
}
