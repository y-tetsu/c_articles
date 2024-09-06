#include <stdio.h>

int main()
{
    _Bool a;
    int i;

    for (i=0; i<5; i++)
    {
        a = i;
        printf("a = %d -> %d\n", i, a);
    }

    return 0;
}
