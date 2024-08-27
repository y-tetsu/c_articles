#include <stdio.h>

int main()
{
    int x = 10;
    float *ptr = (float *)&x;

    printf("x = %d, *ptr = %f\n", x, *ptr);

    *ptr = 5.69f;

    printf("x = %d, *ptr = %f\n", x, *ptr);

    return 0;
}
