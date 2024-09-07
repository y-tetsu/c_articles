#include <stdio.h>

_Static_assert(sizeof(int) > 2, "16bit code not supported.");

int main()
{
    printf("OK.\n");

    return 0;
}
