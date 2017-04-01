#include <stdio.h>

int main(void)
{
    int a[10]={10, 20, 30, 40, 50, 60, 70, 80, 90};
    int i;
    int sum = 0;
    for(i = 0;i < 10; i++)
    {
        sum = sum + a[i];
    }
    printf("%d\n", sum);
    return 0;
}
