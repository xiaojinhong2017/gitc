#include <stdio.h>

int main(void)
{
    char ch ;
    ch = getchar();
    while(ch != EOF) 
    {
        if(ch == ' ')
        {
        printf("%%20");
        }
    else{
    printf("%c", ch);
    }
    ch = getchar();
    }
    return 0;
}
