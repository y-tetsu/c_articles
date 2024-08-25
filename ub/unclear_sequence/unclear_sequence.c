#include <stdio.h>

int main()
{
    int i = 284;

    i = i++ + i--;  // 未定義動作
    printf("%d\n", i);

    i = (i++, i--, i);  // 定義済み動作
    printf("%d\n", i);

    printf("%d, %d, %d, %d\n", i--, i--, i--, i--);  // 未定義動作

    return 0;
}
