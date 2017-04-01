#include <stdio.h>
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main(int argc, const char *argv[])
{
    int c;
    int (*p[4])(int a, int b) = {add , sub, mul , div };
    c = p[0](1 , 2);
   printf ("%d\n", c);
    return 0;
}
int add(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a + b;
}
int mul(int a, int b){
    return a + b;
}
int div(int a, int b){
    return a + b;
}
