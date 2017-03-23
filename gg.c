#include <stdio.h>

int main (void)
{
    int a = 2, b = 3, c = 4;
    int num = 0;
    printf("(num = %d - %d)&&(a > b)&&(a > c) ===>  %d\n", a, b, (num = a - b)&&(a > b)&&(a > c));
    printf("num = %d\n", num);
    int ret = (a > b)&&(num = 10);
    printf("ret = %d, num = %d", ret, num);
    return 0;
}
