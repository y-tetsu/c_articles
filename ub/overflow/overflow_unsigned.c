#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int x;

    x = UINT_MAX;  // unsigned int 型の最大値を格納
    printf("before    : %11u\n", x);

    x += 1;  // 最大値側のオーバーフローが発生
    printf("overflow1 : %11u\n", x);

    x -= 1;  // 最小値側のオーバーフローが発生
    printf("overflow2 : %11u\n", x);

    return 0;
}
