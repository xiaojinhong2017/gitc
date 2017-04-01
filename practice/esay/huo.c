#include <stdio.h>

int main (void)
{
    int a = -3, b = 3, c = 4;
    int num = 0;
    printf("a || b ===> %d\n",a || b);
    printf("(a > b) || (a > c) ===> %d\n", (a > b) || (a > c));
    printf("(a < b) || (a > c) ===> %d\n", (a < b) || (a > c));
    printf("(num =a + b) ||(a < b)=====> %d\n", (num = a + b) ||(a < b));
    printf("num = %d\n", num);
    return 0;
}
