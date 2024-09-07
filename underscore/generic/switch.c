#include <stdio.h>

//#define type_to_string(x) _Generic((x), \
//    int:     "int",                     \
//    double:  "double",                  \
//    char *:  "string",                  \
//    default: "unknown")

char* type_to_string(type x)
{
    char* ret;

    switch (x)
    {
        case int:
            ret = "int";
            break;
        case double:
            ret = "double";
            break;
        case string:
            ret = "string";
            break;
        default:
            ret = "unknown";
            break;
    }
    return ret;
}

int main()
{
    int    a = 1;
    double b = 3.14;
    char  *c = "generic";
    float  d = 5.69;

    printf("type of a is \"%s\"\n", type_to_string(0));
    printf("type of b is \"%s\"\n", type_to_string(1));
    printf("type of c is \"%s\"\n", type_to_string(2));
    printf("type of d is \"%s\"\n", type_to_string(3));

    return 0;
}
