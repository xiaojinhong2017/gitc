#include <stdio.h>

int main(void)
{
    int n,a,j,i,b,d,g,h;
    int c=1 ;
    int f=0;
    printf("please input a oushu:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        d = n --;
           for(j=d;j>0;j--)
           {
            printf(" ");
           }
        for(b=1;b<=c;b++)
           {   
        printf("*");
            }
        c=c+2;
        printf("\n");
    }
    d = 0;
    for(i=n;i>0;i--)
    {
        d ++;
        for(j=0;j<=d;j++)
        {
        printf(" ");
        }
        c=c-2;
        for(g=0;g<=c;g++)
        {
        printf("*");
        }
        printf("\n");
    }
    return 0;
}
