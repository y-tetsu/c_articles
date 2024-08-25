#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(sizeof(int));

    *ptr = 569;
    printf("before : %d\n", *ptr);

    free(ptr);
    printf("after  : %d\n", *ptr);

    return 0;
}
