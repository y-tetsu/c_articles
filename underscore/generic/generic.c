#include <stdio.h>

#define type_to_string(x) _Generic((x), \
    int:     "int",                     \
    double:  "double",                  \
    char *:  "string",                  \
    default: "unknown")

int main()
{
    int    a = 1;
    double b = 3.14;
    char  *c = "generic";
    float  d = 5.69;

    printf("type of a is \"%s\"\n", type_to_string(a));
    printf("type of b is \"%s\"\n", type_to_string(b));
    printf("type of c is \"%s\"\n", type_to_string(c));
    printf("type of d is \"%s\"\n", type_to_string(d));

    return 0;
}
