#include <stdio.h>

int main(void)
{
    char ch[30] = "hello world!";
    char c[15] = "hello guy!";
    int i, j;
    for(i = 0; ch[i] != '\0';)
    {
        i ++;
    }
    for(j = 0; c[j] != '\0'; j++)
    {
        ch[i] = c[j];
        i ++;
    }
    printf("%s",ch);
    return 0;
}
