#include <stdio.h>
#include <string.h>


int main(int argc,const char *argv[])
{
    char str1[32] = "abcde";
    char str2[32] = "abcdef";
    int ret;
    ret = strcmp(str1, str2);
    if(ret > 0)
    {
        printf("str1 > str2 %d\n", ret);
    }
    else if (ret < 0)
    {
        printf("str < str2 %d\n", ret);
    }
    else{
        printf("str1 = str2 %d\n", ret);
    }
    return 0 ;
}
