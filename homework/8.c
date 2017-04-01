#include <stdio.h>

int main (void)
{
    int i,j;
    int m = 1;
    int n;
    for (j = 1; j <=10; j++)
    {
        n = j;
    for(i = j - 1; i > 0; i --)
    {
        n =  n * i;
    }
     m =  m + n ;
    }
    printf("sum = %d\n",m);
    return 0;
}
