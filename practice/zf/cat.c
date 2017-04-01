#include <stdio.h>


int main(void)
{
    char c = 'c';
    c = getchar();
    while(c != EOF )
    {
        printf("%c", c);
        c = getchar();
    }
    return 0;
}
