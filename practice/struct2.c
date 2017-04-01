#include <stdio.h>

int main(void)
{
    typedef struct{

        int number;
        char a[10];
        int hand;
    }s, *p;
    s part = {100, "nihao", 20};
    p q;
    q = &part;
    printf("%d , %s , %d\n", (*q).number, q->a, q->hand);
    return 0;
}
