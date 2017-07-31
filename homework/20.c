#include <stdio.h>

int main (void)
{
    int a, l, b, c, m,  leap, i , n, o, month, year;
    int p = 1;
    int j = 0;
    int k = 0;
    printf("please input year month \n");
    scanf("%d ,%d",&year,&month);
    printf("1  2  3  4  5  6  7\n");
    for(i=0;i<year;i++)
    {
    if(((year % 4 == 0)&&(year % 100 != 0))||(year % 400 == 0))
    {
        j++;
    }
    else{
        k++;
    }
    }
    a = k * 365 + j * 366;
    //printf("%d\n",a);
   // printf("%d\n",j);
    //printf("%d\n",k);
    if(((year % 4 == 0)&&(year % 100 !=0))||(year % 400 == 0))
    {
        leap = 1;
    }
    else{
        leap = 0;
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
        b = 31 + 28 +leap + 31;
    }
    else if(month == 5){
        b = 31 + 28 + leap + 30 + 31 ;
    }
    else if(month == 6){
        b = 31 + 28 + leap + 30 + 31 + 31 ;
    }
    else if(month == 7){
        b = 31 + 28 + leap + 30 + 31 + 30 +31 ;
    }
    else if(month == 8){
        b = 31 + 28 + leap + 30 + 31  + 30 + 31 + 31 ;
    }
    else if(month == 9){
        b = 31 + 28 + leap + 30 + 31 + 30 + 31 + 31 + 31 ;
    }
    else if(month == 10){
        b = 31 + 28 + leap + 30 + 31 + 30 + 31 + 31 + 30 + 31 ;
    }
    else if(month == 11){
        b = 31 * 6 + 28 + leap + 3 * 30;
    }
    else{
        b = 31 * 6 + 28 + leap + 4 * 30 ;
    }
    m = a + b;
    c = m % 7;
   // printf("%d\n",m);
    //printf("%d\n",b);
    //printf("%d\n",c);
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
    for(o = 1;o <= 31 + c; o ++)
    {
        if((o - 1) % 7 == 0)
        {
            printf("\n");
        }
        if(o <= c)
        {
            printf("   ");
        }
        else
        {
            printf("%2d ",p);
            p ++;
        }
    }
    }
   else if(month==4||month==6||month==9||month==11)
    {
        for(o = 1;o <= 30 + c; o ++)
        {
            if((o - 1) % 7 == 0)
            {
                printf("\n");
            }
            if(o <= c)
            {
                printf("   ");
            }
            else{
                printf("%2d ",p);
                p ++;
            }

        }

    }
    else{

        for(o = 1;o <= 28 + leap + c; o ++)
        {
            if((o - 1) % 7 == 0)
            {
                printf("\n");
            }
            if(o <= c)
            {
                printf("   ");
            }
            else{
                printf("%2d ",p);
                p ++;
            }
        }
    }
    printf("\n");
    return 0;
}
