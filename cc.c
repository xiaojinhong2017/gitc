#include <stdio.h>
#include <math.h>

int main (void)
{
    int a = 4, b = 8, c = 4;
    int tmp = b * b - 4 * a * c;
    printf("tmp = %d\n", tmp);
    double x1, x2;
    if (tmp > 0)
    {
        x1 = ( - b + sqrt(tmp))/ (2*a);
        x2 = ( - b - sqrt(tmp))/ (2*a);
        printf("x1 = %f, x2 = %f\n", x1,x2);
    }
    else if (tmp == 0)
    {

        x1 = x2 = -b / (2 * a);
        printf("x1 = x2 = %f\n", x1);
    }
    else{
        printf(" no result !\n");
    }
    return 0;
}
