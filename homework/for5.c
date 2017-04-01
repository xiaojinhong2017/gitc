#include <stdio.h>

int main (void)
{
    int a , b , c , d, i;
    for(i = 100;i < 1000;i++)
    {
      a = i % 10;
      b = i / 10 % 10;
      c = i / 100;
      d = a * a * a + b * b *b + c * c *c;
      if (i == d)
      {
          printf("i = %d\n", i);
      }
    }
    return 0;
}
