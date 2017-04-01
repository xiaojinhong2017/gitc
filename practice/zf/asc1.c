#include <stdio.h>

int main(void)
{
    char c = 'c';
    c = getchar();
    printf("c(10) = %d\t c(8) = %o\t c(16) = %x\n", c, c, c);
    printf("c = %c \n", c += 5);
    c = getchar();
    printf("c = %c \n", c += 5);
    c = getchar();
    printf("c = %c \n", c += 5);
    c = getchar();
    printf("c = %c \n", c += 5);
    c = getchar();
    printf("c = %c \n", c -= 5);

    return 0;
}
