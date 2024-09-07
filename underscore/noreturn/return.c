#include <stdio.h>
#include <stdlib.h>

_Noreturn void goodbye()
{
    printf("good-bye here.\n");

    abort();

    printf("hello again. (but...)\n");

    return;
}

int main()
{
    goodbye();

    printf("never come back here.\n");

    return 0;
}
