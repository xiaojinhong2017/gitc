#include <stdio.h>
#include <string.h>

char *pj(char *dest,const char *src1, const char *src2){
    strcpy(dest, src1);
    strcat(dest, src2);
    return dest;
}
int main(void)
{
    char sum[100];
    char *sum1;
    char name[]="zhao";
    char age[]= "20";
    sum1 = pj(sum, name, age);
    printf("%d",&sum);
    printf("sum = %s\n", sum);
    printf("sum1 =%s\n",sum1);
    return 0;
}
