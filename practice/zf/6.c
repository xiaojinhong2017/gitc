#include <stdio.h>

int main(void)
{
    int ch;
    int flag = 0;
    while((ch = getchar()) != EOF)
    {
        if(flag == 0)
        {
            if(ch == '%')
            {
                flag ++;
            }
            else{
                flag = 0;
                printf("%c", ch);
            }
        }
        else if(flag == 1)
        {
            if(ch == '2')
            {
                flag ++;
            }
            else{
                printf("%%");
                printf("%c", ch);
                flag = 0;
            }
        }
        else if(flag == 2)
        {

            if(ch == '0')
            {
                printf(" ");
            }
            else{
                printf("%%");
                printf("2");
                printf("%c", ch);
            }
            flag = 0;
        }
    }
    return 0;
}
