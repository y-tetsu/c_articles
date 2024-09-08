#include <stdio.h>

int main()
{
    char a;
    char b;
    char c;
    _Alignas(int) short d;
    short e;
    int f;
    _Alignas(8) int g;
    _Alignas(16) int h;

    printf("a : alignment = %2zu, address = 0x%p\n", _Alignof(a), (void *)&a);
    printf("b : alignment = %2zu, address = 0x%p\n", _Alignof(b), (void *)&b);
    printf("c : alignment = %2zu, address = 0x%p\n", _Alignof(c), (void *)&c);
    printf("d : alignment = %2zu, address = 0x%p\n", _Alignof(d), (void *)&d);
    printf("e : alignment = %2zu, address = 0x%p\n", _Alignof(e), (void *)&e);
    printf("f : alignment = %2zu, address = 0x%p\n", _Alignof(f), (void *)&f);
    printf("g : alignment = %2zu, address = 0x%p\n", _Alignof(g), (void *)&g);
    printf("h : alignment = %2zu, address = 0x%p\n", _Alignof(h), (void *)&h);

    return 0;
}
