#include <stdio.h>
//���50��100֮������������ʽ�ֽ�
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
