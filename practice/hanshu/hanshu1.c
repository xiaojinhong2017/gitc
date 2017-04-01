#include <stdio.h>
#include <string.h>

void xiaowu(void)
{
   printf("dao!\n");
}
void xiaowu1(int a){
    printf("xiaowu1 = %d\n", a);
}
void xiaowu2(int a, int b)
{
   printf("a + b = %d\n", a+b);
}
char xiaowu3(int a, int b){
    char c;
    c = a + b;
    return c;
}
char *pj(char *dest,const char *src1, const char *src2){
    strcpy(dest, src1);
    strcat(dest, src2);
    return dest;
}
int main(void)
{
    int i = 10, j = 20 ;
    char x;
    char sum[100];
    char *sum1;
    char name[]="zhao";
    char age[]= "20";
    sum1 = pj(sum, name, age);
    printf("sum = %s\n", sum);
    printf("sum1 =%s\n",sum1);
    return 0;
}
