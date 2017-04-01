#include <stdio.h>

int main (void)
{
    int i=0;
    for(i=0;i<10;i++)
    {
        if(i<5)
        {
            continue;
        }
        printf("i=%d\n",i);
    }
    printf("after for ...\n");
    return 0;
}
