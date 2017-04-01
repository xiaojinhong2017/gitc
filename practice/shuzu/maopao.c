#include <stdio.h>

int main(void)
{
    int a[10] = { 34 ,21 ,7 ,48 ,12 ,3 ,10 ,56 , 0, 33};
    int m;
    int i;
    int j;
    for(j = 10; j > 0; j --)
    {
        for(i = 0;i < j - 1; i ++)
        {
           if(a[i] < a[i+1])
             {
               m = a[i];
               a[i] = a[i+1];
               a[i+1] = m;
             }
         }
        printf("%d ", a[i]);
    }
        printf("\n");
        return 0 ;
}
