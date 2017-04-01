#include <stdio.h>
#include <string.h> 
void mystrcat(char *dest, char *cmd, char *tag );

int main(void)
{
   char a[20] = "li";
   char b[20] = "linux";
   char c[100];
    mystrcat (c, a, b);

    printf("%s\n",c);
    return 0;
}
void mystrcat(char *dest, char *cmd, char *tag )
{
    char a[10] = "<";
    char b[10] = ">";
    char c[10] = "/";
    strcat(dest , a);
    strcat(dest , cmd);

    strcat(dest , b);
    strcat(dest , tag);
    strcat(dest , a);
    strcat(dest , c);
    strcat(dest , cmd);
    strcat(dest , b);
}
