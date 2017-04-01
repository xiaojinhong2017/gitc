#include <stdio.h>

int main (void)
{
    printf("please input 年 月 日\n");
    scanf("%d ,%d ,%d ",&year,&month,&day);
    printf("一  二  三  四  五  六  日\n");
    for(i=1;i<year;i++)
    {
    if(((year % 4 == 0)&&(year % 100 != 0))||(year % 400 == 0))
    {
        j++;
    }
        a=(n - 1 -j) * 365 + j * 366;
    }
    if(((year % 4 == 0)&&(year % 100 !=0))||(year % 400 == 0))
    {
        leap = 1;
    }
    if(month == 1)
    {
         b  = 0;
    }
    else if (month == 2)
    {
        b  = 31 ;
    }
    else if(month == 3){
        b = 31 + 28 + leap ;
    }
    else if(month == 4){
        b = 31 + 28 +leap + 30;
    }
    else if(month == 5){
        b = 31 + 28 + leap + 30 + 31 ;
    }
    else if(month == 6){
        b = 31 + 28 + leap + 30 + 31 + 30 ;
    }
    else if(month == 7){
        b = 31 + 28 + leap + 30 + 31 + 30 +31 ;
    }
    else if(month == 8){
        b = 31 + 28 + leap + 30 + 31  + 30 + 31 + 31 ;
    }
    else if(month == 9){
        b = 31 + 28 + leap + 30 + 31 + 30 + 31 + 31 + 30 ;
    }
    else if(month == 10){
        b = 31 + 28 + leap + 30 + 31 + 30 + 31 + 31 + 30 + 30 ;
    }
    else if(month == 11){
        b = 31 * 6 + 28 + leap + 3 * 30;
    }
    else{
        b = 31 * 6 + 28 + leap + 4 * 30 ;
    }
    b = a + b;
    c = b % 7;
    for(n=7;n>0;n--)
    {
    if(c!=0)
    {
        printf(" ");
        c--;
    }
    m++;
    printf("%2d  ",m);
    printf("\n");
    return 0;
}
