#include <stdio.h>

int main(void)
{
    char c = 'c';
    c = getchar();
    while(c!=EOF)
    {
    if(  c  >= 48 && c  < 53)
    {
      printf("c = %c \n", c+=5 );
    }
    else if( c >= 54 && c  <= 59)
    {
        printf("c = %c \n", c-=5);
    } 
    else if( c >= 65 &&  c <= 90)
     {
         printf("c = %c \n", c+= 32);
     }
   else{

    printf("c = %c \n", c-= 32);
}
     c = getchar();
}
    return 0;
}
