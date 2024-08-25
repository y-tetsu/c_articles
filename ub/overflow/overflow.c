#include <stdio.h>
#include <limits.h>

int main()
{
    int x;

    x= INT_MAX;  // int 型の最大値を格納
    printf("before    : %11d\n", x);

    x += 1;  // 最大値側のオーバーフローが発生
    printf("overflow1 : %11d\n", x);

    x -= 1;  // 最小値側のオーバーフローが発生
    printf("overflow2 : %11d\n", x);

    return 0;
}
