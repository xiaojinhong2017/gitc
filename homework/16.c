#include <stdio.h>

int main(void)
{
    int i,j,m;
    for(i=2;i<=1000;i++)
    {
        m=0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            {
                m = m + j;
            }
        }
            if(i == m)
            {
            printf("%d ",i);
            }
    }
    printf("\n");
    return 0;
}
