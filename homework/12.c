#include <stdio.h>
//输出50～100之间所有数的因式分解
int main(void)
{
    int i , j ,n;
    for(i=50;i<=100;i++)
    {
        printf("%d=",i);
        n = i;
        for(j=2;j<n;)
        {
            if(n % j == 0)
            {
                printf("%d*",j);
                n=n/j;
            }
            else{
                j++;
            }
        }
        printf("%d\n",n);
        
    }
    return 0;
}
