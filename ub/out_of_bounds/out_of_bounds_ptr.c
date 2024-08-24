#include <stdio.h>

int main()
{
    char arr[3] = {1, 2, 3};
    int i;
    int *ptr;

    ptr = (int*)arr;
    for (i=0; i<sizeof(arr); i++)
    {
        printf("%d\n", *ptr);
        ptr++;
    }

    return 0;
}
