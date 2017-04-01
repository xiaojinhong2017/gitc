#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char cmd[100];
    char c[] = "mv";
    char ch[] = " ";
    char buf[100];
    //system("cat file");
    while(fgets(buf, 10, stdin) != NULL){
        buf[strlen(buf) - 1] = '\0';
        strcat(cmd, c);
        strcat(cmd, ch);
        strcat(cmd, buf);
        printf("%s", cmd);
        system(cmd);
    }
return 0;
    
}
