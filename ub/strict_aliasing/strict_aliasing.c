#include <stdio.h>

int hoge(int* ptr)
{
    int a = *ptr;

    *(short*)ptr = 20;
    printf("*ptr = %d\n", *ptr);
    printf("*ptr = %d\n", *ptr);

    return a;
}

int main()
{
    int x = 10;

    hoge(&x);

    return 0;
}
