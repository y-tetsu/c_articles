#include <stdio.h>

int main()
{
    int x = 10;
    float *p = (float *)&x;

    printf("x = %d, *p = %f\n", x, *p);

    *p = 5.69f;

    printf("x = %d, *p = %f\n", x, *p);

    return 0;
}
