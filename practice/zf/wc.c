#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int c;
    int chars = 0;
    int words = 0;
    char temp = ' ';

    while ((c = getchar()) != EOF)
    {
        chars++;

        if(!isspace(c)&& isspace(temp))
        {
            words++;
        }
        temp = c;
    }
    printf("chars = %d, words = %d\n", chars, words );
    return 0;
}
