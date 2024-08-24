#include <stdio.h>

void hoge(int d[], int* s)
{
    d[0] += *s;
    d[1] += *s;
}

void piyo(int d[], int* restrict s)
{
    d[0] += *s;
    d[1] += *s;
}

int main(void)
{
    int a[] = {1, 1};
    hoge(a, &a[0]);
    printf("a[0] = %d, a[1] = %d\n", a[0], a[1]);

    int b[] = {1, 1};
    piyo(b, &b[0]);
    printf("b[0] = %d, b[1] = %d\n", b[0], b[1]);
}

