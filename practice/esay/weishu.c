#include <stdio.h>

int main(void)
{
    int a;
    int i = 1;
    printf("please put a numble\n");
    scanf("%d\n",&a);
    a = a / 10;
    while(a != 0)
    {
        i++;
        a = a/10;
    }
    printf("i = %d\n", i);
    return 0;
}
