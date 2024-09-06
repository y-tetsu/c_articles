#include <stdio.h>
#include <complex.h>

int main()
{
    double _Imaginary z = 3.0 * I;

    printf("%.1fi\n", cimag(z));

    return 0;
}
