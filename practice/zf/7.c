#include <stdio.h>

int main(void)
{
    int ch;
    int flag = 0;
    while((ch = getchar()) != EOF)
    {
        if(flag == 0)
        {
            if(ch == 'a')
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
            if(ch == 'b')
            {
                flag ++;
            }
            else if(ch == 'a'){
                printf("a");
                flag = 1;
            }
            else{
                printf("a");
                printf("%c", ch);
                flag = 0;
            }
        }
        else if(flag == 2)
        {

            if(ch == 'a')
            {
                flag ++;
            }
            else{
                printf("a");
                printf("b");
                printf("%c", ch);
                flag = 0;
            }
        }
        else if(flag == 3)
        {

            if(ch == 'c')
            {
                printf(" ");
            }
            else{
                printf("a");
                printf("b");
                printf("a");
                printf("%c", ch);
            }
         flag = 0;
    }
    }
    return 0;
}
