#include <stdio.h>
#include <string.h>

    struct part{
        int number;
        char name[20] ;
        int hand;
    };
struct part build_part(int number, const char*name, int hand)
{
    struct part p;
    p.number = number;
    strcpy (p.name, name);
    p.hand = hand;
    return p;
}
int main(void)
{
    struct part part1;
    part1 = build_part(528, "Disk dirver", 10);
    printf("%d , %s , %d\n", part1.number, part1.name, part1.hand);

  return 0;
}
