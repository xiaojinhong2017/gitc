#include <stdio.h>
//���100���ڵ�����
int main (void)
{
    int i,j,a;
    for(i=1;i<=100;i++)
    {
        for(j=2;j<i;j++)
        {
           a = i %j;
           if (a == 0)
           {
               break;
           }
        }
       if(i==j){
           printf("%d ", i);
       }
    }
    printf("\n");
    return 0;
}
