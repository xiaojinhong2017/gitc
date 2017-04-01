#include <stdio.h>

int main(void)
{
    char ch = 'c' ;
    ch = getchar();
    int i = 0 ;
    int j = 0 ;
    while(ch != EOF)
    {
        if(ch == '\n')
        {
            j ++;
        }
        i ++;
        ch = getchar();
    }
    printf("%d\n",i);
    printf("%d\n",j);

    return 0;
}


