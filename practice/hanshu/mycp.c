#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc , char *argv[])
{
    char cmd[100];
    char c[] = "cp";
    char ch[] = " ";
    char a[] = "rm";
    if(argc == 4)
    {
        if(*argv[1] == 'c' )
        {
        
           strcat(cmd, c);
           strcat(cmd, ch);
           strcat(cmd,argv[2]);
           strcat(cmd,ch);
           strcat(cmd,argv[3]);
           printf("%s", cmd);
           system(cmd);
       }
       if(*argv[1] == 'd')
       {
        
           strcat(cmd, a);
           strcat(cmd, ch);
           strcat(cmd,argv[2]);
           strcat(cmd,ch);
           strcat(cmd,argv[3]);
           printf("%s",cmd);
           system(cmd);
       }    
    printf("\n");

   }
  else{
    printf("error\n");
  }
}
