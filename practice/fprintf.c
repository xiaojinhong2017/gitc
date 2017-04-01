#include <stdio.h>
#include <stdlib.h>
#include <process.h>
File* stream;
int main(void)
{
    int i = 10;
    double fp = 1.15;
    char s[] = "this is a string";
    char c = '\n';
    stream = fopen("sprintf.out","w");
    fprintf(stream, "%d\n", i);
    fprintf(stream, "%f\n", fp);
    fprintf(stream, "%s\n", s);
    fprintf(stream, "%c\n", c);
    system("typefprintf.out");
    return 0;
}
