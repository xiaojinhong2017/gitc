#include <stdio.h>

int main(void)
{
    printf("please input 年 月 日\n")
    scanf("%d ,%d ,%d "&year,&month,&day);
    printf("一  二  三  四  五  六  日\n");
    for(i=1;i<year;i++)
    {
        if(i%4&&i%100||i%400)
        {
            j++;
        }
        a = (n -1 - j) * 365 + j * 366;
    }
    return 0;
}
