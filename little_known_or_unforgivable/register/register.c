#include <stdio.h>

int main()
{
    register int x = 0;
    register int y = (x = 1, x + 1, x * 2);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
