#include <stdio.h>

int main(void)
{
 char ch ;
 int i, j;
 ch = getchar();
 while(ch != EOF)
 {
    if((ch >= 'a'&& ch <= 'z')||(ch >= 'A' && ch <= 'Z')) 
    {
        i ++;
    }
    if(ch >= '0'&&ch <='9')
    {
        j ++;
    }
    ch = getchar();
 }
 printf("zimu = %d, shuzi = %d", i, j);
    return 0;
}
