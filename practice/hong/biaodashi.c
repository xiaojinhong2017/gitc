#include <stdio.h>
#define MAX(x,y) (x)>(y)? (x):(y)
void main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int t;
    t = MAX(a+b,c+d);
    printf("%d", t);

}
