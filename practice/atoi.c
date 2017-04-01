#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    char buffer[256];
    printf("enter a number");
    fgets(buffer,256,stdin);
    i = atoi(buffer);
    printf("the value enterefis %d",i);
    return 0;
}//把字符串转换成数字

