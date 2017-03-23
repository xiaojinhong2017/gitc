#include <stdio.h>
//因式分解
int main()
{
    int n , i;
    printf("please input a number !\n");
    scanf("%d ",&n);
    printf("%d =",n);
    for(i=2;i<n;)
    {
        if(n%i == 0)
        {
            printf("%d*",i);
            n = n / i;
        }
        else{
            i++;
        }
    }
    printf("%d\n",n);
    return 0;
}
