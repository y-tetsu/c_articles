#include <stdio.h>

int main()
{
    int x = 0;
    int y = (x = 1, x + 1, x * 2);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
