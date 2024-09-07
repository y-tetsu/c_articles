#include <stdio.h>
#include <stdlib.h>

void goodbye()
{
    printf("good-bye here.\n");

    abort();

    printf("hello again. (but...)\n");
}

int main()
{
    goodbye();

    printf("never come back here.\n");

    return 0;
}
