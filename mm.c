#include <stdio.h>
//ʵ����ֵ�������
int main (void)
{
    int a, x;
    printf("please input a  number !\n");
    scanf("%d",&x);
    if(x == 0)
    {
        printf("a = %d\n",x);
    }
    else{
    while(x != 0) 
    {
        a = x % 10;
        printf("%d", a);
        x = x / 10;
    }
    }
    printf("\n");
    return 0;
}
