#include <stdio.h>

int main(void)
{
    char ch ;
    char a;
    char b;
    ch = getchar();
    int flag;
    while(ch != EOF) 
    {
        
        if(ch != '%')
        {
            printf("%c", ch);
            ch = getchar();
        }
            else{
                a = ch;
                ch = getchar();
                if(ch != '2')
                {
                    printf("%c%c", a, ch);
                    ch = getchar();
                }
                else{
                    b = ch;
                    ch = getchar();
                    if(ch != '0')
                    {
                        printf("%c%c%c", a, b, ch);
                        ch = getchar();
                    }
                    else{
                        printf(" ");
                        ch = getchar();
                    }
                }
            }
        }
    return 0;
}
