#include <stdio.h>

int main(void)
{
    int i , j;
    int a[10][10];
    for(i = 0; i < 10 ; i++)
    {
        a[i][0] = 1;
    }
    for(i =0;i < 10 ; i++)
    {
       for(j = 0 ;j <= i; j ++)
         {
             if(i==0&&j==0)
             {
                 printf("%d   \n",a[i][j]);
             }
               else if(j== 0)
                {
                    printf("%d   ",a[i][j]);
                }
                 else if(i == j)
                 {
                    a[i][j]=1;
                     printf("%d\n",a[i][j]);
                 }
                  else{
                      a[i][j]=a[i-1][j-1] + a[i-1][j];
                      printf("%d   ",a[i][j]);
                }
        }
    }
    return 0;
}
