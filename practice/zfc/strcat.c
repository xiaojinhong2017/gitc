#include <stdio.h>
#include <string.h>


int main(int argc,const char *argv[])
{
    char dest[64] = "Hello World";
    char src[32] = "This is a test";
    strcat(dest , src);
    printf("%s\n",dest);
    return 0 ;
}
