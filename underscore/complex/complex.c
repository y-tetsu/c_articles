#include <stdio.h>
#include <complex.h>

int main()
{
    double _Complex z1 = 1.0 + 2.0 * I;  // 複素数 1 + 2i
    double _Complex z2 = 1.0 - 1.0 * I;  // 複素数 1 - i

    printf("z1 : %.1f + %.1fi\n", creal(z1), cimag(z1));
    printf("z2 : %.1f + %.1fi\n", creal(z2), cimag(z2));

    // 加算
    double _Complex z3 = z1 + z2;
    printf("z3 : %.1f + %.1fi\n", creal(z3), cimag(z3));

    // z3を原点を中心に 90°反時計回りに回転
    double _Complex z4 = z3 * I;
    printf("z4 : %.1f + %.1fi\n", creal(z4), cimag(z4));

    return 0;
}
