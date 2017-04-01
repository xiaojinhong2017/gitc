#include <stdio.h>

int main(void)
{
    int a[10]={10, 20, 30, 40, 50, 60, 70, 80, 90, 0};
    int i;
    for(i = 9;i >= 0; i--)
    {
    printf("%d\n", a[i]);
    }
    return 0;
}
