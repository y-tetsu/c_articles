#include <stdio.h>

int main()
{
    char        a;
    short       b;
    int         c;
    long        d;
    long long   e;
    float       f;
    double      g;
    long double h;

    printf("char        : %2zu byte alignment\n", _Alignof(a));
    printf("short       : %2zu byte alignment\n", _Alignof(b));
    printf("int         : %2zu byte alignment\n", _Alignof(c));
    printf("long        : %2zu byte alignment\n", _Alignof(d));
    printf("long long   : %2zu byte alignment\n", _Alignof(e));
    printf("float       : %2zu byte alignment\n", _Alignof(f));
    printf("double      : %2zu byte alignment\n", _Alignof(g));
    printf("long double : %2zu byte alignment\n", _Alignof(h));

    return 0;
}
