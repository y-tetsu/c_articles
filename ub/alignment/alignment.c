#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *mblock = malloc(sizeof(int) + 1);  // メモリ確保(通常4バイト境界に配置)
    int *ptr = (int*)(mblock + 1);           // 1バイト分のオフセットを入れる

    // アライメント違反の可能性あり
    *ptr = 569;
    printf("%d\n", *ptr);

    return 0;
}
