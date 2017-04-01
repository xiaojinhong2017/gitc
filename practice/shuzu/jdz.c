#include <stdio.h>

int main(void)
{
    int a[5] = {1, 23, 10, 89, 35};
    int m = 0;
    int i;
    for(i = 0;i < 5; i++)
    {
        if(a[i] > m)
        {
            m = a[i];
        }
    }
    printf("%d\n", m );
    return 0;
}
