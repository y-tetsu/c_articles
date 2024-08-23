#include <stdio.h>

int loop()
{
    int i;

    i = 1;
    while (i)
    {
        i = 1;
    }

    return 0;
}

int main()
{
    printf("start...\n");

    if (!loop())
    {
        printf("end.\n");
    }

    return 0;
}
